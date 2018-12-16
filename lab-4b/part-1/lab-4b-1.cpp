/*
 * Name: Lab 4B-1
 * Class: COMSC-165
 * Date: 10/11/2018
 * Author: Tejas Shah
 * Description: Reports the type of an input character.
 */

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void determineType(char ch) {
    if (ispunct(ch))
        cout << "Punctuation" << endl;
    else if (isupper(ch))
        cout << "Upper Case" << endl;
    else if (isdigit(ch))
        cout << "Digit" << endl;
    else if (isspace(ch))
        cout << "White Space" << endl;
    else
        cout << "Unknown type" << endl;
}

int main() {
    char input;
    cout << "Enter a character: ";
    while (cin.get(input) && input != '~') {
        if (input == '\n')
            continue;
        determineType(input);
        cout << "Enter a character: ";
    }
    return 0;
}
