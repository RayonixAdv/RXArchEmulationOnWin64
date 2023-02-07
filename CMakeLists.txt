cmake_minimum_required(VERSION 3.2)
project(RXEmulator)

set(CMAKE_CXX_STANDARD 23)

file(GLOB_RECURSE RXEmulator_SRC "Source/*.cxx" "Source/*.hxx")
add_executable(RXEmulator ${RXEmulator_SRC})

# Enable threads for linux
if(UNIX AND NOT APPLE)
    target_link_libraries(RXEmulator pthread)
endif()