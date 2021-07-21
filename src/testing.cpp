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
  std::string hash5 = "ADT";
  std::string key5 = "Sid";
  std::string value5 = "Ukr";
  test1.insert(0,key, value);
  test1.insert(3,hash5, key5, value5);
 //std::string key2 = "Jimish";
 // std::string value2 = "Gujarat";
 // test1.insert(0,key2,value2);
  std::string key1 ="unavailable";
  test1.find(1,key);
  test1.find(4,hash5,key5); 
 // test1.remove(5,hash5,key5); 
  //std::cout<<"Worked"<<std::endl;
  //test1.remove(2,key);
}
