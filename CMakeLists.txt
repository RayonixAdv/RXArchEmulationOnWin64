cmake_minimum_required(VERSION 3.2)
project(RXArxhEmulationOnWin64)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE RXArxhEmulationOnWin64_SOURCES "Source/*.cxx" "Device/*.cxx")
file(GLOB_RECURSE RXArxhEmulationOnWin64_HEADERS "Source/*.hxx" "Device/*.hxx")

include_directories(Include)
add_executable(emulator ${RXArxhEmulationOnWin64_SOURCES} ${RXArxhEmulationOnWin64_HEADERS})

# Add threads
find_package(Threads REQUIRED)
target_link_libraries(emulator Threads::Threads)