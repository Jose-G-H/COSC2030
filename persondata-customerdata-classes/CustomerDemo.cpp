#include <iostream>
#include "CustomerData.cpp"
using namespace std;

int main()
{
    // CustomerData objcet with ovelroaded constructor
    CustomerData customer1("Doe", "Jane", "123 Elm St", "Springfield", "IL", "62701", "217-555-1234", 
                            101, true);

    cout << "Customer 1 Information:" << endl;
    customer1.display();

    cout << "\n";

    // another cutsomer, using default constructor and mutators
    CustomerData customer2;
    customer2.setFirstName("John");
    customer2.setLastName("Smith");
    customer2.setAddress("456 Oak Ave");
    customer2.setCity("Lincoln");
    customer2.setState("NE");
    customer2.setZip("68508");
    customer2.setPhone("402-555-9876");
    customer2.setCustomerNumber(102);
    customer2.setMailingList(false);

    cout << "Customer 2 Information:" << endl;
    customer2.display();

    return 0;
}