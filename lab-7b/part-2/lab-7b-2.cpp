/*
 * Name: Lab 7B-2
 * Class: COMSC-165
 * Date: 11/1/2018
 * Author: Tejas Shah
 * Description: A program that manages students' grades with classes.
 */

#include <iostream>
#include <string>

#include "StudentGrades.h"

using namespace std;

int readInt();

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

void StudentGrades::printGrades() {
    cout << "Grades: " << grade1 << " " << grade2 << " " << grade3 << " " << grade4 << endl;
}

int main() {
    int input[4];
    for (int i = 1; i <= 4; i++) {
        cout << "Enter grade #" << i << ": ";
        input[i - 1] = readInt();
    }

    cout << endl;

    StudentGrades studentGrades(input[0], input[1], input[2], input[3]);
    studentGrades.printGrades();
    cout << "Average grades: " << studentGrades.getAverageGrade();

    return 0;
}
