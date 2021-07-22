#include "redis.h"
#include "enums.h"
#include <cstdarg>
#include <utility>
#include <string.h>

namespace NoSQLite
{
  redisContext * Redis::connect(const std::string& host,int port)
  {
    c = redisConnect(host.c_str(), port);
    if (c == NULL || c->err) {
      if (c) {
        std::cout << "Connection error: " << c->errstr << std::endl;
        redisFree(c); 
      } else {
        std::cout << "Connection error: can't allocate redis context" << std::endl;
      }
      exit(1);
    }

    return c;
  }

  int Redis::insert(int operationType, ...)
  {
    std::cout << "Redis::Insert operationType: " << operationType << std::endl;
    switch((RedisOpType)operationType)
    {
      case RedisOpType::SET:
        {
          std::string key, value;
          std::va_list args;

          va_start(args,operationType);
          key = va_arg(args,std::string);
          value = va_arg(args,std::string);
          va_end(args);

          reply = (redisReply*)redisCommand(c,"SET %s %s",key.c_str(),value.c_str());
          std::cout << "SET: " << reply->str << std::endl;
          freeReplyObject(reply);
        }
        break;

      case RedisOpType::HSET:
        {
	 std::string hash,key,value;
         std::va_list args;

	 va_start(args,operationType);
	 hash = va_arg(args,std::string);
         key = va_arg(args,std::string);
         value = va_arg(args,std::string);
         va_end(args);

         std::cout<<hash<<"\t"<<key<<"\t"<<value<<std::endl;
         reply = (redisReply*)redisCommand(c,"HSET %s %s %s",hash.c_str(),key.c_str(),value.c_str());
         printf ("\n Successful \n");
         freeReplyObject(reply);
        }
        break;

      default:
        {
          return (int)RedisError::COMMAND_NOT_SUPPORTED;
        }
    }

    return (int)RedisError::SUCCESS;
  };

  int Redis::remove(int operationType, ...)
  {
    std::cout << "Redis::Remove operationType: " << operationType << std::endl;
    switch((RedisOpType)operationType)
    {
      case RedisOpType::DEL:
        {
          std::va_list args;
          va_start(args,operationType);
          std::string key = va_arg(args,std::string);
          va_end(args);

          reply= (redisReply*)redisCommand(c,"DEL %s" , key.c_str());
          std::cout << "DEL : " << key << std::endl;
          freeReplyObject(reply);

        }
        break;

      case RedisOpType::HDEL:
        {
          std::va_list args;
          va_start(args,operationType);
          std::string hash = va_arg(args,std::string);
          std::string key = va_arg(args,std::string);
          va_end(args);

          reply= (redisReply*)redisCommand(c,"HDEL %s %s",hash.c_str(),key.c_str());
          std::cout << "HDEL:" << hash << key << std::endl;
          freeReplyObject(reply);
        }
        break;

      default:
        {
          return (int)RedisError::COMMAND_NOT_SUPPORTED;
        }
    }

    return (int)RedisError::SUCCESS;
  }

  int Redis::find(int operationType, ...)
  {
    std::cout << "Redis::find operationType: " << operationType << std::endl;
    switch((RedisOpType)operationType)
    {
      case RedisOpType::GET:
        {
          std::va_list args;
          va_start(args,operationType);
          std::string key = va_arg(args,std::string);

          reply = (redisReply*)redisCommand(c,"GET %s",key.c_str());

          std::cout << "GET: " << reply->str << std::endl;
          freeReplyObject(reply);
          va_end(args);
        }
        break;

      case RedisOpType::HGET:
        {
          std::va_list args;
          va_start(args,operationType);
          std::string hash = va_arg(args,std::string);
          std::string key = va_arg(args,std::string);

          reply = (redisReply*)redisCommand(c,"HGET %s %s",hash.c_str(),key.c_str());

          std::cout << "HGET:" << reply->str << std::endl;
          freeReplyObject(reply);
          va_end(args);  
        }
        break;

      case RedisOpType::KEYS:
        {
           unsigned int j=0;
           redisReply *rep;
           std::cout<<"fetch keys"<<std::endl;
           std::va_list args;
           va_start(args,operationType);
           std::string key = va_arg(args,std::string);
           std::cout<<"key passed"<<key.c_str()<<std::endl;
           reply = (redisReply*)redisCommand(c,"keys %s",key.c_str());
           std::cout<<"Keys are"<<std::endl;
           for (int i=0;i<reply->elements;i++)
          {
              std::cout<<reply->element[i]->str<<std::endl;
          }
           freeReplyObject(reply);
           va_end(args);          
        }

        break;

      default:
        {
          return (int)RedisError::COMMAND_NOT_SUPPORTED;
        }
    }

    return (int)RedisError::SUCCESS;
  }
}

