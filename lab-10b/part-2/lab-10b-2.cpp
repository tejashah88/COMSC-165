/*
 * Name: Lab 10B-2
 * Class: COMSC-165
 * Date: 11/30/2018
 * Author: Tejas Shah
 * Description: Implementing a dynamic float queue
 */

#include <iostream>
#include "DynFloatQueue.cpp"

using namespace std;

int main() {
    const int MAX_ITEMS = 5;

    DynFloatQueue fqueue;

    float num = 1;
    for (int i = 0; i < MAX_ITEMS; i++) {
        num *= 1.1;
        fqueue.enqueue(num);
    }

    while (!fqueue.isEmpty()) {
        float tmp;
        fqueue.dequeue(tmp);
        cout << tmp << endl;
    }

    return 0;
}
