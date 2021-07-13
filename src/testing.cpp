#include <iostream>
#include "mongoDB/mongo.h"
#include "redis/redis.h"

int main()
{
  NoSQLite::Mongo test;
  test.insert(0,"abc","foo","bbo");
  NoSQLite::Redis test1;
  test1.insert(0,"abc","foo","bbo");
}
