cmake_minimum_required(VERSION 3.16)
project(app CXX)
include(CheckIncludeFileCXX)
set(CMAKE_CXX_STANDARD 20)

aux_source_directory(models MODEL_SRC)
aux_source_directory(utils UTILS_SRC)
aux_source_directory(services SERVICES_SRC)
aux_source_directory(tests TESTS_SRC)
aux_source_directory(math MATH_SRC)
aux_source_directory(libs LIBS_SRC)

add_executable(${PROJECT_NAME} main.cc)

target_include_directories(
    ${PROJECT_NAME}
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/models
    ${CMAKE_CURRENT_SOURCE_DIR}/services
    ${CMAKE_CURRENT_SOURCE_DIR}/utils
    ${CMAKE_CURRENT_SOURCE_DIR}/tests
    ${CMAKE_CURRENT_SOURCE_DIR}/math
    ${CMAKE_CURRENT_SOURCE_DIR}/libs
)

target_sources(${PROJECT_NAME}
               PRIVATE
               ${MODEL_SRC}
               ${UTILS_SRC}
               ${SERVICES_SRC}        
               ${TESTS_SRC}        
               ${MATH_SRC}        
               ${LIBS_SRC}
)
