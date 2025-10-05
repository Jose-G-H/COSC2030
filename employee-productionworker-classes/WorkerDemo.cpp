#include <iostream>
#include "ProductionWorker.cpp"
using namespace std;

int main()
{
    //create ProductionWorker object with constructor
    ProductionWorker pw("John Smith", "123-A", "11-15-2015",
                         ProductionWorker::DAY_SHIFT, 26.50);

    cout << "Here's the first production worker:\n";
    pw.display();

    cout << "\n";

    // Creeate another productionWorker object 
    ProductionWorker pw2;
    pw2.setName("John Jones");
    pw2.setEmployeeNumber("222-L");
    pw2.setHireDate("12-01-2020");
    pw2.setShift(ProductionWorker::NIGHT_SHIFT);
    pw2.setPayRate(28.50);

    cout << "Here's the second production worker:\n";
    pw2.display();

    return 0;
}  