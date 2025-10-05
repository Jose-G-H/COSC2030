#include <iostream>
#include <iomanip>
#include "Employee.cpp"
using namespace std;

/* The productionWorker class stores data about
an employee who is a production worker */

class ProductionWorker : public Employee
{
private:
    int shift; // employees shift
    double payRate; // employees pay rate

public:
    static const int DAY_SHIFT = 1;
    static const int NIGHT_SHIFT = 2;

    // default contructor
    ProductionWorker() : Employee()
    {
        shift = DAY_SHIFT;
        payRate = 0.0;
    }

    // overloaded contructor
    ProductionWorker(string n, string num, string date, int sh, double rate)
     : Employee(n, num, date)
     {
        shift = sh;
        payRate = rate;
     }
     
     // set
     void setShift(int s) { shift = s; }
     void setPayRate(double p) {payRate = p;}

     // get
     int getShift() { return shift; }
     double getPayRate() { return payRate;}

     // display 
     void display() 
     {
        Employee::display();
        cout << "Shift: ";
        if (shift == DAY_SHIFT)
            cout << "DAY" << endl;
        else if (shift == NIGHT_SHIFT)
            cout << "NIGHT" << endl;
        else
            cout << "INVALID SHIFT NUMBER" << endl;
        cout << fixed << setprecision(2);
        cout << "Hourly Pay Rate: $" << payRate << endl;
        
     }
};
