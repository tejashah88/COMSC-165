/*
 * Name: Lab 3D-1
 * Class: COMSC-165
 * Date: 10/5/2018
 * Author: Tejas Shah
 * Description: Performs a linear and binary search on an array given a target number, and prints where it's located and the number of comparisions.
 */

#include <iostream>
#include <string>

using namespace std;

int getNumberFromInput();
int linearSearch(const int arr[], const int size, int value, int &position);
int binarySearch(const int arr[], const int size, int value, int &position);

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

int linearSearch(const int arr[], const int size, int value, int &position) {
    int index = 0;      // Used as a subscript to search the array
    position = -1;      // To record the position of search value
    bool found = false; // Flag to indicate if value was found

    int comparisons = 0;

    while (index < size && !found) {
        comparisons++;
        if (arr[index] == value) { // If the value is found
            found = true; // Set the flag
            position = index; // Record the value's subscript
        }

        index++; // Go to the next element
    }

    return comparisons; // Return the position, or -1
}

int binarySearch(const int arr[], const int size, int value, int &position) {
    int first = 0,             // First array element
        last = size - 1,       // Last array element
        middle;                // Mid point of search
    position = -1;             // Position of search value
    bool found = false;        // Flag

    int comparisons = 0;

    while (!found && first <= last) {
        middle = (first + last) / 2;        // Calculate mid point
        comparisons++;
        if (arr[middle] == value) {       // If value is found at mid
            found = true;
            position = middle;
        } else if (arr[middle] > value)   // If value is in lower half
            last = middle - 1;
        else
            first = middle + 1;             // If value is in upper half
    }

    return comparisons;
}

int main() {
    const int arr[] = {
        101, 142, 147, 189, 199,
        207, 222, 234, 289, 296,
        310, 319, 388, 394, 417,
        429, 447, 521, 536, 600
    };

    const int ARR_SIZE = 20;

    cout << "Enter a number to search: ";
    int target = getNumberFromInput();

    cout << "Linear search results:" << endl;
    int linear_position;
    int linear_comparisions = linearSearch(arr, ARR_SIZE, target, linear_position);
    if (linear_position == -1)
        cout << "  Target not found!" << endl;
    else
        cout << "  Target found at position " << linear_position << endl;
    cout << "  Number of comparisions: " << linear_comparisions << endl;

    cout << endl;

    cout << "Binary search results:" << endl;
    int binary_position;
    int binary_comparisions = binarySearch(arr, ARR_SIZE, target, binary_position);
    if (binary_position == -1)
        cout << "  Target not found!" << endl;
    else
        cout << "  Target found at position " << binary_position << endl;
    cout << "  Number of comparisions: " << binary_comparisions << endl;

    return 0;
}
