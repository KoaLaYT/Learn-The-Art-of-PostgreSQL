cmake_minimum_required(VERSION 3.18)

project(psql)

find_package(fmt CONFIG REQUIRED)

add_subdirectory(lib)
add_subdirectory(chinook)
add_subdirectory(f1db)