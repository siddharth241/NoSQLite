#include "redis.h"
#include "enums.h"

namespace NoSQLite
{
  int Redis::insert(int operationType, ...)
  {
    std::cout << "Redis::Insert operationType: " << operationType << std::endl;
    switch((RedisOpType)operationType)
    {
      case RedisOpType::SET:
        {
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

