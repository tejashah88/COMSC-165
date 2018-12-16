/*
 * Name: Lab 5A-3
 * Class: COMSC-165
 * Date: 10/15/2018
 * Author: Tejas Shah
 * Description: Using structures to hold and compute area and paerimeter for a rectangle of a given length and width.
 */

#include <iostream>
#include <string>

using namespace std;

int readInt();
char readChar();
float readFloat();
string readWord();
string readLine();

int readInt() {
    int input;
    cin >> input;
    while (cin.fail()) {
        cin.clear();
        cin.ignore();
        cin >> input;
    }

    cin.ignore();
    return input;
}

char readChar() {
    char input;
    cin >> input;
    while (cin.fail()) {
        cin.clear();
        cin.ignore();
        cin >> input;
    }

    cin.ignore();
    return input;
}

float readFloat() {
    float input;
    cin >> input;
    while (cin.fail()) {
        cin.clear();
        cin.ignore();
        cin >> input;
    }

    cin.ignore();
    return input;
}

string readWord() {
    string input;
    cin >> input;
    while (cin.fail()) {
        cin.clear();
        cin.ignore();
        cin >> input;
    }

    cin.ignore();
    return input;
}

string readLine() {
    string input;
    getline(cin, input);
    return input;
}

struct Dimension {
    int Length, Width;
};

struct Rectangle {
    int Area, Perimeter;
    Dimension Size;
};

Dimension promptDimensions() {
    Dimension dim;

    cout << "Length of rectangle: ";
    dim.Length = readInt();

    cout << "Width of rectangle: ";
    dim.Width = readInt();

    return dim;
}

int calcArea(int length, int width) {
    return length * width;
}

int calcPerimeter(int length, int width) {
    return 2 * (length + width);
}

void printRectangleInfo(Rectangle rect) {
    cout << "Area of rectangle: " << rect.Area << endl;
    cout << "Perimeter of rectangle: " << rect.Perimeter << endl;
}

int main() {
    Rectangle rect;

    rect.Size = promptDimensions();
    rect.Area = calcArea(rect.Size.Length, rect.Size.Width);
    rect.Perimeter = calcPerimeter(rect.Size.Length, rect.Size.Width);

    printRectangleInfo(rect);

    return 0;
}
