/*
* Dynamically allocate memory for an array.
*/

#include <iostream>
#include <memory>
#include <vector>


// NULL and nullptr
void fun_cout(char* str)
{
    std::cout << "char* str" << std::endl;

}
void fun_cout(int i)
{
    std::cout << "int i" << std::endl;
}


int main()
{
    // Dynamically allocate memory for an array of integers in heap
    int size = 6;
    int* my_array = new int[size];

    // Then use it as stack-based array
    for (int i = 0; i < size; ++i) {
        my_array[i] = i * 10; // Initialize the array with some values
    }
    // Print the values in the array
    for (int i = 0; i < size; ++i) {
        std::cout << "my_array[" << i << "] = " << my_array[i] << std::endl;
    }

    // Don't forget to delete the allocated memory
    delete[] my_array;
    my_array = nullptr; // Set pointer to nullptr after deletion to avoid dangling pointer


    /*
    * When use pointers, it's important to manage memory properly.
    * new and delete must be used in pairs.
    * new[] and delete[] must be used for arrays in pairs.
    * It avoids memory leaks and dangling pointers.
    */

    // Demonstrating nullptr and NULL
    fun_cout(nullptr); 
    //fun_cout(NULL); 

    // Smart pointers
    //
    // * unique_ptr: Owns a single object, automatically deletes it when it goes out of scope.
    // * Its use just like a regular pointer, but it automatically manages memory.
    std::unique_ptr<int> uniquePtr(new int(42));
    std::cout << "Value in unique_ptr: " << *uniquePtr << std::endl;
    *uniquePtr = 100;
    std::cout << "New value in unique_ptr: " << *uniquePtr << std::endl;
    std::cout << "Address of unique_ptr: " << uniquePtr.get() << std::endl;
    // Or
    auto uniquePtr2 = std::make_unique<int>(100);
    std::cout << "Value in uniquePtr2: " << *uniquePtr2 << std::endl;
    *uniquePtr2 = 50;
    std::cout << "Value in uniquePtr2: " << *uniquePtr2 << std::endl;

    // also can point an array
    auto uniqueArray = std::make_unique<int[]>(5);
    for (int i = 0; i < 5; ++i) {
        uniqueArray[i] = i * 10;
    }
    std::cout << "Values in uniqueArray: ";
    for (int i = 0; i < 5; ++i) {
        std::cout << uniqueArray[i] << " ";
    }
    std::cout << std::endl;

    // * shared_ptr: Allows multiple pointers to share ownership of an object.
    // * The object is deleted when the last shared_ptr pointing to it is destroyed.
    std::shared_ptr<int> sharedPtr1(new int(42));
    std::shared_ptr<int> sharedPtr2 = sharedPtr1; // shared ownership
    std::cout << "Value in sharedPtr1: " << *sharedPtr1 << std::endl;
    std::cout << "Value in sharedPtr2: " << *sharedPtr2 << std::endl;
    *sharedPtr1 = 200;
    std::cout << "New value in sharedPtr1: " << *sharedPtr1 << std::endl;
    std::cout << "New value in sharedPtr2: " << *sharedPtr2 << std::endl;

    auto var = std::make_shared<int>(100);
    std::cout << "Value in var: " << *var << std::endl;
    std::cout << "Address of var: " << var.get() << std::endl;

    // also can point an array
    //auto sharedArray = std::make_shared<int[]>(5);// C++17 does not support shared_ptr for arrays in this way
    std::shared_ptr<int[]> shared_array(new int[5]);
    for (int i = 0; i < 5; ++i) {
        shared_array[i] = i * 30; 
    }
    std::cout << "Values in sharedArray: ";
    for (int i = 0; i < 5; ++i) {
        std::cout << shared_array[i] << " ";
    }
    std::cout << std::endl;

    // By default use unique_ptr instead of raw pointers
    // but if you need shared ownership, use shared_ptr

    return 0;
}
