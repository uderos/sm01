cmake_minimum_required (VERSION 2.8.11)

set(SRC_FILES common.h Event.cpp Event.h OutMgr.cpp OutMgr.h State.cpp State.h StateMachine.cpp StateMachine.h)

add_library(udr_sm_lib ${SRC_FILES})

