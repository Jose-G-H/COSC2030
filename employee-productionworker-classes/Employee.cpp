//
// Jose Garcia 
// 10/5/2025
// Employee and ProductionWorker Classes Programming Project
// COSC 2030
//

#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

/* Employee class stores data about employee */
class Employee 
{
private:
    string name; // Employee name
    string employeeNumber; // Employee number
    string hireDate; // Employee hire date



public:
    // default constructor
    Employee() 
    {
        name = "";
        employeeNumber = "";
        hireDate = "";
    }

    // overloaded constructor
    Employee(string n, string num, string date) 
    {
        name = n;
        setEmployeeNumber(num);
        hireDate = date;
    }

    // mutators
    void setName(string n) 
    {
        name = n;
    }

    void setEmployeeNumber(string e)
    {
        employeeNumber = e;
    }

    void setHireDate(string h)
    {
        hireDate = h;
    }

    // accessors 
    string getName()
    {
        return name;
    }

    string getEmployeeNumber()
    {
        return employeeNumber;
    }

    string getHireDate()
    {
        return hireDate;
    }

    // Display Employess information
    void display()
    {
        cout << "Name: " << name << endl;
        if (employeeNumber == "")
            cout << "Employee Number: INVALID EMPLOYEE NUMBER" << endl;
        else 
            cout << "Employee Number: " << employeeNumber << endl;
        cout << "Hire Date: " << hireDate << endl;
    }

 };