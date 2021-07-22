cmake_minimum_required(VERSION 3.13)
project(nosqlite)
set(CMAKE_CXX_STANDARD 17)


add_library(nosqlite STATIC
	mongoDB/mongo.cpp
	redis/redis.cpp
	)

target_include_directories(nosqlite PRIVATE
  /usr/local/include/bsoncxx/v_noabi
  /usr/local/include/mongocxx/v_noabi
  /usr/local/include/hiredis
  )

target_link_libraries(nosqlite
	/usr/local/lib/libhiredis.so.0.14
	)

add_executable(example
  testing.cpp
  )

target_link_libraries(example
  nosqlite
  /usr/local/lib/libmongocxx.so.3.6.5
  /usr/local/lib/libbsoncxx.so.3.6.5
  )

target_include_directories(example PRIVATE
  /usr/local/include/bsoncxx/v_noabi/
  /usr/local/include/mongocxx/v_noabi/
  /usr/local/include/hiredis
  )
