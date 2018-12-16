/*
 * Name: Lab 1C-2
 * Class: COMSC-165
 * Date: 9/13/2018
 * Author: Tejas Shah
 * Description: It finds the average time spent programming by a student each day over a 3 day period.
 */

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    int numStudents;
    cout << "Number of students: ";
    cin >> numStudents;

    for (int currStudent = 1; currStudent <= numStudents; currStudent++) {
        cout << "Hello Student " << currStudent << endl;

        float totalHours = 0.0f;
        for (int day = 1; day <= 3; day++) {
            float hours;
            cout << "How many hours were you programming on day " << day << ": ";
            cin >> hours;
            totalHours += hours;
        }

        float avgHours = totalHours / 3.0f;
        cout << "Student " << currStudent << " has spent an average of " << setprecision(1) << avgHours << " hours." << endl;
    }

    return 0;
}
