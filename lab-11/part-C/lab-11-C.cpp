/*
 * Name: Lab 11-C
 * Class: COMSC-165
 * Date: 12/2/2018
 * Author: Tejas Shah
 * Description: Extending on the NumberList class to recursively calculate the max node.
 */

#include <iostream>
#include "NumberList.cpp"

using namespace std;

int main() {
    double arr[] = { 10.0, 20.0, 50.0, 110.0, 340.0, 672.0, 25.0, 1.0, 89.0, 214.0 };
    NumberList lst;

    for (double num : arr)
        lst.appendNode(num);

    double maxNumber = lst.maxNode();
    cout << "The max number in the list is " << maxNumber << endl;
    return 0;
}
