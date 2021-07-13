#ifndef NOSQLITE_REDIS_H
#define NOSQLITE_REDIS_H

#include "../noSQL.h"

namespace NoSQLite
{
  class Redis : public NoSQL 
  {
    public:
      using NoSQL::insert;  // Pull in the Split symbol from the parent class

      virtual int insert(int operationType, ...) override;
      
      virtual int remove(int operationType, ...) override;

      virtual int find(int operationType, ...) override;
  };
}
#endif
