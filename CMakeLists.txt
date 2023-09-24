cmake_minimum_required(VERSION 3.16)
project(app CXX)
include(CheckIncludeFileCXX)
set(CMAKE_CXX_STANDARD 20)

# aux_source_directory(models MODEL_SRC)
# aux_source_directory(utils UTILS_SRC)
# aux_source_directory(services SERVICES_SRC)
# aux_source_directory(tests TESTS_SRC)
# aux_source_directory(math MATH_SRC)
# aux_source_directory(libs LIBS_SRC)

add_executable(${PROJECT_NAME} main.cc)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

file(GLOB_RECURSE SRC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/**/*.cc")

target_sources(
    ${PROJECT_NAME} 
    PRIVATE
    ${SRC_FILES}
)
