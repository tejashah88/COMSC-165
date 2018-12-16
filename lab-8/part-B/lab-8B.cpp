/*
 * Name: Lab 8-B
 * Class: COMSC-165
 * Date: 11/7/2018
 * Author: Tejas Shah
 * Description: Using operator overloading to manipulate work hours/days
 */

#include <iostream>
#include <string>
#include <iomanip>

#include "NumDays.h"

using namespace std;

void printNumDayInfo(string name, const NumDays &nday) {
    cout << "Hours for " << name << ": " << nday.getHours() << endl;
    cout << "Days for " << name << ": " << nday.getDays() << endl;
}

int main() {
    NumDays day1(25), day2(15);

    printNumDayInfo("day1", day1);
    printNumDayInfo("day2", day2);

    NumDays day3 = day1 + day2;
    printNumDayInfo("day3", day3);

    NumDays day4 = day3++;
    printNumDayInfo("day4", day4);

    day4 = ++day3;
    printNumDayInfo("day4", day4);

    day4 = day3--;
    printNumDayInfo("day4", day4);

    day4 = --day3;
    printNumDayInfo("day4", day4);

    return 0;
}
