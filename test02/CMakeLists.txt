cmake_minimum_required (VERSION 2.8.11)

set(SRC_FILES test02.cpp)

add_executable(test02 ${SRC_FILES})
TARGET_LINK_LIBRARIES(test02 udr_sm_lib udr_sm_filter_lib)

