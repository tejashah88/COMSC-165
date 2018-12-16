/*
 * Name: Lab 6-3
 * Class: COMSC-165
 * Date: 10/26/2018
 * Author: Tejas Shah
 * Description: Reads the first 10 lines of a given file
 */

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

const int MAX_LINES = 10;

string readLine() {
    string input;
    getline(cin, input);
    return input;
}

// COMSC165Lab6C.rtf
int main() {
    cout << "Enter file name: ";
    string filename = readLine();

    ifstream txtFile;

    cout << "Opening a text file called '" << filename << "'...";
    txtFile.open(filename, ios::in);
    cout << "done!" << endl;

    if (!txtFile) {
        cout << "Unable to open the text file!" << endl;
        return true;
    }

    int newlineCount = 0;
    char ch;
    bool cycledOnce = false;

    txtFile.seekg(-1, ios::end);
    while (newlineCount < 10 && !cycledOnce) {
        if (txtFile.tellg() == 0)
            cycledOnce = true;

        txtFile.get(ch);
        txtFile.seekg(-2L, ios::cur);

        if (ch == '\n')
            newlineCount++;
    }

    string text = "";

    // skip the newline
    txtFile.seekg(2L, ios::cur);

    while (txtFile.tellg() != -1L) {
        char ch;
        txtFile.get(ch);
        if (!txtFile.eof()) {
            text += ch;
            if (ch == '\n') // for readability sake
                text += '\n';
        }
    }

    cout << endl << text << endl << endl;

    if (cycledOnce)
        cout << "Entire file is being displayed." << endl;

    txtFile.close();

    return 0;
}
