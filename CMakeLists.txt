cmake_minimum_required (VERSION 2.8.11)

#message("Supported features = ${CMAKE_CXX_COMPILE_FEATURES}")
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -std=c++11")

#set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)

project (sm01)

add_subdirectory (sm_lib)
add_subdirectory (sm_filter)

