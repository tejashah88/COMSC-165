/*
 * Name: Lab 6-4
 * Class: COMSC-165
 * Date: 10/26/2018
 * Author: Tejas Shah
 * Description: Reads a joke and punchline from 2 files and prints them to the screen.
 */

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

string readLine();
bool readLinesFromFront(string filename);
bool readLinesFromBack(string filename);

string readLine() {
    string input;
    getline(cin, input);
    return input;
}

// returns true if an error has occurred
bool readLinesFromFront(string filename) {
    fstream txtFile;
    txtFile.open(filename, ios::in);

    if (!txtFile) {
        cout << "Unable to open the text file!" << endl;
        return true;
    }

    for (string line; getline(txtFile, line);)
        cout << line << endl;

    txtFile.close();

    return false;
}

bool readLinesFromBack(string filename) {
    fstream txtFile;
    string punchline = "";

    txtFile.open(filename, ios::in);

    if (!txtFile) {
        cout << "Unable to open the text file!" << endl;
        return true;
    }

    int offset = 0;
    char ch;
    txtFile.seekg(--offset, ios::end);

    while (txtFile.get(ch) && ch != '\n') {
        punchline = ch + punchline;
        txtFile.seekg(--offset, ios::end);
    }

    cout << punchline << endl;

    txtFile.close();

    return false;
}

int main() {
    string jokeFilename = "COMSC165Lab6Djoke.txt";
    string punchlineFilename =  "COMSC165Lab6Dpunchline.txt";

    if (readLinesFromFront(jokeFilename)) {
        cout << "Unable to read joke file '" << jokeFilename << "'\n";
        return 1;
    }

    if (readLinesFromBack(punchlineFilename)) {
        cout << "Unable to read punchline file '" << punchlineFilename << "'\n";
        return 1;
    }

    return 0;
}
