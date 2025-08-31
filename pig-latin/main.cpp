//
// Jose Garcia 
// 8/29/25
// Pig Latin Programming Project
// COSC 2030
//

#include <iostream>
#include <cstring>
using namespace std;

// Function prototype 
void pigLatin(char *);

int main()
{
    const int SIZE = 200;
    char input[SIZE];

    // Get sentence from user
    cout << "Enter a sentecne in ALL CAPS to convert to Pig Latin:\n";
    cin.getline(input, SIZE);

    // Convert to pig latin
    pigLatin(input);

    return 0;
}

// Function to convert cstring to piglain 
void pigLatin(char *str)
{
    const int WORDSIZE = 40;
    char word[WORDSIZE];
    int i = 0;

    while (str[i] != '\0')
    {
        int j = 0;

        // Take one word at a time
        while (str[i] != ' ' && str[i] !='\0')
        {
            word[j] = str[i];
            j++;
            i++;
        }
        word[j] = '\0';

        // Convert word into pig latin
        int len = strlen(word);

        if (len == 1)

        {
            cout << word << "AY";
        }
        else if (len > 1)
        {
            // Move letters to the end
            for (int k = 1; k < len; k++)
                cout << word[k];
            
            // Add the first letter
            cout << word[0];
            
            // add "AY"
            cout << "AY";
        }

        // Add any spaces found
        if (str[i] == ' ')
        {
            cout << " ";
            i++;
        }
    }
    
    cout << endl;
}