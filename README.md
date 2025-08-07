# Modern C++ Programming

This repository contains examples and exercises for modern C++ programming, tracking my progress and learning journey.

## Table of Contents
- [Modern C++ Programming](#modern-c-programming)
  - [Table of Contents](#table-of-contents)
  - [Build and Run](#build-and-run)
  - [Basics of C++](#basics-of-c)

## Build and Run

This project uses CMake to compile each `*.cpp` file into its own executable. To build all examples:

```bash
cmake -S . -B build
cmake --build build
```

Executables will appear in the `build/` directory with names matching the source file (e.g., `day01.cpp` -> `day01`). Run them directly:

```bash
./build/day01
```

When you add a new source file, rerun the commands above and CMake will automatically include it.

## Basics of C++

This section covers the fundamental concepts of C++ programming.

1. Loop based on range:

    C++17 introduced range-based for loops, which allow you to iterate over elements in a container without needing to manage iterators or indices explicitly.

```cpp

std::vector<int> numbers = {1, 2, 3, 4, 5};

for (const auto& num : numbers) // Range-based for loop, : is used to iterate over the elements
{
    std::cout << num << std::endl;
}

```

2. Initializer List:

   C++11 introduced initializer lists, which allow you to initialize containers and other data structures more conveniently.

```cpp
int makeSum_vector( std::initializer_list<int> list)
{
    int sum = 0;
    for (const auto& num : list) // auto keyword must be used to deduce the type of elements in the initializer list
    {
        sum += num;
    }
    return sum;
}

int main()
{
    std::cout << makeSum_vector({1, 2, 3, 4, 5}) << std::endl; // Outputs: 15
    return 0;
}
```
