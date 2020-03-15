cmake_minimum_required(VERSION 3.0)
project(All)
add_library(Blib SHARED lib.h)
SET_TARGET_PROPERTIES(Blib PROPERTIES LINKER_LANGUAGE CXX)
