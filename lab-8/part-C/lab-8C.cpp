/*
 * Name: Lab 8-C
 * Class: COMSC-165
 * Date: 11/7/2018
 * Author: Tejas Shah
 * Description: A program that track an employee's sick leave, vacation, and unpaid time off.
 */

#include <iostream>
#include <string>
#include <iomanip>

#include "TimeOff.h"

using namespace std;

int readInt();
string readLine();

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

string readLine() {
    string input;
    getline(cin, input);
    return input;
}

void TimeOff::printInfo() {
    cout << "Max number of sick days: " << this->maxSickDays.getDays() << endl;
    cout << "Amount of sick days you've taken: " << this->sickTaken.getDays() << endl;
    cout << "Max number of vacation days: " << this->maxVacation.getDays() << endl;
    cout << "Amount of vacation days you've taken: " << this->vacTaken.getDays() << endl;
    cout << "Max number of unpaid days: " << this->maxUnpaid.getDays() << endl;
    cout << "Amount of unpaid days: " << this->unpaidTaken.getDays() << endl;

    cout << endl;

    NumDays sickDaysLeft = this->maxSickDays - this->sickTaken;
    cout << "Number of sick days left: " << sickDaysLeft.getDays() << endl;

    NumDays vacDaysLeft = this->maxVacation - this->vacTaken;
    cout << "Number of vacation days left: " << vacDaysLeft.getDays() << endl;

    NumDays unpaidDaysLeft = this->maxUnpaid - this->unpaidTaken;
    cout << "Number of unpaid days left: " << unpaidDaysLeft.getDays() << endl;
}

int main() {
    cout << "What's your name: ";
    string name = readLine();

    cout << "What's your employee ID: ";
    int id = readInt();

    TimeOff * timeOff = new TimeOff(name, id);

    cout << "What's the max number of sick hours: ";
    NumDays maxSickDays(readInt());
    timeOff->setMaxSickDays(maxSickDays);

    cout << "What's the amount of sick hours you've taken: ";
    NumDays sickDaysTaken(readInt());
    timeOff->setSickTaken(sickDaysTaken);

    cout << "What's the max number of vacation hours: ";
    int maxVacHours = readInt();
    if (maxVacHours > 240)
        maxVacHours = 240;
    NumDays maxVacationDays(maxVacHours);
    timeOff->setMaxVacation(maxVacationDays);

    cout << "What's the amount of vacation hours you've taken: ";
    NumDays vacDaysTaken(readInt());
    timeOff->setVacTaken(vacDaysTaken);

    cout << "What's the max number of unpaid hours: ";
    NumDays maxUnpaidDays(readInt());
    timeOff->setMaxUnpaid(maxUnpaidDays);

    cout << "What's the amount of unpaid hours: ";
    NumDays unpaidHoursTaken(readInt());
    timeOff->setUnpaidTaken(unpaidHoursTaken);

    cout << endl;

    timeOff->printInfo();

    delete timeOff;

    return 0;
}
