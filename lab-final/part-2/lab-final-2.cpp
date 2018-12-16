/*
 * Name: Lab FINAL-2
 * Class: COMSC-165
 * Date: 12/12/2018
 * Author: Tejas Shah
 */

#include <iostream>
#include "DynDoubleStack.cpp"

using namespace std;

int main() {
    DynDoubleStack stack;

    stack.push(2.5);
    stack.push(3.5);
    stack.push(4.5);
    stack.push(5.5);

    double tmp;
    for (int i = 0; i < 4; i++) {
        stack.pop(tmp);
        cout << tmp << endl;
    }

    stack.pop(tmp);
    return 0;
}
