/*
 * Name: Lab 1A-1
 * Class: COMSC-165
 * Author: Tejas Shah
 * Description: It prompts for a number and reports the user if it equals the BASELINE_NUMBER or not.
 */

#include <iostream>
#include <string>

using namespace std;

int main()
{
    // define needed variables and constants here
    const int BASELINE_NUMBER = 35;
    int input;

    // prompt the user for a number
    cout << "Enter a valid integer: " << endl;
    cin >> input;

    // set to true if the input equals the baseline number
    bool matchingBaseline = input == BASELINE_NUMBER;

    // create the message and display it
    string message = matchingBaseline ? "Equal Numbers" : "Unequal";
    cout << message << endl;

    return 0;
}
