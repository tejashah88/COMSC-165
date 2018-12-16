/*
 * Name: Lab 2A-2
 * Class: COMSC-165
 * Date: 9/14/2018
 * Author: Tejas Shah
 * Description: A program that prompts the user for 2 numbers, finds the sum and difference for those numbers and displays a descriptive label for each computation.
 */

#include <iostream>
#include <string>

using namespace std;

void SumLabel(int sum);
void DifferenceLabel(int diff);

void SumLabel(int sum) {
    cout << "This is the Sum: " << sum << endl;
}
void DifferenceLabel(int diff) {
    cout << "This is the Difference: " << diff << endl;
}

int main() {
    int num1, num2;

    cout << "Enter number 1: ";
    cin >> num1;

    cout << "Enter number 2: ";
    cin >> num2;

    int sum = num1 + num2;
    int diff = num1 - num2;

    SumLabel(sum);
    DifferenceLabel(diff);

    return 0;
}
