//
// Jose Garcia
// 9/14/25
// Inventory Program Programming Project
// COSC 2030
//

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

// Inventory item structure
struct InventoryItem
{
    char description[50];
    int quantity;
    double wholesaleCost;
    double retailCost;
    char dateAdded[11];
};

// Function prototypes
void addRecord(fstream &);
void displayRecord(fstream &);
void changeRecord(fstream &);
bool validDate(const char[]);
bool validNumber(double);

int main()
{
    fstream inventoryFile("inventory.dat", ios::in | ios::out | ios::binary);

    // if file doesnt exist, create one 
    if (!inventoryFile)
    {
        inventoryFile.open("inventory.dat", ios::out | ios::binary);
        inventoryFile.close();
        inventoryFile.open("inventory.dat", ios::in | ios::out | ios::binary);
    }

    int choice;
    do
    {
        cout << "\nInventory Menu\n";
        cout << "\n1. Add new record\n";
        cout << "2. Display record\n";
        cout << "3. Change record\n";
        cout << "4. Exit\n";
        cout << "\nEnter choice: ";
        cin  >> choice;
        cin.ignore(); 

        switch (choice)
        {
            case 1: addRecord(inventoryFile); break;
            case 2: displayRecord(inventoryFile); break;
            case 3: changeRecord(inventoryFile); break;
            case 4: cout << "Exiting program...\n"; break;
            default: cout << "Invalid choice.\n";
        } 

    } while (choice != 4);

    inventoryFile.close();
    return 0;
}

// add new record 
void addRecord(fstream &file)
{
    InventoryItem item;

    cout << "Enter item description: ";
    cin.getline(item.description, 50);

    do {
        cout << "Enter quantity on hand: ";
        cin >> item.quantity;
    } while (item.quantity < 0);

    do {
        cout << "Enter wholesale cost: ";
        cin >> item.wholesaleCost;
    } while (item.wholesaleCost < 0);

    do {
        cout << "Enter retail cost: ";
        cin >> item.retailCost;
    } while (item.retailCost < 0);

    cin.ignore();
    do {
        cout << "Enter date added (MM/DD/YYYY): ";
        cin.getline(item.dateAdded, 11);
    } while (!validDate(item.dateAdded));

    file.clear();
    file.seekp(0L, ios::end);
    file.write(reinterpret_cast<char*>(&item), sizeof(item));

    cout << "Record added.\n";
}

// Display record
void displayRecord(fstream &file)
{
    int recordNum;
    InventoryItem item;

    cout << "Enter record number you want displayed: ";
    cin >> recordNum;

    file.clear();
    file.seekg((recordNum - 1) * sizeof(item), ios::beg);
    file.read(reinterpret_cast<char*>(&item), sizeof(item));

    if (file.gcount() == sizeof(item))
    {
        cout << "\nDescription: " << item.description
             << "\nQuantity: " << item.quantity
             << "\nWholesale Cost: " << item.wholesaleCost
             << "\nRetail Cost: " << item.retailCost
             << "\nDate Added: " << item.dateAdded << endl;
    }
    else
    {
        cout << "Record not found.\n";
    }
}

// change esxisting record 
void changeRecord(fstream &file)
{
    int recordNum;
    InventoryItem item;

    cout << "Enter record number to change: ";
    cin >> recordNum;
    cin.ignore();

    file.clear();
    file.seekg((recordNum -1) * sizeof(item), ios::beg);
    file.read(reinterpret_cast<char*>(&item), sizeof(item));

    if (file.gcount() == sizeof(item))
    {
        cout << "Enter new description: ";
        cin.getline(item.description, 50);

        do {
            cout << "Enter new quantity: ";
            cin >> item.quantity;
        } while (item.quantity < 0);

        do {
            cout << "Enter new wholesale cost: ";
            cin >> item.wholesaleCost;
        } while (item.wholesaleCost < 0);

        do {
            cout << "Enter new retail cost: ";
            cin >> item.retailCost;
        } while (item.retailCost < 0);

        cin.ignore();
        do {
            cout << "Enter new date (MM/DD/YYYY): ";
            cin.getline(item.dateAdded, 11);
        } while (!validDate(item.dateAdded));

        file.seekp((recordNum - 1) * sizeof(item), ios::beg);
        file.write(reinterpret_cast<char*>(&item), sizeof(item));
        
        cout << "Record updated.\n";
    }
    else
    {
        cout << "Record not found.\n";
    }
}

// Validate date (MM/DD/YYYY)
bool validDate(const char date[])
{
    return strlen(date) == 10 && date[2] == '/' && date[5] == '/';
}

// validate non negative numbers
bool validNumber(double num)
{
    return num >= 0;
}

