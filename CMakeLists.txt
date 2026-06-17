#Setup
cmake_minimum_required(VERSION 4.3)
project(Pong CXX)

#Rules
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#Source files
file(GLOB_RECURSE SOURCES "src/*.cpp")

#executable
add_executable(${PROJECT_NAME} ${SOURCES})

#Link headers
target_include_directories(${PROJECT_NAME} PRIVATE include)