/*
 * Name: Lab 2A-1
 * Class: COMSC-165
 * Date: 9/14/2018
 * Author: Tejas Shah
 * Description: Prints "Learning new topics is Fun!" for 5 times using functions.
 */

#include <iostream>
#include <string>

using namespace std;

void writeThoughts() {
    cout << "Learning new topics is Fun!" << endl;
}

int main() {
    cout << "I am calling writeThoughts" << endl;
    for (int i = 0; i < 5; i++)
        writeThoughts();
    cout << "Back from writeThoughts" << endl;
    return 0;
}
