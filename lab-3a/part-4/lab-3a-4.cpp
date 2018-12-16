/*
 * Name: Lab 3A-4
 * Class: COMSC-165
 * Date: 9/21/2018
 * Author: Tejas Shah
 * Description: It prompts a user for their grades (until they enter -1), finds the average and prints out the average grade.
 */

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void GetGrades(int grades[], int &count);
float FindAverage(int grades[], int count);

void GetGrades(int grades[], int &count) {
    int currGrade;
    cout << "Enter the grade values or enter -1 to stop." << endl;

    while (cin >> currGrade && currGrade != -1)
        grades[count++] = currGrade;
}

float FindAverage(int grades[], int count) {
    int sumGrades = 0;
    for (int i = 0; i < count; i++)
        sumGrades += grades[i];

    return sumGrades / (float) count;
}

int main() {
    int GradesInput[1000];
    int GradeCount = 0;

    GetGrades(GradesInput, GradeCount);
    float average = FindAverage(GradesInput, GradeCount);

    cout << "Average Grade: " << setprecision(2) << fixed << average << endl;
    return 0;
}
