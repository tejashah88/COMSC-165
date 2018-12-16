/*
 * Name: Lab 3A-1
 * Class: COMSC-165
 * Date: 9/21/2018
 * Author: Tejas Shah
 * Description: Compares 2 arrays of their elements are equal or not.
 */

#include <iostream>
#include <string>

using namespace std;

int main() {
    const int MAX_SIZE = 4;
    int arr1[] = {5, 15, 25, 30};
    int arr2[] = {2, 15, 20, 30};

    bool eq;
    for (int i = 0; i < MAX_SIZE; i++) {
        eq = arr1[i] != arr2[i];
        cout << (eq ? "equal" : "not equal") << endl;
    }

    return 0;
}
