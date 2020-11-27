cmake_minimum_required(VERSION 3.18)

project(psql)

find_package(libpqxx CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /usr/local/opt/libpq/lib/libpq.dylib")

add_subdirectory(lib)
add_subdirectory(chinook)