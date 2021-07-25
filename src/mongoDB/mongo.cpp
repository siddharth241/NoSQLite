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
          std::string collection;                                              //Initialization
          std::map<std::string,std::string> doc_pair;
          std::va_list args;

          va_start(args,operationType);                                         // Reading variadic args
          doc_pair = *(std::map<std::string,std::string>*)va_arg(args,void*);
          collection = va_arg(args,std::string);
          va_end(args);
          
          mongocxx::client conn{mongocxx::uri{DEF_URI + ":" + std::to_string(DEF_PORT)}};	  //Connecting Mongo
          auto db = conn[Mongo::DB_NAME];

          std::cout << "Creating Doc: " << std::endl;                           //Creating doc
          auto doc = bsoncxx::builder::basic::document{};
        //auto arr = bsoncxx::builder::basic::arr{};
         
          std::map<std::string,std::string>::iterator it;
          for(it=doc_pair.begin(); it!=doc_pair.end(); ++it){
          //for(auto it : doc_pair){
         
            doc.append(kvp(it->first,it->second));                              // Appending key-value pairs to doc
          }
          
          //bsoncxx::document::value docName = make_document(doc.view());
          auto res = db[collection].insert_one(std::move(doc.view()));        //Inserting doc to collection
          std::cout << "Document Inserted Succesfully." << std::endl;	   
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
          std::string collection;               //Initialization
          std::map<std::string,std::string> doc_pair;
          std::va_list args;

          va_start(args,operationType);                   //Reading Variadic args
          doc_pair =*(std::map<std::string,std::string>*)va_arg(args,void*);
          collection = va_arg(args,std::string);
          va_end(args);

          mongocxx::client conn{mongocxx::uri{DEF_URI + ":" + std::to_string(DEF_PORT)}}; //Connecting Mongo
          auto db = conn[Mongo::DB_NAME];
         
          std::cout << "Removing Doc:" << std::endl;              //Creating doc
          auto doc = bsoncxx::builder::basic::document{};

          std::map<std::string,std::string>::iterator it;
          for(it=doc_pair.begin(); it!=doc_pair.end(); ++it){
            doc.append(kvp(it->first,it->second));                     //Appedning key-value pairs
          }
          db[collection].delete_one(std::move(doc.view()));   //Deleting document
          std::cout << "Document removed succesfully." << std::endl;
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
          std::string collection;                     //Initialization
          std::map<std::string,std::string> doc_pair;
          std::va_list args;

          va_start(args,operationType);               //Reading Varadic args
          doc_pair =*(std::map<std::string,std::string>*)va_arg(args,void*);
          collection = va_arg(args,std::string);
          va_end(args);

          mongocxx::client conn{mongocxx::uri{DEF_URI + ":" + std::to_string(DEF_PORT)}};
          auto db = conn[Mongo::DB_NAME];

          std::cout << "Finding Doc::" << std::endl;        //Creating doc object
          auto doc = bsoncxx::builder::basic::document{};
          
          std::map<std::string,std::string>::iterator it;
          for(it=doc_pair.begin(); it!=doc_pair.end();++it){
          
            doc.append(kvp(it->first,it->second));
          }
          
          auto cursor = db[collection].find(std::move(doc.view()));
          std::cout << "Documents found: \n" << std::endl;
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
