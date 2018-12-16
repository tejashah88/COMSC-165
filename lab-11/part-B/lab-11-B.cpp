/*
 * Name: Lab 11-B
 * Class: COMSC-165
 * Date: 12/2/2018
 * Author: Tejas Shah
 * Description: A program that calculates the sum of all the elements in an array using recursion
 */

#include <iostream>

using namespace std;

int recursiveSum(int arr[], int numItems) {
    if (numItems <= 0)
        return 0;
    return arr[numItems - 1] + recursiveSum(arr, numItems - 1);
}

int main() {
    int firstArray[] = { 0, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
    int firstSum = recursiveSum(firstArray, sizeof(firstArray) / sizeof(int));
    cout << "First array sum: " << firstSum << endl;

    int secondArray[] = { 50, 73, 27 };
    int secondSum = recursiveSum(secondArray, sizeof(secondArray) / sizeof(int));
    cout << "Second array sum: " << secondSum << endl;

    return 0;
}
