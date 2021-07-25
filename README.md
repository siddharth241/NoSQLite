# NoSQLite
A database access library that provides the illusion of embedding
NoSQL in regular C++ code.

Unlike SQL, there is no specific defined format for NoSQL. 

This library provides users a common format, unified interface, 
and a single point of access to multiple NoSQL databases. 

# Model

![image](https://user-images.githubusercontent.com/16489673/126892021-1f134958-87d6-437d-be50-cb256a6c6f72.png)


# Dependencies

Currently, this library supports MongoDB and redis using mongo-cxx-driver and
hiredis API respectively.

Mongo-CXX-Driver 
Version : 3.6.5 
Git Tag : r3.6.5

Hiredis 
Version : 0.14.0
Git Tag : v0.14.0

# Build

To build the code, following are the constraints:
- CMake version higher than 3.13 is required.
- C++17 is required
- Shared libraries for Mongo-CXX-Driver and Hiredis

To compile, run following commands in build folder ( pwd: src/build/ )

    cmake ..
    make
