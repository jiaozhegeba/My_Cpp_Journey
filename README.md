# Modern C++ Programming

This repository contains examples and exercises for modern C++ programming, tracking my progress and learning journey.

## Project Structure

```
.
├── CMakeLists.txt
├── docs/
│   └── README.md
└── src/
    ├── day01/
    │   └── main.cpp
    ├── day02/
    │   └── main.cpp
    ├── day03/
    │   └── main.cpp
    └── day04/
        └── main.cpp
```

Each `src/dayXX` folder is an independent lesson or exercise containing a `main.cpp`. Notes and explanations can be added under `docs/`.

## Build and Run

This project uses CMake to compile each lesson into its own executable. To build all examples:

```bash
cmake -S . -B build
cmake --build build
```

Executables will appear in the `build/` directory with names matching the lesson folder (e.g., `src/day01/main.cpp` -> `day01`). Run them directly:

```bash
./build/day01
```

When you add a new lesson (e.g., `src/day05/main.cpp`), rerun the commands above and CMake will automatically include it.

## Future Directions

- Add new lesson folders under `src/` to explore data structures, algorithms, and language features.
- Split code into headers (`.hpp`) and sources (`.cpp`) as programs grow.
- Introduce unit tests using a framework like GoogleTest to verify behaviour.
- Experiment with modern C++ topics: templates, smart pointers, ranges, coroutines, and concurrency.
- Record detailed study notes or summaries in the `docs/` directory.

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
