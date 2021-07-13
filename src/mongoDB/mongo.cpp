#include "mongo.h"
#include "enums.h"

namespace NoSQLite
{
  int Mongo::insert(int operationType, ...)
  {
    std::cout << "Mongo::Insert operationType: " << operationType << std::endl;
    switch((MongoOpType)operationType)
    {
      case MongoOpType::INSERT_ONE:
        {
        }
        break;

      default:
        {
          return (int)MongoError::COMMAND_NOT_SUPPORTED;
        }
    }

    return (int)MongoError::SUCCESS;
  };

  int Mongo::remove(int operationType, ...)
  {
    std::cout << "Mongo::Remove operationType: " << operationType << std::endl;
    switch((MongoOpType)operationType)
    {
      case MongoOpType::DELETE_ONE:
        {
        }
        break;

      default:
        {
          return (int)MongoError::COMMAND_NOT_SUPPORTED;
        }
    }

    return (int)MongoError::SUCCESS;
  }
  
  int Mongo::find(int operationType, ...)
  {
    std::cout << "Mongo::find operationType: " << operationType << std::endl;
    switch((MongoOpType)operationType)
    {
      case MongoOpType::FIND_ONE:
        {
        }
        break;

      default:
        {
          return (int)MongoError::COMMAND_NOT_SUPPORTED;
        }
    }

    return (int)MongoError::SUCCESS;
  }
}
