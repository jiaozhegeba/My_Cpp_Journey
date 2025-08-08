/*
* uniform initialization
*/

#include <iostream>
#include <string>

#include "day05.h"

void uniformInitialization() {
    int a{5}; // uniform initialization
    double b{3.14};
    std::string c{"Hello, World!"};

    std::cout << "a: " << a << "\n";
    std::cout << "b: " << b << "\n";
    std::cout << "c: " << c << "\n";
}