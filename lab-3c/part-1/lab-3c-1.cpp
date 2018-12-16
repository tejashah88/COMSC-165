/*
 * Name: Lab 3C-1
 * Class: COMSC-165
 * Date: 9/30/2018
 * Author: Tejas Shah
 * Description: A program that utilizes various vector member functions.
 */

#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> ages = {16, 18, 30, 45, 56, 60};

    for (int age : ages)
        cout << age << " ";
    cout << endl;

    auto iter = ages.begin() + 2;
    ages.insert(iter, 25);

    for (iter = ages.begin(); iter < ages.end(); iter++)
        cout << *iter << " ";
    cout << endl;
    return 0;
}
