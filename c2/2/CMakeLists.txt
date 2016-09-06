cmake_minimum_required(VERSION 2.6)
 
include_directories(${GMOCK_INCLUDE_DIRS})
 
add_executable(runTests SoundexTest.cpp)

target_link_libraries(runTests gmock pthread)

