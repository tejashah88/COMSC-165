/*
 * Name: Lab 7B-1
 * Class: COMSC-165
 * Date: 11/1/2018
 * Author: Tejas Shah
 * Description: Expand on the Square class by adding constructors/destructors
 */

#include <iostream>
#include "Square.h"

using namespace std;

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

int main()
{
    // PART 1
	Square box;	// box is defined as an object of the Square class
	float size;	// size contains the length of a side of the square

    cout << "Please input the length of the side of the square: ";
    size = readFloat();
    box.setSide(size);

    cout << "The area of the square is " << box.findArea() << endl;
    cout << "The area of the square is " << box.findPerimeter() << endl;

    // PART 2
    Square box1(9);
    cout << "The area of box1 is " << box1.findArea() << endl;
    cout << "The area of box1 is " << box1.findPerimeter() << endl;

	return 0;
}

// _______________________________________________________
//
// Implementation section	Member function implementation

//**************************************************
//  setSide
//
//  task:	 This procedure takes the length of a side and
//	         places it in the appropriate member data
//  data in: length of a side
//***************************************************

void Square::setSide(float length)
{
	side = length;
}

//**************************************************
//	findArea
//
//  task:	       This finds the area of a square
//  data in:       none (uses value of data member side)
//  data returned: area of square
//***************************************************

float Square::findArea()
{
	return side * side;
}

//**************************************************
//	findPerimeter
//
//  task:	       This finds the perimeter of a square
//  data in:       none (uses value of data member side)
//  data returned: perimeter of square
//***************************************************

float Square::findPerimeter()
{
	return 4 * side;
}
