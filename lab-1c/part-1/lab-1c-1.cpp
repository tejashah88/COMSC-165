/*
 * Name: Lab 1C-1
 * Class: COMSC-165
 * Date: 9/13/2018
 * Author: Tejas Shah
 * Description: It prompts the user 5 times for an integer and outputs the average from those numbers.
 */

#include <iostream>
#include <string>

using namespace std;

int main() {
    int sum = 0;
    cout << "Enter 5 numbers" << endl;
    for (int i = 1; i <= 5; i++) {
        int input;
        cout << "Number #" << i << ": ";
        cin >> input;
        sum += input;
    }

    float average = (float) sum / 5.0f;
    cout << "Average of all 5 numbers: " << average;

    return 0;
}
