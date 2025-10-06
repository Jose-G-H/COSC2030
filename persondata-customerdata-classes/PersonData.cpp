//
// Jose Garcia
// 10/05/25
// PersonData and CustomerData Classes Programming Project
// COSC 2030
//

#include <iostream>
#include <iostream>
using namespace std;

/* PersonData class stores basic information */

class PersonData
{
private:
    string lastName;
    string firstName;
    string address;
    string city;
    string state;
    string zip;
    string phone;

public:
    // default constructor
    PersonData()
    {
        lastName = "";
        firstName = "";
        address = "";
        city = "";
        state = "";
        zip = "";
        phone = "";
    }

    // overloaded constructor
    PersonData(string ln, string fn, string addr, string c, string st, string z, string ph)
    {
        lastName = ln;
        firstName = fn;
        address = addr;
        city = c;
        state = st;
        zip = z;
        phone = ph;
    }

    // mutators
    void setLastName(string ln) {lastName = ln;}
    void setFirstName(string fn) {firstName = fn;}
    void setAddress(string addr) {address = addr;}
    void setCity(string c) {city = c;}
    void setState(string st) {state = st;}
    void setZip(string z) {zip = z;}
    void setPhone(string ph) {phone = ph;}

    // accessor
    string getLastName() {return lastName;}
    string getFirstName() {return firstName;}
    string getAddress() {return address;}
    string getCity() {return city;}
    string getState() {return state;}
    string getZip() {return zip;}
    string getPhone() {return phone;}

    // display data
    void display()
    {
        cout << "Name: " << firstName << " " << lastName << endl;
        cout << "Address: " << address << endl;
        cout << "City: " << city << ", State: " << state << "  Zip: " << zip << endl;
        cout << "Phone: " << phone << endl;
    }
};