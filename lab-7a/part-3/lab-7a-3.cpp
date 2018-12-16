/*
 * Name: Lab 7A-3
 * Class: COMSC-165
 * Date: 10/30/2018
 * Author: Tejas Shah
 * Description: A program to manage your savings account.
 */

#include <iostream>
#include <string>
#include <iomanip>

#include "SavingsAccount.h"

using namespace std;

int readInt();
char readChar();

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

void SavingsAccount::normalizeValues() {
    while (cents < 0) {
        dollars--;
        cents += 100;
    };

    while (cents >= 100) {
        cents -= 100;
        dollars++;
        return;
    }
}

void SavingsAccount::open(int d, int c) {
    dollars = d;
    cents = c;

    normalizeValues();
}

void SavingsAccount::deposit(int d, int c) {
    dollars += d;
    cents += c;

    normalizeValues();
}

void SavingsAccount::withdraw(int d, int c) {
    dollars -= d;
    cents -= c;

    normalizeValues();
}

void SavingsAccount::showBalance() {
    // append a zero if necessary
    string displayCents = (cents < 10 ? "0" : "") + to_string(cents);
    cout << "Your current balance is: $" << dollars << "." << displayCents << endl;
};

void askInitialBalance(SavingsAccount &account) {
    int inputDollars, inputCents;

    cout << "Please input the initial dollars: ";
    inputDollars = readInt();
    cout << "Please input the initial cents: ";
    inputCents = readInt();

    account.open(inputDollars, inputCents);
}

void askForDeposit(SavingsAccount &account) {
    int inputDollars, inputCents;

    cout << "Please input the dollars to be deposited: ";
    inputDollars = readInt();
    cout << "Please input the cents to be deposited: ";
    inputCents = readInt();

    account.deposit(inputDollars, inputCents);
}

void askForWithdrawal(SavingsAccount &account) {
    int inputDollars, inputCents;

    cout << "Please input the dollars to be withdrawn: ";
    inputDollars = readInt();
    cout << "Please input the cents to be withdrawn: ";
    inputCents = readInt();

    account.withdraw(inputDollars, inputCents);
}

void runPart1() {
    SavingsAccount bank1;
    bank1.open(200, 50);
    bank1.showBalance();

    bank1.deposit(40, 50);
    bank1.showBalance();

    bank1.withdraw(100, 98);
    bank1.showBalance();
}

void runPart2() {
    SavingsAccount account;
    bool isNotDone;
    char input;

    askInitialBalance(account);

    // handle deposit flow
    isNotDone = true;
    while (isNotDone) {
        cout << endl << "Would you like to make a deposit? (Y/y) for yes: ";
        input = readChar();

        if (input == 'Y' || input == 'y')
            askForDeposit(account);
        else // at this point, we are done
            isNotDone = false;
    }

    // handle withdrawal flow
    isNotDone = true;
    while (isNotDone) {
        cout << endl << "Would you like to make a withdrawal? (Y/y) for yes: ";
        input = readChar();

        if (input == 'Y' || input == 'y')
            askForWithdrawal(account);
        else // at this point, we are done
            isNotDone = false;
    }

    cout << endl;
    account.showBalance();
}

int main() {
    // For part 1, call runPart1()
    // For part 2, call runPart2()
    runPart2();

    return 0;
}
