#ifndef NOSQLITE_NOSQL_H
#define NOSQLITE_NOSQL_H

#include <iostream>
#include <utility>

namespace NoSQLite
{
  class NoSQL 
  {
    public:

      virtual int insert(int operationType, ...) = 0;
      virtual int remove(int operationType, ...) = 0;
      virtual int find(int operationType, ...) = 0;
  };
}
#endif
