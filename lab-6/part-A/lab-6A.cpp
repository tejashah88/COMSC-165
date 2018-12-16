/*
 * Name: Lab 6A
 * Class: COMSC-165
 * Date: 10/26/2018
 * Author: Tejas Shah
 * Description: Saves some input records of an address book into a binary and text file
 */

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

char readChar();
long int readLongInt();
string readLine();

struct AddressBook {
    string firstName;
    string lastName;
    string streetAddress;
    string city;
    string state;
    long int zip;
};

AddressBook readRecord();
bool saveToBinaryFile(string filename, AddressBook records[20]);
bool readBinaryFile(string filename, AddressBook records[20]);
bool saveToTextFile(string filename, AddressBook records[20]);

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

long int readLongInt() {
    long int input;
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

AddressBook readRecord() {
    cout << "First name: ";
    string firstName = readLine();

    cout << "Last name: ";
    string lastName = readLine();

    cout << "Street address: ";
    string address = readLine();

    cout << "City: ";
    string city = readLine();

    cout << "State: ";
    string state = readLine();

    cout << "ZIP Code: ";
    long int zipCode = readLongInt();

    return { firstName, lastName, address, city, state, zipCode };
}

// returns true if an error has occurred
bool saveToBinaryFile(string filename, AddressBook records[], int count) {
    ofstream binaryFile;

    cout << "Saving to a binary file called '" << filename << "'...";
    binaryFile.open(filename, ios::out | ios::binary);

    if (!binaryFile) {
        cout << "Unable to open the binary file!" << endl;
        return true;
    }

    for (int i = 0; i < count; i++)
        binaryFile.write(reinterpret_cast<char *>(&records[i]), sizeof(records[i]));

    binaryFile.close();

    cout << "done!" << endl;

    return false;
}

// returns true if an error has occurred
bool readBinaryFile(string filename, AddressBook records[], int count) {
    ifstream binaryFile;

    cout << "Opening a binary file called '" << filename << "'...";
    binaryFile.open(filename, ios::in | ios::binary);

    if (!binaryFile) {
        cout << "Unable to open the binary file!" << endl;
        return true;
    }

    for (int i = 0; i < count; i++)
        binaryFile.read(reinterpret_cast<char *>(&records[i]), sizeof(records[i]));

    binaryFile.close();

    cout << "done!" << endl;

    return false;
}

bool saveToTextFile(string filename, AddressBook records[], int count) {
    ofstream txtFile;

    cout << "Saving to a text file called '" << filename << "'...";
    txtFile.open(filename, ios::out);

    if (!txtFile) {
        cout << "Unable to open the text file!" << endl;
        return true;
    }

    int spacing = 45;

    for (int i = 0; i < count; i++) {
        AddressBook record = records[i];
        txtFile << "Contact #" << (i + 1) << endl;
        txtFile << "=========" << endl;
        txtFile << "First name:\t\t" << record.firstName << endl;
        txtFile << "Last name:\t\t" << record.lastName << endl;
        txtFile << "Street Address:\t\t" << record.streetAddress << endl;
        txtFile << "City:\t\t\t" << record.city << endl;
        txtFile << "State:\t\t\t" << record.state << endl;
        txtFile << "Zip Code:\t\t" << record.zip << endl;
        txtFile << endl;
    }

    txtFile.close();

    cout << "done!" << endl;

    return false;
}

int main() {
    AddressBook records[20];
    bool isDone = true;

    cout << "Input your address book records:" << endl;
    int count = 0;
    for (int i = 0; i < 20 && isDone; i++) {
        records[i] = readRecord();
        count++;
        cout << "Do you want to quit? (Y/N): ";
        if (readChar() == 'Y')
            isDone = false;
    }

    cout << endl;

    string binFilename = "records.bin";
    string txtFilename = "records.txt";

    if (saveToBinaryFile(binFilename, records, count)) {
        cout << "Unable to save records to binary file! Aborting..." << endl;
        return 1;
    }

    AddressBook readRecords[20];

    if (readBinaryFile(binFilename, readRecords, count)) {
        cout << "Unable to read records to binary file! Aborting..." << endl;
        return 1;
    }

    if (saveToTextFile(txtFilename, readRecords, count)) {
        cout << "Unable to save records to text file! Aborting..." << endl;
        return 1;
    }

    cout << "All done! Check out " << binFilename << " and " << txtFilename << endl;
    return 0;
}
