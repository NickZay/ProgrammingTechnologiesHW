cmake_minimum_required(VERSION 3.0)
project(All)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

include_directories(${PROJECT_SOURCE_DIR})
add_custom_command(
	OUTPUT YYY
	COMMAND python3 ${PROJECT_SOURCE_DIR}/A/preparing.py ${PROJECT_SOURCE_DIR}/A/index.h
	DEPENDS ${PROJECT_SOURCE_DIR}/A/preparing.py
	COMMENT "GENERATING"
)
add_custom_target(XXX DEPENDS YYY COMMENT "Checking")

add_executable(C C/main.cpp)
add_dependencies(C XXX)

add_subdirectory(B)
target_link_libraries(C Blib)
