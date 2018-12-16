/*
 * Name: Lab 2B-2
 * Class: COMSC-165
 * Date: 9/19/2018
 * Author: Tejas Shah
 * Description: A program that takes cents as an integer and converts it to dollars and cents.
 */

#include <iostream>
#include <string>

using namespace std;

float NormalizeMoney(int cents);

float NormalizeMoney(int cents) {
    static int sum;
    float dollars = 0;

    while (cents >= 100) {
        dollars++;
        cents -= 100;
        sum += 100;
    }

    dollars += (float) cents / 100.0f;
    sum += cents;

    cout << "Cents received: " << sum << endl;

    return dollars;
}

int main() {
    int cents;
    bool running = true;
    while (running) {
        cout << "Enter the amount of cents you have: ";
        cin >> cents;
        if (cents == -1)
            running = false;
        else {
            cout << "Dollar equivalent: $" << NormalizeMoney(cents) << endl;
        }
    }

    return 0;
}
