/*
 * Name: Lab 2B-4
 * Class: COMSC-165
 * Date: 9/19/2018
 * Author: Tejas Shah
 * Description: It prompts a user for their grades, finds the average and prints out the average and the corresponding letter grade.
 */

#include <iostream>
#include <string>

using namespace std;

void GetGrades(int &finalGrade);
void FindAverage(int sum, int count, int &finalGrade);

void GetGrades(int &finalGrade) {
    int numGrades;
    cout << "How many grades do you want to input: ";
    cin >> numGrades;

    int gradeSum;
    int currGrade;
    for (int i = 1; i <= numGrades; i++) {
        cout << "Grade #" << i << ": ";
        cin >> currGrade;
        gradeSum += currGrade;
    }

    FindAverage(gradeSum, numGrades, finalGrade);
}

void FindAverage(int sum, int count, int &finalGrade) {
    finalGrade = sum / count;
}

int main() {
    int finalGrade;
    GetGrades(finalGrade);
    char letterGrade;

    if (finalGrade >= 90 && finalGrade <= 100)
        letterGrade = 'A';
    else if (finalGrade >= 80 && finalGrade <= 89)
        letterGrade = 'B';
    else if (finalGrade >= 70 && finalGrade <= 79)
        letterGrade = 'C';
    else if (finalGrade >= 60 && finalGrade <= 69)
        letterGrade = 'D';
    else
        letterGrade = 'F';

    cout << "Average Grade: " << finalGrade << endl;
    cout << "Letter Grade: " << letterGrade << endl;
    return 0;
}
