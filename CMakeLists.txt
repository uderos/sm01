cmake_minimum_required (VERSION 2.8.11)

SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -std=c++14")

SET(CMAKE_BUILD_TYPE Debug)

include_directories(${CMAKE_SOURCE_DIR})
LINK_DIRECTORIES(${CMAKE_BINARY_DIR}/sm_lib ${CMAKE_BINARY_DIR}/sm_filter)

project (sm01)

add_subdirectory (sm_lib)
add_subdirectory (sm_filter)
add_subdirectory (test01)
add_subdirectory (test02)

