/*
 * Name: Lab 1B-2
 * Class: COMSC-165
 * Author: Tejas Shah
 * Description: It prompts the user for a lowercase letter, reprompting if it doesn't get one.
 */

#include <iostream>
#include <string>

using namespace std;

int main()
{
    bool hasValidChar = false;
    char input;

    while (!hasValidChar) {
        // prompt user to enter a lowercase letter
        cout << "Enter a lowercase letter from a to z: " << endl;
        cin >> input;
        // check if we get a bad input or it's not the desired input
        if (cin.bad() || input < 'a' || input > 'z') {
            cout << "Received invalid char: '" << input << "'. Try again" << endl;
        } else {
            // we have a valid char, thus we are done here
            hasValidChar = true;
            cout << "Congratulations valid entry!" << endl;
            cout << "Received valid char: '" << input << "'" << endl;
        }
    }

    return 0;
}
