cmake_minimum_required (VERSION 2.8.11)

set(SRC_FILES Event.cpp State.cpp StateMachine.cpp)

add_library(udr_sm_lib ${SRC_FILES})

