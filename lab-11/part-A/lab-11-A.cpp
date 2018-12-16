/*
 * Name: Lab 11-A
 * Class: COMSC-165
 * Date: 12/2/2018
 * Author: Tejas Shah
 * Description: A program that raises a number to a power using recursion.
 */

#include <iostream>

using namespace std;

int promptInt(string display) {
    int input;
    cout << display;
    cin >> input;
    while (cin.fail()) {
        cin.clear();
        cin.ignore();
        cin >> input;
    }

    cin.ignore();
    return input;
}

char promptChar(string display) {
    char input;
    cout << display;
    cin >> input;
    while (cin.fail()) {
        cin.clear();
        cin.ignore();
        cin >> input;
    }

    cin.ignore();
    return input;
}

int raiseByPower(int base, int exponent) {
    if (exponent == 1)
        return base;
    return base * raiseByPower(base, exponent - 1);
}

int main() {
    bool isDone = false;
    while (!isDone) {
        int base = promptInt("Enter the base number: ");
        int exponent = promptInt("Enter the exponent number: ");

        if (base > 0 && exponent > 0) {
            int result = raiseByPower(base, exponent);
            cout << "The result is " << result << endl;
        } else
            isDone = true;

        char continueResult = promptChar("Do you want to exit (Y/N): ");
        isDone = continueResult == 'Y';
    }

    return 0;
}
