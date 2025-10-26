//
// Jose Garcia
// 10/26/25
// Course Information Programming Project
// COSC 2030
//

#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    string courseNumber; // hold course number

    // map containing course numbers & room numbers
    map<string, string> courseRoom = { { "CS101", "3004" },{ "CS102", "4501" },
                                       { "CS103", "6755" },{ "NT110", "1244" },
                                       { "CM241", "1411" } };
    
    // map containing course numbers & instructors
    map<string, string> courseInstructor = { { "CS101", "Haynes" },{ "CS102", "Alvarado" },
                                        { "CS103", "Rich" },{ "NT110", "Burke" },
                                        {"CM241", "Lee" } };
    
    // map containing course numbers & meeting times
    map<string, string> courseTimes = { { "CS101", "8:00 A.M." },{ "CS102", "9:00 A.M."},
                                        { "CS103", "10:00 A.M." },{ "NT110", "11:00 A.M." },
                                        { "CM241", "1:00 P.M." } };

    // Get course number from user
    cout << "Enter a course number to get information about that course: ";
    getline(cin, courseNumber);

    // Display information about course
    if (courseRoom.count(courseNumber))
    {
        cout << "\nRoom number: " << courseRoom.at(courseNumber) << endl;
        cout << "Instructor: " << courseInstructor.at(courseNumber) << endl;
        cout << "Meeting time: " << courseTimes.at(courseNumber) << endl;
    }
    else
    {
        cout << "Invalid course" << endl;
    }

    return 0;
}