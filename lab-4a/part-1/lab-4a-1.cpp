/*
 * Name: Lab 4A-1
 * Class: COMSC-165
 * Date: 10/8/2018
 * Author: Tejas Shah
 * Description: Create a list that is double the size of the original list a user provides.
 */

#include <iostream>
#include <string>

using namespace std;

int getNumberFromInput() {
    int input;
    cin >> input;
    while (cin.fail()) {
        cin.clear();
        cin.ignore();
        cin >> input;
    }
    return input;
}

int* doubleArray(int* oldArr, int size) {
    int* newArr = new int[size * 2];
    for (int i = 0; i < size; i++)
        *(newArr + i) = *(oldArr + i);
    for (int j = size; j < size * 2; j++)
        *(newArr + j) = -1;
    return newArr;
}

void printArray(int* array, int size) {
    for (int i = 0; i < size; i++)
        cout << *(array + i) << " ";
    cout << endl;
}

int main() {
    cout << "How many numbers: ";
    int numValues = getNumberFromInput();
    while (numValues <= 0) {
        cout << "Sorry, you can't have a negative amount of numbers. Try again." << endl;
        cout << "How many numbers: ";
        numValues = getNumberFromInput();
    }

    int* oldArr = new int[numValues];

    int currentCount = 0;
    int currentVal;
    cout << "Enter the list of values: ";
    while (currentCount < numValues) {
        currentVal = getNumberFromInput();
        if (currentVal > 0)
            *(oldArr + currentCount++) = currentVal;
    }

    int* newArr = doubleArray(oldArr, numValues);

    cout << "Old Array: ";
    printArray(oldArr, numValues);
    cout << "New Array: ";
    printArray(newArr, numValues * 2);

    return 0;
}
