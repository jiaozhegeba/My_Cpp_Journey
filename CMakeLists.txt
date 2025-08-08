cmake_minimum_required(VERSION 3.16)

# This CMake configuration builds each lesson under `src/` as an independent
# executable. Each subdirectory containing a `main.cpp` becomes a program with
# the directory name as the target. Adding a new folder with a `main.cpp` and
# rerunning the build will automatically produce a new executable.
project(My_Cpp_Journey)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Recursively gather `main.cpp` files inside the `src` tree. `CONFIGURE_DEPENDS`
# tells CMake to rescan when sources change so new files are picked up.
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*/main.cpp")

# Create an executable for each source file. The target name matches the
# containing directory (e.g., `src/day01/main.cpp` becomes the `day01`
# executable).
foreach(src ${SOURCES})
    get_filename_component(dir ${src} DIRECTORY)
    get_filename_component(target ${dir} NAME)
    add_executable(${target} ${src})
endforeach()
