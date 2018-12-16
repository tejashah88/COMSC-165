/*
 * Name: Lab FINAL-1
 * Class: COMSC-165
 * Date: 12/12/2018
 * Author: Tejas Shah
 */

#include <iostream>
#include <iomanip>

#include "FactoryWorker.cpp"

using namespace std;

int promptInt(string prompt) {
    int input;
    cout << prompt;
    cin >> input;
    while (cin.fail()) {
        cin.clear();
        cin.ignore();
        cin >> input;
    }

    cin.ignore();
    return input;
}

double promptDouble(string prompt) {
    double input;
    cout << prompt;
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
    string input;
    cout << prompt;
    getline(cin, input);
    return input;
}

void displayWorker(FactoryWorker worker) {
    cout << "Worker name: " << worker.getName() << endl;
    cout << "Worker ID: " << worker.getId() << endl;
    cout << "Worker employment date: " << worker.getEmploymentDate() << endl;
    cout << "Worker shift: " << worker.getShiftName() << endl;
    cout << "Worker hourly pay rate: $" << setprecision(2) << fixed << worker.getPayRate() << endl;
}

FactoryWorker promptWorkerData() {
    string name = promptLine("What's your name: ");
    int id = promptInt("What's your ID: ");
    string employmentDate = promptLine("What's your employment date: ");
    int shift = promptInt("What's your working shift (1 for day and 2 for night): ");
    double payRate = promptDouble("What's your hourly pay rate: $");
    return FactoryWorker(name, id, employmentDate, shift, payRate);
}

int main() {
    FactoryWorker worker1("Joan Smith", 12345, "12/01/2018", 1, 25.00);
    displayWorker(worker1);
    cout << endl;

    FactoryWorker worker2 = promptWorkerData();
    cout << endl;
    displayWorker(worker2);
    cout << endl;

    FactoryWorker worker3 = promptWorkerData();
    cout << endl;
    displayWorker(worker3);
    cout << endl;
    return 0;
}
