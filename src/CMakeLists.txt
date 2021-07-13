cmake_minimum_required(VERSION 3.13)
project(nosqlite)
set(CMAKE_CXX_STANDARD 17)

add_library(nosqlite STATIC
	mongoDB/mongo.cpp
	redis/redis.cpp
	)
