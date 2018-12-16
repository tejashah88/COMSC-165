/*
 * Name: Lab 8-A
 * Class: COMSC-165
 * Date: 11/7/2018
 * Author: Tejas Shah
 * Description: Converts a day in a year into its canonical form
 */

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class NumberToDate {
    public:
        NumberToDate(int _day) : day(_day) {};
        void print();
        const static string months[];
        const static int daysInMonth[];

    private:
        int day;
};

const string NumberToDate::months[] = {
    "January", "February", "March",
    "April", "May", "June",
    "July", "August", "September",
    "October", "November", "December"
};

const int NumberToDate::daysInMonth[] = {
    31, 28, 31,
    30, 31, 30,
    31, 31, 30,
    31, 30, 31
};

void NumberToDate::print() {
    int monthIndex = 0;
    int countedDays = 0;
    while (NumberToDate::daysInMonth[monthIndex] < (day - countedDays)) {
        countedDays += NumberToDate::daysInMonth[monthIndex];
        monthIndex++;
    }

    cout << "  " << NumberToDate::months[monthIndex] << " " << (day - countedDays) << endl;
}

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

int main() {
    cout << "Enter a day number to convert into it's canonical form or -1 to exit:" << endl;

    bool done = false;
    int input;
    NumberToDate * num2date;
    while (!done) {
        cout << "> ";
        input = readInt();
        if (input == -1)
            done = true;
        else if (input < 1 || input > 365) // invalid day
            cout << "Invalid day given!" << endl;
        else {
            num2date = new NumberToDate(input);
            num2date->print();
            delete num2date;
        }
    }

    return 0;
}
