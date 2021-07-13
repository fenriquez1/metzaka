cmake_minimum_required(VERSION 3.18)

project(metzaka)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_COMPILER "/usr/bin/g++")
set(CMAKE_CXX_FLAGS "-Wall -pedantic")

find_package(Boost REQUIRED system)

link_directories(${metzaka_SOURCE_DIR}/src)

include_directories(${PROJECT_ROOT}/metzaka/include)

add_executable(metzaka ${metzaka_SOURCE_DIR}/src/main.cpp)

target_link_libraries(metzaka PUBLIC pthread)