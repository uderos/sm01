cmake_minimum_required (VERSION 2.8.11)

#include_directories(${CMAKE_SOURCE_DIR})

set(SRC_FILES FilterSMEvents.h FilterSMStates.h FilterSMStates.cpp FilterSM.h FilterSM.cpp)

add_library(udr_sm_filter_lib ${SRC_FILES})

