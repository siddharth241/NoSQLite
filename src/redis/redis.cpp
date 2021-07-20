#include "redis.h"
#include "enums.h"
#include <cstdarg>
#include <utility>

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
        }
        break;

      case RedisOpType::KEYS:
        {
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

