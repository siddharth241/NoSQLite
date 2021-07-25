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
  /**
   * @description Derived from NoSQL base, this class shall provide connection 
   *              and interface to MongoDB database via Mongo-CXX-Driver API.
   */
  class Mongo : public NoSQL 
  {
    public:
      using NoSQL::insert;  // Pull in the Split symbol from the parent class

      const std::string DB_NAME = "APIDB";
      const int DEF_PORT = 27017;
      const std::string DEF_URI = "mongodb://localhost";


      /**
       * @brief method to handle all insertion related operations offered by MongoDB.
       *
       * @param operationType : operation to execute from the supported operations
       *
       * @return error code
       */
      virtual int insert(int operationType, ...) override;

      /**
       * @brief method to handle all deletion related operations offered by MongoDB.
       *
       * @param operationType : operation to execute from the supported operations
       *
       * @return error code
       */
      virtual int remove(int operationType, ...) override;

      /**
       * @brief method to handle all find/get related operations offered by Redis.
       *
       * @param operationType : operation to execute from the supported operations
       *
       * @return error code
       */
      virtual int find(int operationType, ...) override;

      void connect();


  };
}
#endif
