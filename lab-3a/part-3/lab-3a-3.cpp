/*
 * Name: Lab 3A-3
 * Class: COMSC-165
 * Date: 9/21/2018
 * Author: Tejas Shah
 * Description: It takes the ages of 5 workers and prints the average on the screen.
 */

#include <iostream>
#include <string>

using namespace std;

void PrintAverageAge(int arr[], int numAges);

void PrintAverageAge(int arr[], int numAges) {
    int sumAges = 0;
    for (int i = 0; i < numAges; i++)
        sumAges += arr[i];

    cout << "Average age: " << (sumAges / numAges) << endl;
}

int main() {
    const int MAX_AGES = 5;
    int ages[5];
    int currAge;
    for (int i = 1; i <= MAX_AGES ; i++) {
        cout << "Age of worker #" << i << ": ";
        cin >> currAge;
        ages[i - 1] = currAge;
    }

    PrintAverageAge(ages, MAX_AGES);

    return 0;
}
