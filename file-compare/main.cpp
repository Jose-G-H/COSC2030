//
// Jose Garcia
// 11/09/2025
// File Compare Programming Project
// COSC 2030
//

#include<iostream>
#include<fstream>
#include<cstdlib>
#include "Dynqueue.h"
using namespace std;

int main()
{
    // Create input file stream object
    fstream file1("file1.txt", ios::in);

    // Create another input fstream object
    fstream file2("file2.txt", ios::in);

    // Create two queues to hold characters 
    Dynque<char> queue1;
    Dynque<char> queue2;
    char ch1, ch2;

    // Read all characters from file #1, enque in queue1
    file1.get(ch1);
    while (!file1.eof())
    {
        queue1.enqueue(ch1);
        file1.get(ch1);
    }

    // Read all characters from file #2, enque in queue2
    file2.get(ch2);
    while (!file2.eof())
    {
        queue2.enqueue(ch2);
        file2.get(ch2);
    }

    // close files
    file1.close();
    file2.close();

    // Deque characters from each queue, one at a time and compare them
    while (!queue1.isEmpty() && !queue2.isEmpty())
    {
        queue1.dequeue(ch1);
        queue2.dequeue(ch2);
        cout << ch1 << "\t" << ch2 << endl;
        if (ch1 != ch2)
        {
            cout << "\nThe files are not identical.\n";
            return 0;
        }
    }

    cout << "\nThe files are identical.\n" << endl << endl;
    return 0;
}

