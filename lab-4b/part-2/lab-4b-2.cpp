/*
 * Name: Lab 4B-2
 * Class: COMSC-165
 * Date: 10/11/2018
 * Author: Tejas Shah
 * Description: Prompts the user for their name and 2 numbers to multiply.
 */

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

float getFloatFromInput() {
    float input;
    cin >> input;
    while (cin.fail()) {
        cin.clear();
        cin.ignore();
        cin >> input;
    }
    return input;
}

int main() {
    string name, num1, num2;
    cout << "What's your name: ";
    getline(cin, name);
    cout << "Enter one number: ";
    getline(cin, num1);
    cout << "Enter another number: ";
    getline(cin, num2);

    cout << endl;

    float result = stof(num1) * stof(num2);
    cout << "Your name is " + name << endl;
    cout << "The product of the 2 input numbers is " << setprecision(3) << fixed << result << endl;

    return 0;
}
