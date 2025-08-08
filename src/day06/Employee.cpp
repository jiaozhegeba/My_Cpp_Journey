/*
 * My First C++ Program
 * An employee database example
 * 
 */



# include <iostream>
# include <string>

# include "Employee.h"


using namespace std;

namespace Records
{
    Records::Employee::Employee(const std::string& firstName, 
                                 const std::string& lastName)
        : mFirstName(firstName), mLastName(lastName)
    {
        // Constructor body (optional)
    }   

    void Employee::promote(int raiseAmount)
    {
        setSalary(getSalary() + raiseAmount);
    }

    void Employee::demote(int demeritAmount)
    {
        setSalary(getSalary() - demeritAmount);
    }


    void Employee::hire()
    {
        mIsHired = true;
    }

    void Employee::fire()
    {
        mIsHired = false;
    }

    void Employee::display() const
    {
        cout << "Employee: " << getLastName() << ", " << getFirstName() << endl;
        cout << "------------------------------" << endl;
        cout << (isHired() ? "Current Employee" : "Former Employee") << endl;
        cout << "Employee Number: " << getEmployeeNumber() << endl;
        cout << "Salary: $" << getSalary() << endl;
        cout << endl;
    }

    // Getters and setters
    void Employee::setFirstName(const string& firstName)
    {
        mFirstName = firstName;
    }
    const string& Employee::getFirstName() const
    {
        return mFirstName;
    }

    void Employee::setLastName(const string& lastName)
    {
        mLastName = lastName;
    }

    const string& Employee::getLastName() const
    {
        return mLastName;
    }

    void Employee::setEmployeeNumber(int employeeNumber)
    {
        mEmployeeNumber = employeeNumber;
    }

    int Employee::getEmployeeNumber() const
    {
        return mEmployeeNumber;
    }

    void Employee::setSalary(int newSalary)
    {
        mSalary = newSalary;
    }

    int Employee::getSalary() const
    {
        return mSalary;
    }

    bool Employee::isHired() const
    {
        return mIsHired;
    }

}