/*
 * Name: Lab 10B-1
 * Class: COMSC-165
 * Date: 11/30/2018
 * Author: Tejas Shah
 * Description: Implementing a dynamic string stack
 */

#include <iostream>
#include "DynStringStack.cpp"

using namespace std;

int main() {
    DynStringStack stack;

    stack.push("one");
    stack.push("two");
    stack.push("three");

    string tmp;
    for (int i = 0; i < 3; i++) {
        stack.pop(tmp);
        cout << tmp << endl;
    }

    stack.pop(tmp);

    return 0;
}
