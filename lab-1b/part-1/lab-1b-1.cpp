/*
 * Name: Lab 1B-1
 * Class: COMSC-165
 * Author: Tejas Shah
 * Description: For 'Num' times, it prints "Loops in Action" and the value of 'Num'
 */

#include <iostream>
#include <string>

using namespace std;

int main()
{
    // make a variable called "Num" and set it to the value 3
    int Num = 3;

    // while Num is bigger than 0, keep on running
    while (Num > 0) {
        cout << "Loops in Action" << endl;
        cout << "Num: " << Num-- << endl;
    }

    return 0;
}
