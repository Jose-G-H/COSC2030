#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <string>
using namespace std;

class inventory
{
    private:
        int serialNum;
        string manufactDate;
        int lotNum;
    
    public:
        // constructor
        inventory()
        {
            serialNum = 0;
            manufactDate = "";
            lotNum = 0;
        }

        inventory(int s, string d, int l)
        {
            serialNum = s;
            manufactDate = d;
            lotNum = l;
        }

        // mutators
        void setSerialNum(int s)
        {   serialNum = s;  }

        void setManufactDate(string d)
        {   manufactDate = d;   }

        void setLotNum(int l)
        {   lotNum = l; }

        // accessors
        int getSerialNum() const
        {   return serialNum;   }

        string getManufactDate() const
        {   return manufactDate;    }

        int getLotNum() const
        {   return lotNum;  }

        // display func
        void display() const
        {
            cout << "Serial Number: " << serialNum << endl;
            cout << "Manufacture Date: " << manufactDate << endl;
            cout << "Lot Number: " << lotNum << endl;
        }
};

#endif