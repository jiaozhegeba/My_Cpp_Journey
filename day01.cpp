#include <iostream>
#include <array>

int main() 
{
    // struct binding
    // * variable can be declared with number of variables in the struct, array, tuple, etc.
    // * the declared variables must match the number of elements in the struct, array, tuple, etc.
    // * the declared variables must use auto

    // Example: Array
    std::array<int, 3> arr = {1, 2, 3};
    auto [a, b, c] = arr; // struct binding
    std::cout << "a: " << a << ", b: " << b << ", c: " << c << std::endl;

    return 0;
}