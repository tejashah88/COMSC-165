/*
 * Name: Lab 3A-2
 * Class: COMSC-165
 * Date: 9/21/2018
 * Author: Tejas Shah
 * Description: It reads a list of numbers into an array and creates another array with the elements multiplied by 2 before printing the contents of both arrays.
 */

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
    ifstream infile;

    // read from input file
    infile.open("Lab3A2Input.txt");
    if (!infile) {
        cout << "Unable to open the input file!" << endl;
        return 1;
    }

    int num, count = 0;
    const int MAX_COUNT = 10;
    int first[MAX_COUNT];

    while (infile >> num)
        first[count++] = num;

    int second[MAX_COUNT];
    for (int i = 0; i < MAX_COUNT; i++)
        second[i] = first[i] * 2;

    for (int i = 0; i < MAX_COUNT; i++)
        cout << first[i] << (i != MAX_COUNT - 1 ? ", " : "");

    cout << endl;

    for (int i = 0; i < MAX_COUNT; i++)
        cout << second[i] << (i != MAX_COUNT - 1 ? ", " : "");

    return 0;
}
