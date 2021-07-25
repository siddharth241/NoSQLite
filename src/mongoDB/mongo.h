#ifndef NOSQLITE_MONGO_H
#define NOSQLITE_MONGO_H

#include "../noSQL.h"
//#include "enums.h"
#include <cstdlib>
#include <map>

#include <chrono>
#include <bsoncxx/builder/basic/array.hpp>
#include <bsoncxx/builder/basic/document.hpp>
#include <bsoncxx/builder/basic/kvp.hpp>
#include <bsoncxx/types.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/uri.hpp>
#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/json.hpp>

#include <memory>
#include <bsoncxx/stdx/make_unique.hpp>
#include <bsoncxx/stdx/optional.hpp>
#include <bsoncxx/stdx/string_view.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/logger.hpp>
#include <mongocxx/pool.hpp>
#include <mongocxx/uri.hpp>


namespace NoSQLite
{
  class Mongo : public NoSQL 
  {
    public:
      using NoSQL::insert;  // Pull in the Split symbol from the parent class

      const std::string DB_NAME = "APIDB";
      const int DEF_PORT = 27017;
      const std::string DEF_URI = "mongodb://localhost";


      virtual int insert(int operationType, ...) override;

      virtual int remove(int operationType, ...) override;

      virtual int find(int operationType, ...) override;

      void connect();


  };
}
#endif
