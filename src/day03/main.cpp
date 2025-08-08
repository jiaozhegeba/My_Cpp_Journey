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


void fun_addOne(int i)
{
    i += 1;
}

void fun_addOne_ref(int& j)
{
    j += 1;
}

void print_str(const std::string& str)
{
    std::cout << "String: " << str << std::endl;
    //str += " modified"; // This will not change the original string
    //std::cout << "Modified String: " << str << std::endl;
}

double divide(double a, double b)
{
    if (b == 0) {
        //throw std::runtime_error("Division by zero");
        throw std::invalid_argument("Division by zero");
    }
    return a / b;
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


    //////////////
    // Reference//
    //////////////
    int x = 10;
    int& ref_x = x; // Create a reference to x
    std::cout << "Value of x: " << x << std::endl;
    std::cout << "Value of ref_x: " << ref_x << std::endl;
    ref_x = 20; // Modify x through the reference
    std::cout << "New value of x: " << x << std::endl;
    std::cout << "New value of ref_x: " << ref_x << std::endl;

    //
    // Pass by reference
    //
    int num = 5;
    std::cout << "Before fun_addOne: " << num << std::endl;
    fun_addOne(3); // Pass by value
    std::cout << "After fun_addOne (by value): " << num << std::endl;
    fun_addOne_ref(num); // Pass by reference
    std::cout << "After fun_addOne (by reference): " << num << std::endl;

    //
    // Pass by const reference
    //
    std::string str = "Hello";
    print_str(str); 
    // * no copy is made but the original variable cannot be changed



    ////////////////
    // Exceptions //
    ////////////////
    try {
        std::cout << divide(10.0, 2.0) << std::endl; // Should work fine
        double result = divide(10.0, 0.0);
        std::cout << "Result: " << result << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "Caught an exception: " << e.what() << std::endl;
    }

    ////////////////////
    // Type reference //
    ////////////////////
    // * Type reference can let compiler automatically deduce the type of a variable.
    // * keyword auto and decltype

    auto a = 10; // a is of type int
    auto b = 3.14; // b is of type double
    std::cout << "a: " << a << ", b: " << b << std::endl;
    std::cout << "Type of a: " << typeid(a).name() << std::endl;
    std::cout << "Type of b: " << typeid(b).name() << std::endl;

    // * auto strips away the reference and constness, so use auto& or const auto& to keep the reference or constness.
    const auto& c = b; // c is a const reference to b
    std::cout << "c: " << c << std::endl;
    //c = 5.0; // This will not compile because c is a const reference


    // * decltype can be used to get the type of an expression without evaluating it.
    decltype(a) d = 20; // d is of type int, same as a
    std::cout << "d: " << d << std::endl;
    decltype(b) e = 2.71; // e is of type double, same as b
    std::cout << "e: " << e << std::endl;
    std::cout << "Type of d: " << typeid(d).name() << std::endl;
    std::cout << "Type of e: " << typeid(e).name() << std::endl;
    // * decltype can also be used with references and const variables.


    return 0;
}
