/*
 * Name: Lab 6B
 * Class: COMSC-165
 * Date: 10/26/2018
 * Author: Tejas Shah
 * Description: Prompts the user to read a character at the requested location in the input file until he/she is done
 */

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

int readInt();
char readChar(ifstream &file, int location);

char readChar(ifstream &file, int location) {
    if (file.eof()) {
        file.clear();
        file.ignore();
    }

    file.seekg(location, ios::cur);

    char input;
    file.get(input);

    return input;
}

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

int main() {
    ifstream file("Lab6BInputProverb.txt");
    int currentLoc = file.tellg();
    cout << "Current read location: " << currentLoc << endl << endl;

    bool isRunning = true;

    while (isRunning) {
        cout << "Ennter read location or -1 to exit: ";
        currentLoc = readInt();
        if (currentLoc < 0) {
            isRunning = false;
            continue;
        }

        cout << "Current read location: " << file.tellg() << endl;
        cout << "Character at location: '" << readChar(file, currentLoc) << "'" << endl;
        cout << "New read location: " << file.tellg() << endl << endl;
    }

    return 0;
}
