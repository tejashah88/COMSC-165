/*
 * Name: Lab 1A-2
 * Class: COMSC-165
 * Author: Tejas Shah
 * Description: It prompts for the user's average grade and reports if he/she will pass or not.
 */

#include <iostream>
#include <string>

using namespace std;

int main()
{
    // define needed variables and constants here
    const int PASSING_GRADE = 80;
    int inputGrade;

    // prompt the user for a grade
    cout << "Enter a valid grade: " << endl;
    cin >> inputGrade;

    // set to true if the user's grade is greater than or equal to the passing grade
    bool willPass = inputGrade >= PASSING_GRADE;

    // create the message and display it
    string message = willPass ? "You Passed" : "You Failed";
    cout << message << endl;

    return 0;
}
