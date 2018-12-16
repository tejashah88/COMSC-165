/*
 * Name: Lab 2A-3
 * Class: COMSC-165
 * Date: 9/14/2018
 * Author: Tejas Shah
 * Description: Calculates the net pay for each worker by reading a file and outputs the results on screen and on another file
 */

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

ifstream infile;
ofstream outfile;

float CalNetPay(int hoursWorked, float hourlyPay);

float CalNetPay(int hoursWorked, float hourlyPay) {
    return hoursWorked * hourlyPay;
}

int main() {
    // read from input file
    infile.open("Lab2A3Input.txt");
    if (!infile) {
        cout << "Unable to open the input file!" << endl;
        return 1;
    }

    // write to output file
    outfile.open("Lab2A3Output.txt");
    if (!outfile) {
        cout << "Unable to open the output file!" << endl;
        return 1;
    }

    int hoursWorked;
    float hourlyPay;
    while (infile >> hoursWorked >> hourlyPay) {
        float netPay = CalNetPay(hoursWorked, hourlyPay);
        cout << "Net pay: " << netPay << endl;
        outfile << "Net pay: " << netPay << endl;
    }

    // we are done with the files, so let's close it
    infile.close();
    outfile.close();

    return 0;
}
