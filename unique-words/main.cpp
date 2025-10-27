//
// Jose Garcia 
// 10/26/25
// Unique Words Programming Project
// COSC 2030
//

#include <iostream>
#include <fstream>
#include <string>
#include <set>
using namespace std;

int main()
{
    string word;
    set<string> uniqueWords; // holds the unique words
    ifstream inputFile("Kennedy.txt");

    // check if file opened
    if (!inputFile)
    {
        cout << "Error opening file.\n";
        return 1;
    }

    // Read each word from file & put into text 
    while (inputFile >> word)
    {
        uniqueWords.insert(word);
    }

    inputFile.close();

    // display unique words
    cout << "The unique words found in the file:\n\n";
    for (auto it = uniqueWords.begin(); it != uniqueWords.end(); ++it)
    {
        cout << *it << endl;
    }

    return 0;
}