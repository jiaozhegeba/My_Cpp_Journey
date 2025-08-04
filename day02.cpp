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
    int* my_ptr = nullptr; // Initialize pointer to nullptr when don't initialize it immediately
    int my_var = 42; 
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

    int* dynamic_ptr = new int; // Allocate memory on the heap
    *dynamic_ptr = 200;

    std::cout << "Value of dynamic_ptr: " << *dynamic_ptr << std::endl;
    std::cout << "Address of dynamic_ptr: " << dynamic_ptr << std::endl;

    // The pointers will be not used after this point, but we should free the memory allocated on the heap
    delete my_ptr;
    delete dynamic_ptr;
    // It's important to set pointers to nullptr after deleting to avoid dangling pointers
    my_ptr = nullptr; 
    dynamic_ptr = nullptr; 

    
    return 0;
}