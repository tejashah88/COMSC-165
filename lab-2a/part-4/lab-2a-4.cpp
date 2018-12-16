/*
 * Name: Lab 2A-4
 * Class: COMSC-165
 * Date: 9/14/2018
 * Author: Tejas Shah
 * Description: It prompts a user for their grades, finds the average and prints out the average and the corresponding letter grade.
 */

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

float GetGrades();
float FindAverage(float sum, float count);

float GetGrades() {
    float numGrades;
    cout << "How many grades do you want to input: ";
    cin >> numGrades;

    float gradeSum = 0;
    float currGrade;
    for (int i = 1; i <= numGrades; i++) {
        cout << "Grade #" << i << ": ";
        cin >> currGrade;
        gradeSum += currGrade;
    }

    return FindAverage(gradeSum, numGrades);
}

float FindAverage(float sum, float count) {
    return sum / count;
}

int main() {
    float finalGrade = GetGrades();
    char letterGrade;

    if (finalGrade >= 90 && finalGrade <= 100)
        letterGrade = 'A';
    else if (finalGrade >= 80 && finalGrade < 90)
        letterGrade = 'B';
    else if (finalGrade >= 70 && finalGrade < 80)
        letterGrade = 'C';
    else if (finalGrade >= 60 && finalGrade < 70)
        letterGrade = 'D';
    else
        letterGrade = 'F';

    cout << "Average Grade: " << setprecision(2) << fixed << finalGrade << endl;
    cout << "Letter Grade: " << letterGrade << endl;
    return 0;
}
