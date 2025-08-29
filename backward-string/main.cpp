//
// Jose Garcia 
// 8/29/25
// Backward String Programming Project
// COSC 2030
//

#include <iostream>
#include <cstring>
using namespace std;

// Function prototype
void backward(char *);

int main()
{
    // Define array to hold input
    const int SIZE = 80;
    char input[SIZE];

    // Get a string from user
    cout << "Enter a string and i will display it backwards:\n";
    cin.getline(input, SIZE);

    //Display string bakwards
    backward(input);
    return 0;
}

// Backward function accepts pointer to c string 
// and displays the string backwards 

void backward(char *str)
{
    // Get the subscript of last character in string 
    int last = strlen(str) - 1;

    // Work backward through string, displaying
    // each character from last to first
    for (int index = last; index >= 0; index--)
        cout << str[index];

    // End line
    cout << endl;
}