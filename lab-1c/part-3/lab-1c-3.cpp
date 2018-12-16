/*
 * Name: Lab 1C-3
 * Class: COMSC-165
 * Date: 9/132/2018
 * Author: Tejas Shah
 * Description: It reads an input file with a price and quantity in them, calculates the total bill, and writes it in a new file.
 */

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

ifstream infile;
ofstream outfile;

int main() {
    // read from input file
    infile.open("Lab1C3Input.txt");
    if (!infile) {
        cout << "Unable to open the input file!";
        return 1;
    }

    float price, quantity;
    infile >> price >> quantity;

    // we are done with the input file, so let's close it
    infile.close();

    float bill = price * quantity;

    // write to output file
    outfile.open("Bill.txt");
    if (!outfile) {
        cout << "Unable to open the output file!";
        return 1;
    }

    outfile << "Price:      $" << price << endl;
    outfile << "Quantity:    " << setprecision(2) << quantity << endl;
    outfile << "===================" << endl;
    outfile << "Total bill: $" << setprecision(2) << fixed << bill;

    outfile.close();

    return 0;
}
