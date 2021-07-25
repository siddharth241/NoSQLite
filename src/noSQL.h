/**
 * @author Srishti Jain
 *
 * @date 25-07-2021
 */

#ifndef NOSQLITE_NOSQL_H
#define NOSQLITE_NOSQL_H

#include <iostream>
#include <utility>

namespace NoSQLite
{
  /**
   * @description This class defines the standard for NoSQL databases.
   */
  class NoSQL 
  {
    public:

      /**
       * @brief A pure virtual method to act as standard for all insert
       *        operations.
       *
       * @param operationType : a value from enum declared in DB specific
       *                        derived versions
       *        ... : variadic list because arguments might differ based on the
       *              deriving database API.
       *
       * @return int - errorcode if any. error code for a specific DB should be
       *               present in enums.
       */
      virtual int insert(int operationType, ...) = 0;
      
      /**
       * @brief A pure virtual method to act as standard for all remove
       *        operations.
       *
       * @param operationType : a value from enum declared in DB specific
       *                        derived versions
       *        ... : variadic list because arguments might differ based on the
       *              deriving database API.
       *
       * @return int - errorcode if any. error code for a specific DB should be
       *               present in enums.
       */
      virtual int remove(int operationType, ...) = 0;

      /**
       * @brief A pure virtual method to act as standard for all find/get
       *        operations.
       *
       * @param operationType : a value from enum declared in DB specific
       *                        derived versions
       *        ... : variadic list because arguments might differ based on the
       *              deriving database API.
       *
       * @return int - errorcode if any. error code for a specific DB should be
       *               present in enums.
       */
      virtual int find(int operationType, ...) = 0;
  };
}
#endif
