#ifndef NOSQLITE_MONGO_H
#define NOSQLITE_MONGO_H

#include "../noSQL.h"

namespace NoSQLite
{
  class Mongo : public NoSQL 
  {
    public:
      using NoSQL::insert;  // Pull in the Split symbol from the parent class

      virtual int insert(int operationType, ...) override;
      
      virtual int remove(int operationType, ...) override;

      virtual int find(int operationType, ...) override;
  };
}
#endif
