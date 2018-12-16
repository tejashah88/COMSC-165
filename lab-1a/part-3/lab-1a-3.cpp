/*
 * Name: Lab 1A-3
 * Class: COMSC-165
 * Author: Tejas Shah
 * Description: It prompts for the user's current year and GPA and reports if they are ready to graduate or not.
 */

#include <iostream>
#include <string>

using namespace std;

int main()
{
    // define here constants here
    const int PASSING_YEAR = 4;
    const float PASSING_GPA = 2.0;

    // define needed variables here
    int userYear;
    float userGPA;

    // prompt the user for their year
    cout << "What year are you in: " << endl;
    cin >> userYear;

    // prompt the user for their GPA
    cout << "What is your GPA: " << endl;
    cin >> userGPA;

    // set to true only if the student is in year 4 and his/her GPA is greater than or equal to 2.0
    bool isGraduating = userYear == PASSING_YEAR && userGPA >= PASSING_GPA;

    // create the message and display it
    string message = isGraduating ? "You will be graduating this year" : "More school for you";
    cout << message << endl;

    return 0;
}
