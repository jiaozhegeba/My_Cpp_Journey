# Understanding `namespace` in C++

In C++, the statement:

```cpp
namespace Name {
    // code (functions, variables, classes, etc.)
}
```

defines a **namespace** called `Name`. A namespace is a container that allows you to organize code into **logical groups** and avoid name conflicts (name collisions) in larger projects.

## 🧠 Breakdown of `namespace Name {}`

### ✅ What is a Namespace?

- **Namespace** is a mechanism that allows you to define a scope for identifiers (like variables, functions, classes, etc.).
- It groups related code together to prevent **name conflicts**.

For example, in a big project, two different parts of the project might have a function called `print()`. With namespaces, you can avoid a conflict by giving each `print()` function a different namespace.

## ✅ Example

```cpp
namespace math {
    int add(int a, int b) {
        return a + b;
    }
}

namespace utils {
    void print(const std::string& msg) {
        std::cout << msg << std::endl;
    }
}

int main() {
    int sum = math::add(3, 4);  // Calling math::add
    utils::print("Sum is: " + std::to_string(sum));  // Calling utils::print
    return 0;
}
```

### Explanation:
1. `namespace math`: Contains the `add` function.
2. `namespace utils`: Contains the `print` function.
3. In `main()`, you access the functions by using **qualified names** (`math::add`, `utils::print`).

## ✅ Why Use Namespaces?

1. **Avoid Name Conflicts:**
   - If two libraries both have a function `add()`, you can use namespaces to distinguish them.

2. **Organize Code:**
   - You can logically group related functions, classes, and variables into namespaces (e.g., `math`, `graphics`, `io`).

## ✅ `namespace Name {};` (Empty Namespace)

You can define an empty namespace like this:

```cpp
namespace Name {};
```

This is useful for **forward declaration** or defining an **empty container** that will be filled with content later.

### Example of an Empty Namespace:
```cpp
namespace Name {
    // The namespace is empty right now
}

// Later, you can define functions inside Name
namespace Name {
    void func() {
        std::cout << "Inside namespace Name" << std::endl;
    }
}

int main() {
    Name::func();  // Calling the function from namespace Name
    return 0;
}
```

## ✅ Nested Namespaces
You can also have namespaces inside other namespaces:

```cpp
namespace outer {
    namespace inner {
        void greet() {
            std::cout << "Hello from inner namespace!" << std::endl;
        }
    }
}

int main() {
    outer::inner::greet();  // Call from nested namespace
    return 0;
}
```

## ✅ `using` Keyword

Instead of fully qualifying namespace members, you can use the `using` directive to make them accessible without the namespace prefix:

```cpp
using namespace math;
int result = add(3, 4);  // No need to write math::add
```

However, be cautious using `using namespace` globally, as it can lead to **name conflicts** if overused.

## ⚠️ Summary

- **Namespace** helps avoid name conflicts by grouping related code.
- **Empty namespace** (`namespace Name {};`) is useful for forward declarations or as a placeholder.
- **Nested namespaces** allow hierarchical organization.
- **Using the `using` directive** simplifies code but should be used carefully.


## Class Member Functions

In C++, classes can have member functions that define the behavior of the class. 
```cpp

class Employee
{
    public:
        Employee() = default;
        Employee(const std::string& firstName, 
                 const std::string& lastName);

        void promote(int raiseAmount = 1000); // Default parameter value of 1000. If no argument is passed, it will use 1000.
        void demote(int demeritAmount = 1000); // Like promote, but for demotion.
        void hire();
        void fire();
        void display() const; // const means this function does not modify any member variables
};
```

getter and setter 

functions are used to access and modify private member variables of a class. They provide controlled access to the class's data, ensuring encapsulation.

```cpp
class Employee
{
    private:
        std::string firstName;
        std::string lastName;
        int salary;

    public:
        Employee() = default;
        Employee(const std::string& firstName, 
                 const std::string& lastName, 
                 int salary);

        // Getter for firstName
        const std::string& getFirstName() const {
            return firstName;
        }

        // Setter for firstName
        void setFirstName(const std::string& name) {
            firstName = name;
        }

        // Getter for lastName
        const std::string& getLastName() const {
            return lastName;
        }

        // Setter for lastName
        void setLastName(const std::string& name) {
            lastName = name;
        }

        // Getter for salary
        int getSalary() const {
            return salary;
        }

        // Setter for salary
        void setSalary(int newSalary) {
            salary = newSalary;
        }
};
```
