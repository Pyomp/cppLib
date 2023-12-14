cmake_minimum_required(VERSION 3.16)
project(cppLib CXX)
include(CheckIncludeFileCXX)
set(CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME} main.cc)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

file(GLOB_RECURSE SRC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/**/*.cc")

target_sources(
    ${PROJECT_NAME} 
    PRIVATE
    ${SRC_FILES}
)
