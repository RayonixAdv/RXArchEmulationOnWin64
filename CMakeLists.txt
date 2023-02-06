cmake_minimum_required(VERSION 3.2)
project(RXArxhEmulationOnWin64)

file(GLOB_RECURSE RXArxhEmulationOnWin64_SOURCES "Source/*.cxx" "Device/*.cxx")
file(GLOB_RECURSE RXArxhEmulationOnWin64_HEADERS "Source/*.hxx" "Device/*.hxx")

include_directory(Include)
add_executable(emulator ${RXArxhEmulationOnWin64_SOURCES} ${RXArxhEmulationOnWin64_HEADERS})
