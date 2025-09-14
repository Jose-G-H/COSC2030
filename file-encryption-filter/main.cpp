//
// Jose Garcia 
// 09/14/25
// File Encryption Programming Project
// COSC 2030
//

// File encyrption filter 
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    ifstream inputFile; // input file object 
    ofstream outputFile; // output file object

    string inFileName; // input file name 
    string outFileName; // output file name
    char data; // to hold a chaacter of data

    // Get the input file name
    cout << "Enter the input file name: ";
    getline(cin, inFileName);

    // Get the output file name 
    cout << "Enter the output file name: ";
    getline(cin, outFileName);

    // Open the files
    inputFile.open(inFileName.c_str());
    outputFile.open(outFileName.c_str());

    // Read the first character from input file
    inputFile.get(data);

    /* Read contents of the input file,
    one character at a time, encrypt it, and store in output file */
    while (inputFile)
    {
        // Encrypt the character by adding 10 to it
        data += 10;

        // Write the character to outputFile
        outputFile.put(data);

        // Get the next character from inputFile
        inputFile.get(data);
    }
    cout << "The file has been encrypted.\n";

    //close both files.
    inputFile.close();
    outputFile.close();

    return 0;
}