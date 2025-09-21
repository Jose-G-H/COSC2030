//
// Jose Garcia 
// 09/21/25
// Employee Class Programming Project
// COSC 2030
//

#include <iostream>
#include "Employee.h"
using namespace std;

// Function prototype
void displayEmployee(Employee);

int main()
{
    // Create three Employee objects
    Employee susan("Susan Meyers", 47899, "Accounting", "Vice President");
    Employee mark("Mark Jones", 39119);
    Employee joy; 

    // Display each employees data
    cout << "Here is each employee data:\n";
    displayEmployee(susan);
    displayEmployee(mark);
    displayEmployee(joy);

    // Using mutator functions to update
    // mark and joy objects 
    mark.setDepartment("IT");
    mark.setPosition("Programmer");

    joy.setName("Joy Rogers");
    joy.setIdNumber(81774);
    joy.setDepartment("Manufacturing");
    joy.setPosition("Engineer");

    // Display each employee's data again
    cout << "\nEmployee data affter updating:\n";
    displayEmployee(susan);
    displayEmployee(mark);
    displayEmployee(joy);

    return 0;
}

// The displayEmployee function displays an 
// employee objcets data
void displayEmployee(Employee e)
{
    cout << "----------------------------------\n";
    cout << "Name: " << e.getName() << endl;
    cout << "ID Number: " << e.getIdNumber() << endl;
    cout << "Department: " << e.getDepartment() << endl;
    cout << "Position: " << e.getPosition() << endl;
}