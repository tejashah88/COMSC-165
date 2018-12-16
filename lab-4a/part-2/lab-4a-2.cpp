/*
 * Name: Lab 4A-2
 * Class: COMSC-165
 * Date: 10/8/2018
 * Author: Tejas Shah
 * Description: A program that calculates the average, median and mode of a list of numbers passed to it.
 */

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int getNumberFromInput();
void swap_num(int *a, int *b);
int* GetValues(int numValues);
void SortValues(int* array, int size);
float CalcAverage(int* arr, int size);
float CalcMedian(int* arr, int size);
int CalcMode(int* arr, int size);

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

void swap_num(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int* GetValues(int numValues) {
    int* arr = new int[numValues];

    int currentCount = 0;
    int currentVal;
    cout << "Enter the list of values: ";
    while (currentCount < numValues) {
        currentVal = getNumberFromInput();
        if (currentVal >= 0)
            *(arr + currentCount++) = currentVal;
    }

    return arr;
}

void SortValues(int* array, int size) {
    int minIndex, minValue;
    for (int start = 0; start < (size - 1); start++) {
        minIndex = start;
        minValue = *(array + start);
        for (int index = start + 1; index < size; index++) {
            if (*(array + index) < minValue) {
                minValue = *(array + index);
                minIndex = index;
            }
        }
        swap_num((array + minIndex), (array + start));
    }
}

float CalcAverage(int* arr, int size) {
    float avg = 0.0f;
    for (int i = 0; i < size; i++)
        avg += *(arr + i);

    return avg / size;
}

float CalcMedian(int* arr, int size) {
    int middle = size / 2;
    if (size % 2 == 0){ // even size
        float sum = *(arr + (middle - 1)) + *(arr + middle);
        return sum / 2.0f;
    } else // odd size
        return *(arr + (middle));
}

int CalcMode(int* arr, int size) {
    int mode = -1;
    int maxCount = -1;
    int currentVal, currentCount;
    bool foundMultipleModes = false;
    for (int i = 0; i < size; i++) {
        currentVal = *(arr + i);
        currentCount = 0;

        for (int j = 0; j < size; j++) {
            if (*(arr + j) == currentVal)
                currentCount++;
        }

        if (maxCount < currentCount) {
            mode = currentVal;
            maxCount = currentCount;
        }

        if (maxCount == currentCount && mode != currentVal)
            foundMultipleModes = true;
    }

    return foundMultipleModes ? -1 : mode;
}

/*
Run 1: 100 75 84 25 66 200
Run 2: 3300 8800 5500 3300 8800 7700 3300
Run 3: 10 9 8 7 6 5 4 3 2 1 1 1 1 1 0
*/

int main() {

    cout << "How many numbers: ";
    int numValues = getNumberFromInput();
    while (numValues < 0) {
        cout << "Sorry, you can't have a negative amount of numbers. Try again." << endl;
        cout << "How many numbers: ";
        numValues = getNumberFromInput();
    }

    int* arr = GetValues(numValues);
    SortValues(arr, numValues);

    float average = CalcAverage(arr, numValues);
    float median = CalcMedian(arr, numValues);
    int mode = CalcMode(arr, numValues);

    cout << "Average: " << setprecision(2) << fixed << average << endl;
    cout << "Median: " << setprecision(1) << fixed << median << endl;
    cout << "Mode: " << mode << endl;

    return 0;
}
