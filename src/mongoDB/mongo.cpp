#include "mongo.h"
#include "enums.h"
#include <cstdarg>
#include <utility>

namespace NoSQLite
{
  using bsoncxx::builder::basic::kvp;
  using bsoncxx::builder::basic::make_document;
  using bsoncxx::builder::basic::make_array;
  using bsoncxx::builder::stream::document;
  using bsoncxx::builder::stream::finalize;

  void Mongo::connect()
  {
    mongocxx::instance instance{};
    mongocxx::client conn{mongocxx::uri{DEF_URI + ":" + std::to_string(DEF_PORT)}};
  }

  int Mongo::insert(int operationType, ...)
  {
    std::cout << "Mongo::Insert operationType: " << operationType << std::endl;
    switch((MongoOpType)operationType)
    {
      case MongoOpType::INSERT_ONE:
        {
          std::string key,value,collection;
          std::va_list args;

          va_start(args,operationType);
          key = va_arg(args,std::string);
          value = va_arg(args,std::string);
          collection = va_arg(args,std::string);
          va_end(args);

          mongocxx::client conn{mongocxx::uri{DEF_URI + ":" + std::to_string(DEF_PORT)}};	
          auto db = conn[Mongo::DB_NAME];
          std::cout << "Creating Doc: " << std::endl;

          bsoncxx::document::value coll_doc = make_document(kvp(key,value));
          auto res = db[collection].insert_one(std::move(coll_doc));

          std::cout << "Created Doc: " << std::endl;

          // std::cout << "Response: " << res << std::endl;	   
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
          std::string key,value,collection;
          std::va_list args;

          va_start(args,operationType);
          key = va_arg(args,std::string);
          value = va_arg(args,std::string);
          collection = va_arg(args,std::string);
          va_end(args);

          mongocxx::client conn{mongocxx::uri{DEF_URI + ":" + std::to_string(DEF_PORT)}};
          auto db = conn[Mongo::DB_NAME];
          db[collection].delete_one(make_document(kvp(key,value)));
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
          std::string key,value,collection;
          std::va_list args;

          va_start(args,operationType);
          key = va_arg(args,std::string);
          value = va_arg(args,std::string);
          collection = va_arg(args,std::string);
          va_end(args);

          mongocxx::client conn{mongocxx::uri{DEF_URI + ":" + std::to_string(DEF_PORT)}};
          auto db = conn[Mongo::DB_NAME];
          auto cursor = db[collection].find(make_document(kvp(key,value)));
          for(auto&& doc : cursor){
            std::cout << bsoncxx::to_json(doc) << std::endl;
          }

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
