/*
 * Name: Lab 4B-3
 * Class: COMSC-165
 * Date: 10/11/2018
 * Author: Tejas Shah
 * Description: Combines two input strings, converts to lowercase, and searches for the letter "the"
 */

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    string str1, str2;

    cout << "Enter one string: ";
    getline(cin, str1);

    cout << "Enter another string: ";
    getline(cin, str2);

    cout << endl;

    cout << "First string: " << str1 << endl;
    cout << "Second string: " << str2 << endl;

    str1.append(" " + str2);
    for (int i = 0; i < str1.length(); i++)
        str1[i] = tolower(str1[i]);

    cout << "New string: " << str1 << endl;

    if (str1.find("the") != -1)
        cout << "We found the word 'the'!" << endl;
    else
        cout << "We didn't find the word 'the'!" << endl;

    return 0;
}
