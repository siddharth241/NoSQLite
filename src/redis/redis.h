#ifndef NOSQLITE_REDIS_H
#define NOSQLITE_REDIS_H

#include <iostream> 
#include <cstdlib>
#include <string>
#include <hiredis.h>

#include "../noSQL.h"

namespace NoSQLite
{
  /**
   * @description Derived from NoSQL base, this class shall provide connection 
   *              and interface to Redis database via Hiredis API.
   */
  class Redis : public NoSQL 
  {
    public:

      /**
       * @brief method to handle all insertion related operations offered by Redis.
       *
       * @param operationType : operation to execute from the supported operations
       *
       * @return error code
       */
      virtual int insert(int operationType, ...) override;

      /**
       * @brief method to handle all deletion related operations offered by Redis.
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

      redisContext * connect (const std::string& hostname,int port);

    private:
      redisContext *c;
      redisReply *reply;
  };
}
#endif
