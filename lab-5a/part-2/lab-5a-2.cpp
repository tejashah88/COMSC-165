/*
 * Name: Lab 5A-2
 * Class: COMSC-165
 * Date: 10/15/2018
 * Author: Tejas Shah
 * Description: It stores and prints personal tax information using structures.
 */

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct PersonalTaxes {
    string Name;
    float AnnualSalary;
    float TaxRate;
    float TaxesOwed;
};

float readFloat();
string readLine();
void printPersonalTaxInfo(const PersonalTaxes &taxes);

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

string readLine() {
    string input;
    getline(cin, input);
    return input;
}

void printPersonalTaxInfo(const PersonalTaxes &taxes) {
    cout << "Name\t\tAnnual Salary\tTax Rate\tTaxes Owned" << endl;
    cout << taxes.Name << "\t$" << setprecision(2) << fixed << taxes.AnnualSalary << "\t";
    cout << taxes.TaxRate << "%\t\t$" << setprecision(2) << fixed << taxes.TaxesOwed << endl;
}

int main() {
    const int MAX_PEOPLE = 3;
    PersonalTaxes taxes[MAX_PEOPLE];
    for (int i = 1; i <= MAX_PEOPLE; i++) {
        PersonalTaxes tmpInfo;
        cout << "Person #" << i << endl;

        cout << "What is your name: ";
        tmpInfo.Name = readLine();

        cout << "What is your annual salary: ";
        tmpInfo.AnnualSalary = readFloat();

        cout << "What is your tax rate: ";
        tmpInfo.TaxRate = readFloat();

        tmpInfo.TaxesOwed = tmpInfo.AnnualSalary * tmpInfo.TaxRate;
        taxes[i - 1] = tmpInfo;

        cout << endl;
    }

    for (PersonalTaxes tax : taxes) {
        printPersonalTaxInfo(tax);
        cout << endl;
    }

    return 0;
}
