#include <iostream>
#include "PersonData.cpp"
using namespace std;

/* CustomerData class stores customer info 
    and inherits from PersonData */

class CustomerData : public PersonData
{
private:
    int customerNumber; // customer unique id
    bool mailingList; // if on mailing list true, otherwise false

public:
    // default constructor 
    CustomerData() : PersonData()
    {
        customerNumber = 0;
        mailingList = false;
    }

    // overloaded constructor
    CustomerData(string ln, string fn, string addr, string c, string st, string z, string ph,
                 int custNum, bool mail)
        : PersonData(ln, fn, addr, c , st, z, ph)
    {
        customerNumber = custNum;
        mailingList = mail;
    }

    // mutators
    void setCustomerNumber(int num) {customerNumber = num;}
    void setMailingList(bool mail) {mailingList = mail;}

    // accessors
    int getCustomerNumber() {return customerNumber;}
    bool getMailingList() {return mailingList;}

    // display data
    void display()
    {
        PersonData::display();
        cout << "Customer Number: " << customerNumber << endl;
        cout << "On Mailing List: " << (mailingList ? "Yes" : "No") << endl;
    }
};