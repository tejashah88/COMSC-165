/*
 * Name: Lab 2B-3
 * Class: COMSC-165
 * Date: 9/19/2018
 * Author: Tejas Shah
 * Description: It calculates the miles per hour for every mile and hour pair given, until it receives -1 in either inputs.
 */

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void mphCalc(float miles, float hours, float &milesPerHour);

void mphCalc(float miles, float hours, float &milesPerHour) {
    milesPerHour = miles / hours;
}

int main() {
    float miles, hours, mph;
    bool running = true;
    while (running) {
        cout << "Enter the amount of miles: ";
        cin >> miles;
        if (miles == -1) {
            running = false;
        } else {
            cout << "Enter the amount of hours: ";
            cin >> hours;
            if (hours == -1) {
                running = false;
            } else {
                mphCalc(miles, hours, mph);
                cout << "MPH: " << setprecision(2) << fixed << mph << endl;
            }
        }
    }

    return 0;
}
