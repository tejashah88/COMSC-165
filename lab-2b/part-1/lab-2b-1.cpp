/*
 * Name: Lab 2B-1
 * Class: COMSC-165
 * Date: 9/19/2018
 * Author: Tejas Shah
 * Description: It prompts the user to enter a radius and outputs the area and circumference from it. This process continues until the user inputs -1.
 */

#include <iostream>
#include <string>

using namespace std;

const float PI = 3.14f;

float AreaOfCircle(float radius);
float CircumferenceOfCircle(float radius);

float AreaOfCircle(float radius) {
    return PI * radius * radius;
}

float CircumferenceOfCircle(float radius) {
    return 2 * PI * radius;
}

int main() {
    int radius;
    bool running = true;
    while (running) {
        cout << "Enter a radius: ";
        cin >> radius;
        if (radius == -1)
            running = false;
        else {
            cout << "Area of circle: " << AreaOfCircle(radius) << endl;
            cout << "Circumference of circle: " << CircumferenceOfCircle(radius) << endl;
        }
    }

    return 0;
}
