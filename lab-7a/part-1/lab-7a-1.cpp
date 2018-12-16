/*
 * Name: Lab 7A-1
 * Class: COMSC-165
 * Date: 10/30/2018
 * Author: Tejas Shah
 * Description: A program that can calculate the area of a circle using classes.
 */

#include <iostream>
#include <string>
#include <iomanip>

#include "Circle.h"

using namespace std;

int main() {
    Circle unitCircle;
    unitCircle.setRadius(1);
    cout << "Unit circle:" << endl;
    cout << "  Radius: " << unitCircle.getRadius() << endl;
    cout << "  Area: " << unitCircle.getArea() << endl;

    Circle largeCircle;
    largeCircle.setRadius(20);
    cout << "Large circle:" << endl;
    cout << "  Radius: " << largeCircle.getRadius() << endl;
    cout << "  Area: " << largeCircle.getArea() << endl;

    return 0;
}
