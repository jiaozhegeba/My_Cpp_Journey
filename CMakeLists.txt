cmake_minimum_required(VERSION 3.16)

# This CMake configuration builds every C++ source file in this directory
# as an independent executable. Adding a new `*.cpp` file and rerunning the
# build will automatically produce a new program.
project(My_Cpp_Journey)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Gather all .cpp files. `CONFIGURE_DEPENDS` tells CMake to rescan the
# directory when sources change so new files are picked up.
file(GLOB SOURCES CONFIGURE_DEPENDS "*.cpp")

# Create an executable for each source file. The target name matches the file
# name without extension (e.g., `day01.cpp` becomes the `day01` executable).
foreach(src ${SOURCES})
    get_filename_component(target ${src} NAME_WE)
    add_executable(${target} ${src})
endforeach()
