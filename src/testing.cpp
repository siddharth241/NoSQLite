#include <iostream>
#include "mongoDB/mongo.h"
#include "redis/redis.h"

int main()
{
  NoSQLite::Mongo test;
  test.insert(0,"abc","foo","bbo");
  NoSQLite::Redis test1;
  test1.connect("127.0.0.1",6379);
  std::string key = "Srishti";
  std::string value = "Ambala";
  test1.insert(0,key, value);
  //std::string key2 = "Jimish";
 // std::string value2 = "Gujarat";
 // test1.insert(0,key2,value2);
  std::string key1 ="unavailable";
  test1.find(1,key);
  //std::cout<<"Worked"<<std::endl;
  //test1.remove(2,key);
}
