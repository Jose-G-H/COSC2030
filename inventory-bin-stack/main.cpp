//
// Jose Garcia
// 11/09/25
// Inventory Bin Stack Programming Project
// COSC 2030
//

#include <iostream>
#include <string>
#include "inventory.h"
#include "DynStack.h"
using namespace std;

int main()
{
    DynStack<inventory> stack;
    inventory part;
    int choice;
    int serial;
    string date;
    int lot;
    bool done = false;

    cout << "Inventory Stack Program\n";
    cout << "------------------------\n";

    while (!done)
    {
        cout << "\n1. Add a part to the inventory\n";
        cout << "2. Remove a part from the inventory\n";
        cout << "3. Quit the program\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // skip nelwine after number input

        if (choice == 1)
        {
            cout << "\nEnter the serial number: ";
            cin >> serial;
            cin.ignore();

            cout << "Enter the manufacture date: ";
            getline(cin, date);

            cout << "Enter the lot number: ";
            cin >> lot;

            // create new part objcet
            inventory newPart(serial, date, lot);
            stack.push(newPart);
            cout << "Part added to inventory.\n";
        }
        else if (choice == 2)
        {
            if (!stack.isEmpty())
            {
                stack.pop(part);
                cout << "\nPart removed from inventory:\n";
                cout << "-----------------------------\n";
                part.display();
            }
            else
                cout << "Inventory is empty.\n";
        
        }
        else if (choice == 3)
        {
            done = true;
        }
        else
        {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    cout << "\nDisplaying the remaining inventory parts:\n";
    stack.displayAll();

    cout << "\nEnd of program.\n";
    return 0;
}