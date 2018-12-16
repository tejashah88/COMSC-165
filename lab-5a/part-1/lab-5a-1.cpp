/*
 * Name: Lab 5A-1
 * Class: COMSC-165
 * Date: 10/15/2018
 * Author: Tejas Shah
 * Description: It asks the user for their favorite day and tells if todays month matches the favorite month.
 */

#include <iostream>
#include <string>

using namespace std;

struct Date {
    int Day;
    string Month;
    int Year;
};

int readInt();
string readWord();

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

string readWord() {
    string input;
    cin >> input;
    while (cin.fail()) {
        cin.clear();
        cin.ignore();
        cin >> input;
    }

    cin.ignore();
    return input;
}

string dateToString(Date date);

string dateToString(Date date) {
    return date.Month + " " + to_string(date.Day) + ", " + to_string(date.Year);
}

int main() {
    Date today = {15, "October", 2018};
    Date favDate;

    cout << "Enter your favorite year: ";
    favDate.Year = readInt();

    cout << "Enter your favorite month: ";
    favDate.Month = readWord();

    cout << "Enter your favorite day: ";
    favDate.Day = readInt();

    cout << "Today's date: " << dateToString(today) << endl;
    cout << "Favorite date: " << dateToString(favDate) << endl;

    if (favDate.Month == today.Month)
        cout << "We are in your favorite Month!" << endl;
    else
        cout << "This is not your favorite month!" << endl;
    return 0;
}
