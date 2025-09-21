// Specification file for Employee class
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
using namespace std;

class Employee
{
private:
    string name; // Employees name
    int idNumber; // ID number 
    string department; // Department name
    string position; // Job title 

public:
    //constructors
    Employee(string, int, string, string);
    Employee(string, int);
    Employee();

    // Mutators
    void setName(string);
    void setIdNumber(int);
    void setDepartment(string);
    void setPosition(string);

    //Accesors
    string getName() const;
    int getIdNumber() const;
    string getDepartment() const;
    string getPosition() const;
};

#endif