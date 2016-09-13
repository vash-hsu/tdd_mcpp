cmake_minimum_required(VERSION 2.6)
 
include_directories(${GMOCK_INCLUDE_DIRS})

# extended initializer lists only available with -std=c++11 or -std=gnu++11
#    static const size_t MaxCodeLength{4};
# enable debug, when core dump, shows line number
set(CMAKE_CXX_FLAGS "-Wall -std=c++11 -O2 -g")

add_executable(runTests SoundexTest.cpp)

target_link_libraries(runTests gmock pthread)

