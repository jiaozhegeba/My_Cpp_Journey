#include <iostream>
#include <array>

#include <initializer_list>

// Initializer list
int makeSum(std::initializer_list<int> nums) {
    int sum = 0;
    for (auto n : nums) {
        sum += n;
    }
    return sum;
}

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

    // Example: Function with Initializer List
    int sum = makeSum({1, 2, 3, 4, 5});
    std::cout << "Sum: " << sum << std::endl;

    return 0;
}