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

#raylib
find_package(raylib REQUIRED)

# If fetching raylib from source is preferred, uncomment the following lines and comment out the find_package line above.
# include(FetchContent)
# FetchContent_Declare(
#     raylib
#     GIT_REPOSITORY https://github.com/raysan5/raylib.git
#     GIT_TAG        master 
#     GIT_SHALLOW    TRUE
# )
# FetchContent_MakeAvailable(raylib)

#Link headers
target_include_directories(${PROJECT_NAME} PRIVATE include)
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)

