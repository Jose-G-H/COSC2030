//
// Jose Garcia
// 9/5/25
// Movie Data Programming Project
// COSC 2030
//

#include <iostream>
#include <cstring>
using namespace std;

// Define Moviedata structure 
struct MovieData
{
    char title[50];
    char director[50];
    int  yearReleased;
    int runningTime;
};

// Function prototype 
void displayMovie(const MovieData &);

int main()
{
    // Two variables for MovieData
    MovieData movie1;
    MovieData movie2;

    // use strcpy to store values
    strcpy(movie1.title, "The Fast and the Furious");
    strcpy(movie1.director, "Vin Diesel");
    movie1.yearReleased = 2001;
    movie1.runningTime = 106;

    strcpy(movie2.title, "Napolean Dynamite");
    strcpy(movie2.director, "Jared Hess");
    movie2.yearReleased = 2004;
    movie2.runningTime = 82;

    // Display both movies
    displayMovie(movie1);
    cout << endl;
    displayMovie(movie2);
    
    return 0;
}

// Function to display movie info
void displayMovie(const MovieData &m)
{
    cout << "Title: " << m.title << endl;
    cout << "Director: " << m.director << endl;
    cout << "Year Released: " << m.yearReleased << endl;
    cout << "Running Time: " << m.runningTime << " minutes" << endl;
}