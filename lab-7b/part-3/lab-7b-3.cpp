/*
 * Name: Lab 7B-3
 * Class: COMSC-165
 * Date: 11/1/2018
 * Author: Tejas Shah
 * Description: A program that does basic statistics on an array of numbers.
 */

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>

#include "ArrayStats.h"

using namespace std;

int readInt();
float readFloat();

int readInt() {
    int input;
    cin >> input;
    while (cin.fail()) {
        cin.clear();
        cin.ignore();
        cin >> input;
    }

    cin.ignore();
    return input;
}

float readFloat() {
    float input;
    cin >> input;
    while (cin.fail()) {
        cin.clear();
        cin.ignore();
        cin >> input;
    }

    cin.ignore();
    return input;
}

ArrayStats::ArrayStats(int _size) {
    size = _size;
    numbers = new float[size];
};

float ArrayStats::getMax() const {
    float maxVal = numbers[0];

    for (int i = 0; i < size; i++) {
        if (numbers[i] > maxVal)
            maxVal = numbers[i];
    }

    return maxVal;
}

float ArrayStats::getMin() const {
    float minVal = numbers[0];

    for (int i = 0; i < size; i++) {
        if (numbers[i] < minVal)
            minVal = numbers[i];
    }

    return minVal;
}

float ArrayStats::getAverage() const {
    float sum = 0;
    for (int i = 0; i < size; i++)
        sum += numbers[i];
    return sum / size;
}

int main() {
    cout << "Enter the amount of numbers to input: ";
    int size = readInt();

    ArrayStats stats(size);
    cout << "Enter numbers below, delimited by a space. Press enter when you are done: " << endl;
    for (int i = 0; i < size; i++) {
        float num = readFloat();
        stats.setNumber(num, i);
    }

    cout << "Numbers: ";
    for (int i = 0; i < size; i++)
        cout << stats.getNumber(i) << " ";
    cout << endl;

    cout << "Average of numbers: " << stats.getAverage() << endl;
    cout << "Biggest number: " << stats.getMax() << endl;
    cout << "Smallest number: " << stats.getMin() << endl;
    return 0;
}
