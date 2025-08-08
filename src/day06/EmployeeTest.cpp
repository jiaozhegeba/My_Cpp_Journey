#include <iostream>
#include "Employee.h"

using namespace std;
using namespace Records;
/*
 * This is a simple program to test the Employee class.
 * It creates an Employee object, sets its properties, promotes it, and displays its information.
 * The Employee class is defined in Employee.h and implemented in Employee.cpp.
 */
int main()
{
    cout << "Testing the Employee class." << endl;
    Employee emp;
    emp.setFirstName("John");
    emp.setLastName("Doe");
    emp.setEmployeeNumber(71);
    emp.setSalary(50000);
    emp.promote();
    emp.promote(50);
    emp.hire();
    emp.display();
    
    return 0;
}