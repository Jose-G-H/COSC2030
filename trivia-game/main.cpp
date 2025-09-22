//
// Jose Garcia 
// 09/21/25
// Trivia Game Programming Project
// COSC 2030
//

#include <iostream>
#include "Question.h"
using namespace std;

int main()
{
    const int NUM_QUESTIONS = 10;
    Question trivia[NUM_QUESTIONS]
    {
        Question("What holiday is usually celebrated on December 25th?", "Halloween", "Christmas", "Easter", "Thanksgiving", 2),
        Question("Which holiday on July 4th involves fireworks?", "Independence Day", "Memorial Day", "Labor Day", "Veterans Day", 1),
        Question("What Holiday is known for costumes and trick or treating?", "Halloween", "Valentines Day", "New Years Eve", "Thanksgiving", 1),
        Question("Which holiday honors U.S. Veterans?", "Memorial Day", "Veterans Day", "Armed Forces Day", "Patriot Day", 2),
        Question("On which Holiday do people eat turkey?", "Thanksgiving", "New Years Day", "Easter", "Christmas", 1),
        Question("Which holiday marks the start of a new year?", "Christmas", "New Years Day", "Halloween", "Memorial Day", 2),
        Question("Which holiday has a bunny?", "Christmas", "Thanksgiving", "Easter", "Valentines Day", 3),
        Question("Which holiday is known for an angel with a bow and arrow?", "Easter", "Christmas", "Valentines Day", "Thanksgiving", 3),
        Question("Which holiday uses a tree and presents?", "Halloween", "Christmas", "Thanksgiving", "Hanukkah", 2),
        Question("Which holiday is considered spooky?", "Christmas", "Thanksgiving", "Halloween", "Labor Day", 3)
    };

    int player1Score = 0;
    int player2Score = 0;
    int answer;

    cout << "Welcome Holiday Trivia!\n";

    // Player 1
    cout << "\n--- Player 1 Turn ---\n";
    for (int i = 0; i < 5; i++)
    {
        cout << trivia[i].getQuestion() << endl;
        cout << "1. " << trivia[i].getAnswer1() << endl;
        cout << "2. " << trivia[i].getAnswer2() << endl;
        cout << "3. " << trivia[i].getAnswer3() << endl;
        cout << "4. " << trivia[i].getAnswer4() << endl;
        cout << "Enter your answer (1-4): ";
        cin >> answer;

        if (answer == trivia[i].getCorrectAnswer())
        {
            cout << "Correct!\n";
            player1Score++;
        }
        else
            cout << "Wrong!\n";
        cout << endl;
    }

    // Player 2
    cout << "\n--- Player 2 Turn ---\n";
    for (int i =5; i < 10; i++)
    {
        cout << trivia[i].getQuestion() << endl;
        cout << "1. " << trivia[i].getAnswer1() << endl;
        cout << "2. " << trivia[i].getAnswer2() << endl;
        cout << "3. " << trivia[i].getAnswer3() << endl;
        cout << "4. " << trivia[i].getAnswer4() << endl;
        cout << "Enter your answer (1-4): ";
        cin >> answer;

        if (answer == trivia[i].getCorrectAnswer())
        {
            cout << "Correct!\n";
            player2Score++;
        }
        else
            cout << "Wrong!\n";
        cout << endl;
    }

    // Results
    cout << "\n--- Final Results ---\n";
    cout << "Player 1 Score: " << player1Score << endl;
    cout << "Player 2 Score: " << player2Score << endl;

    if (player1Score > player2Score)
        cout << "Player 1 wins!\n";
    else if (player2Score > player1Score)
        cout << "Player 2 wins!\n";
    else
        cout << "Its a tie!\n";
}