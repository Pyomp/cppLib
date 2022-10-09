cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 20)

#set the project name
project(cppPlayground)

file(GLOB_RECURSE srcFiles CONFIGURE_DEPENDS "*.h" "*.cc")

#add the executable
add_executable(a ${srcFiles})
set_target_properties(a PROPERTIES LINKER_LANGUAGE CXX)