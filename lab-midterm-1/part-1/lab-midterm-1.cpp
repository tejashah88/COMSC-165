/*
 * Name: Question 51
 * Class: COMSC-165
 * Date: 10/19/2018
 * Author: Tejas Shah
 */

#include <iostream>
#include <string>
#include <iomanip>

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

struct Address {
    string Street;
    string City;
    string State;
    int ZipCode;
};

struct LoginInfo {
    string LoginName;
    string Password;
    string PasswordHint;
};

struct PayrollInfo {
    float HourlyRate;
    float HoursWorkedPerWeek;
    float MonthlySalary;
};

struct EmployeeRecord {
    int EmployeeID;
    string FirstName;
    string LastName;
    Address CurrentAddress;
    LoginInfo Security;
    PayrollInfo Salary;
};

void populateAddress(Address &address) {
    /*string Street;
    string City;
    string State;
    int ZipCode;*/
    cout << "  Enter street: ";
    address.Street = readLine();

    cout << "  Enter city: ";
    address.City = readLine();

    cout << "  Enter state: ";
    address.State = readWord();

    cout << "  Enter zip code: ";
    address.ZipCode = readInt();
}

void populateLoginInfo(LoginInfo &linfo) {
    /*
    string LoginName;
    string Password;
    string PasswordHint;
    */

    cout << "  Enter name: ";
    linfo.LoginName = readLine();

    // TODO: validate it!!
    // The function should validate the password entered: The only characters acceptable for a password
    // are Lower Case and Digits, if the user enters any other type of characters the program should display
    // an error message and give the user the ability to enter another character.

    cout << "  Enter password (character by character). Type '~' (without quotes) when you are done." << endl;
    bool isReadingPass = true;
    string pass = "";
    char input;
    while (isReadingPass) {
        cout << "    > ";
        input = readChar();
        if (input == '~')
            isReadingPass = false;
        else if (islower(input) || isdigit(input))
            pass += input;
        else
            cout << "    Invalid character detected! Try a different one." << endl;
    }
    linfo.Password = pass;

    cout << "  Enter password hint: ";
    linfo.PasswordHint = readLine();
}

void populatePayrollInfo(PayrollInfo &pinfo) {
    /*
    float HourlyRate;
    float HoursWorkedPerWeek;
    float MonthlySalary;
    */

    cout << "  Enter hourly rate: ";
    pinfo.HourlyRate = readFloat();

    cout << "  Enter hours worked per week: ";
    float hourlyWorkRate = readFloat();
    while (hourlyWorkRate > 40) {
        cout << "    You cannot put more than 40 hours per week. Please try again." << endl;
        cout << "  Enter hours worked per week: ";
        hourlyWorkRate = readFloat();
    }
    pinfo.HoursWorkedPerWeek = hourlyWorkRate;

    pinfo.MonthlySalary = pinfo.HourlyRate * pinfo.HoursWorkedPerWeek * 4;
}

void populateEmployeeRecord(EmployeeRecord &record) {
    /*
    int EmployeeID;
    string FirstName;
    string LastName;
    */
    cout << "Enter employee ID: ";
    record.EmployeeID = readInt();

    cout << "Enter first name: ";
    record.FirstName = readWord();

    cout << "Enter last name: ";
    record.LastName = readWord();

    cout << "Asking for address info: " << endl;
    populateAddress(record.CurrentAddress);

    cout << "Asking for login info: " << endl;
    populateLoginInfo(record.Security);

    cout << "Asking for payroll info: " << endl;
    populatePayrollInfo(record.Salary);

    cout << endl;
}

void printEmployeeRecord(const EmployeeRecord &record) {
    cout << "Employee ID: " << record.EmployeeID << endl;
    cout << "First name: " << record.FirstName << endl;
    cout << "Last name: " << record.LastName << endl;

    cout << "Address info: " << endl;
    cout << "  Street: " << record.CurrentAddress.Street << endl;
    cout << "  City: " << record.CurrentAddress.City << endl;
    cout << "  State: " << record.CurrentAddress.State << endl;
    cout << "  Zip Code: " << record.CurrentAddress.ZipCode << endl;
    cout << endl;

    cout << "Login info: " << endl;
    cout << "  Login Name: " << record.Security.LoginName << endl;
    cout << "  Password: " << record.Security.Password << endl;
    cout << "  Password Hint: " << record.Security.PasswordHint << endl;
    cout << endl;

    cout << "Payroll info: " << endl;
    cout << "  Hourly Rate: $" << record.Salary.HourlyRate << endl;
    cout << "  Hourly Worked Per Week: " << record.Salary.HoursWorkedPerWeek << endl;
    cout << "  Monthly Salary: $" << record.Salary.MonthlySalary << endl;
    cout << endl;
    cout << endl;
}

int main() {
    const int NUM_EMPLOYEES = 3;
    EmployeeRecord records[NUM_EMPLOYEES];

    for (int i = 0; i < NUM_EMPLOYEES; i++)
        populateEmployeeRecord(records[i]);

    cout << endl;

    for (int i = 0; i < NUM_EMPLOYEES; i++)
        printEmployeeRecord(records[i]);

    return 0;
}
