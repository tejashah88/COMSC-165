/*
 * Name: Lab 4B-4
 * Class: COMSC-165
 * Date: 10/11/2018
 * Author: Tejas Shah
 * Description: Compares two input strings and prints the results
 */

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    string str1, str2;

    cout << "Enter value for string 1: ";
    getline(cin, str1);

    cout << "Enter value for string 2: ";
    getline(cin, str2);

    cout << endl;

    switch (str1.compare(str2)) {
        case -1:
            cout << "String 1 comes before String 2" << endl;
            break;
        case 0:
            cout << "Equal Strings" << endl;
            break;
        case 1:
            cout << "String 1 comes after String 2" << endl;
            break;
    }

    return 0;
}
