//
// Jose Garcia
// 10/19/25
// Exception Project Programming Project
// COSC 2030
//

#include <iostream>
#include <string>
using namespace std;

class Employee
{
private:
    string employeeName;
    int employeeNumber;
    string hireDate;

    // Member function validates employee number
    void checkEmployeeNumber()
    {   if (employeeNumber < 0 || employeeNumber > 9999)
            throw InvalidEmployeeNumber();
    }

public:
    // exception class
    class InvalidEmployeeNumber{};

    // constructor
    Employee(string name, int number, string hDate)
    {   // set member variables
        employeeName = name;
        employeeNumber = number;
        hireDate = hDate;

        // check employee number
        checkEmployeeNumber();
    }

    // mutators
    void setEmployeeName(string name)
    {   employeeName = name;    }

    void setEmployeeNumber(int number)
    {   employeeNumber = number;
        checkEmployeeNumber();
    }

    void setHireDate(string hDate)
    {   hireDate = hDate;   }

    // accessors
    string getEmployeeName() const
    {   return employeeName;   }

    int getEmployeeNumber() const
    {   return employeeNumber;  }

    string getHireDate() const
    {   return hireDate;    }
};

class ProductionWorker : public Employee
{
private:
    int shift;
    double hourlyPayRate;

    // member function validates shift number
    void checkShift()
    {   if (shift < 1 || shift > 2)
            throw InvalidShift();
    }

    // member function validates pay rate
    void checkPayRate()
    {   if (hourlyPayRate < 0)
            throw InvalidPayRate();
    }

public:
    // Exception classes
    class InvalidShift
    {};

    class InvalidPayRate
    {};

    // Constructor
    ProductionWorker(string name, int number, string hDate,
        int shiftNum, double payRate) : Employee(name, number, hDate)
    {   // set member variables
        shift = shiftNum;
        hourlyPayRate = payRate;

        // check shift and pay rate
        checkShift();
        checkPayRate();
    }

    // Mutators
    void setShift(int shiftNum)
    {   shift = shiftNum;
        checkShift();
    }

    void setHourlyPayRate(double payRate)
    {   hourlyPayRate = payRate;
        checkPayRate();
    }

    // Accessors
    int getShift() const
    {   return shift;   }

    double getHourlyPayRate()
    {   return hourlyPayRate;   }
};

// function prototype
void testValues(string, int, string, int, double);

int main()
{
    // test all good data
    cout << "Testing good data...\n";
    testValues("John Doe", 1234, "12/01/2009", 1, 22.50);

    // test bad employee number
    cout << "\nTesting a bad employee number...\n";
    testValues("John Doe", -99, "12/01/2009", 1, 22.50);

    // test a bad shift number
    cout << "\nTesting a bad shift number...\n";
    testValues("John Doe", 1234, "12/01/2009", 5, 22.50);

    // test bad pay rate
    cout << "\nTesting a bad pay rate...\n";
    testValues("John Doe", 1234, "12/01/2009", 1, -100.0);

    return 0;
}

void testValues(string name, int number, string hDate, int shift, double payRate)
{
    // test the InvalidEmployeeNumber exception
    try
    {
        // create production worker with invalid number
        ProductionWorker(name, number, hDate, shift, payRate);

        // Report good data
        cout << "Good data\n";
    }
    catch (Employee::InvalidEmployeeNumber)
    {
        cout << "Invalid employee number encountered.\n";
    }
    catch (ProductionWorker::InvalidShift)
    {
        cout << "Invalid shift encountered.\n";
    }
    catch (ProductionWorker::InvalidPayRate)
    {
        cout << "Invalid pay rate encountered.\n";
    }
}