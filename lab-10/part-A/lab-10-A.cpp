/*
 * Name: Lab 10-A
 * Class: COMSC-165
 * Date: 11/14/2018
 * Author: Tejas Shah
 * Description: Practicing inheritance with Customer Data
 */

#include <iostream>
#include <string>
#include <iomanip>

#include "CustomerData.h"

using namespace std;

bool promptBool(string prompt);
int promptInt(string prompt);
string promptWord(string prompt);
string promptLine(string prompt);

bool promptBool(string prompt) {
    cout << prompt;

    bool input;
    cin >> input;
    while (cin.fail()) {
        cin.clear();
        cin.ignore();
        cin >> input;
    }

    cin.ignore();
    return input;
}

int promptInt(string prompt) {
    cout << prompt;

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

string promptWord(string prompt) {
    cout << prompt;

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

string promptLine(string prompt) {
    cout << prompt;

    string input;
    getline(cin, input);
    return input;
}

void displayCustomer(CustomerData * data) {
    cout << "First name: " << data->getFirstName() << endl;
    cout << "Last name: " << data->getLastName() << endl;
    cout << "Address: " << data->getAddress() << endl;
    cout << "City: " << data->getCity() << endl;
    cout << "State: " << data->getState() << endl;
    cout << "Zip: " << data->getZip() << endl;

    cout << "Customer Number: " << data->getCustomerNumber() << endl;
    cout << "Mailing List: " << data->getMailingList() << endl;
    cout << endl;
}

CustomerData* promptCustomerData() {
    CustomerData * userData = new CustomerData();

    userData->setFirstName(promptWord("What is your first name: "));
    userData->setLastName(promptWord("What is your last name: "));
    userData->setAddress(promptLine("What is your address: "));
    userData->setCity(promptWord("Which city do you live in: "));
    userData->setState(promptWord("Which state do you live in: "));
    userData->setZip(promptWord("What's your zip code: "));

    userData->setCustomerNumber(promptInt("What is your phone number: "));

    bool isOnMailingList = promptWord("Are you on the mailing list: ") == "true";
    userData->setMailingList(isOnMailingList);

    cout << endl;
    return userData;
}

int main() {
    CustomerData * customer = new CustomerData("Smith", "Joan", "123 Main Street", "Smithville", "NC", "99999", 12345, true);
    displayCustomer(customer);
    delete customer;

    CustomerData * user = promptCustomerData();
    displayCustomer(user);
    delete user;

    return 0;
}
