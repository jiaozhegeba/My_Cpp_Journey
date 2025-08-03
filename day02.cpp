/*
    * Memory: stack and heap
    * Stack: automatic storage, limited size, faster access
    * Heap: dynamic storage, larger size, slower access

*/

#include <iostream>
#include <string>

int main()
{
    // Pointer 
    int* my_ptr = nullptr; // Initialize pointer to null
    int my_var = 42; // Create an integer variable
    my_ptr = &my_var; // Assign the address of my_var to my_ptr

    // Accessing the value using the pointer
    std::cout << "Value of my_var: " << *my_ptr << std::endl;
    std::cout << "Address of my_var: " << my_ptr << std::endl;
    std::cout << "Address of my_var using &: " << &my_var << std::endl;

    // Modifying the value using the pointer
    *my_ptr = 100;
    std::cout << "New value of my_var: " << my_var << std::endl;
    std::cout << "Address of NEW VALUE of my_var: " << my_ptr << std::endl;
    std::cout << "Address of NEW VALUE of my_var using &: " << &my_var << std::endl;



    /*
    * * is used to dereference the pointer, accessing the value it points to.
    * & is used to get the address of a variable.
    */

    return 0; 
}