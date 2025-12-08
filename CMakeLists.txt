
cmake_minimum_required(VERSION 3.10)
project(MyProgram VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set global object file output directory
set(CMAKE_OBJECT_PATH_MAX 4096)  # Avoid path length issues
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/obj)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/obj)

# Add include directory
#include_directories(include)

#add_subdirectory(day1)
#add_subdirectory(day2)
#add_subdirectory(day3)
#add_subdirectory(day4)
add_subdirectory(day5)
