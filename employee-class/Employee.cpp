// Implementation file for Employee class
#include "Employee.h"

// Constructor accpets arguments for the emplyee
// name, ID number, department, and position
Employee::Employee(string n, int id, string dept, string pos)
{
    name = n;
    idNumber = id;
    department = dept;
    position = pos;
}

// Construtor accpets arguments for the employee's
// name and ID number. Departmnet and position
// member variables are assigned empty storage.
Employee::Employee(string n, int id)
{
    name = n;
    idNumber = id;
    department = "";
    position = "";
}

// Default constructor assigns empty strings to
// name, department, position member variables.
// The idNumber member variable is assigned 0;
Employee::Employee()
{
    name = "";
    idNumber = 0;
    department = "";
    position = "";
}

// Mutator function for the name.
void Employee::setName(string n)
{
    name = n;
}

// Mutator fucntion for the ID number.
void Employee::setIdNumber(int id)
{
    idNumber = id;
}

// Mutator function for the department.
void Employee::setDepartment(string dept)
{
    department = dept;
}

// Mutator function for the psotion
void Employee::setPosition(string pos)
{
    position = pos;
}

// Accessor function for name
string Employee::getName() const
{
    return name;
}

// Accessor fucntion for id number
int Employee::getIdNumber() const
{
    return idNumber;
}

// Accesor function for department 
string Employee::getDepartment() const
{
    return department;
}

//Accessor fucntion for position
string Employee::getPosition() const
{
    return position;
}