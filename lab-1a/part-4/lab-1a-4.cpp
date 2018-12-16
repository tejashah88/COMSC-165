/*
 * Name: Lab 1A-4
 * Class: COMSC-165
 * Author: Tejas Shah
 * Description: It prompts for a letter grade and reports on their performance based on it.
 */

#include <iostream>
#include <string>

using namespace std;

int main()
{
    char inputGrade;

    // prompt the user for a letter grade
    cout << "Enter your grade: " << endl;
    cin >> inputGrade;

    // check the input grade and assign the appropriate message
    string message;
    switch (inputGrade) {
        case 'A':
            message = "Excellent";
            break;
        case 'B':
            message = "Good";
            break;
        case 'C':
            message = "Okay Job";
            break;
        case 'D':
            message = "Just managed to pass";
            break;
        case 'F':
            message = "Failed";
            break;
        default:
            message = "Invalid Grade";
    }

    cout << message << endl;
    return 0;
}
