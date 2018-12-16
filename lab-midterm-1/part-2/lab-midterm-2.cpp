/*
 * Name: Question 52
 * Class: COMSC-165
 * Date: 10/19/2018
 * Author: Tejas Shah
 */

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

const int NUM_QUARTERS = 4;

int readInt();
float readFloat();
string readWord();

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

/*
3
Americas
EMEA
APAC
12018
22018
33018
42018
7500 10000 15000 10000
10000 10000 8000 55000
7500 10000 15000 10000

*/

void promptQuarterlySales(vector<string> regions, vector<int> quarters, int sales[][NUM_QUARTERS]) {
    cout << "Enter the quarterly sales data, with all four quarters in one line for each region: " << endl;

    for (int r = 0; r < regions.size(); r++) {
        cout << regions[r] << ": ";
        for (int i = 0; i < 4; i++)
            sales[r][i] = readInt();
    }
}

float getSingleAverage(int sales[][NUM_QUARTERS], int numRegions, int numQuarters) {
    float avg = 0.0f;
    for (int row = 0; row < numRegions; row++)
        for (int col = 0; col < numQuarters; col++)
            avg += sales[row][col];

    avg /= (numQuarters * numRegions);
    return avg;
}

void getRowAverage(int sales[][NUM_QUARTERS], int numRegions, int numQuarters, float avg[]) {
    float sum = 0.0f;
    for (int row = 0; row < numRegions; row++) {
        for (int col = 0; col < numQuarters; col++)
            avg[row] += sales[row][col];
        avg[row] /= numQuarters;
    }
}

void getColAverage(int sales[][NUM_QUARTERS], int numRegions, int numQuarters, float avg[]) {
    float sum = 0.0f;
    for (int col = 0; col < numQuarters; col++) {
        for (int row = 0; row < numRegions; row++)
            avg[col] += sales[row][col];
        avg[col] /= numRegions;
    }
}

void printAverageStats(vector<string> regions, vector<int> quarters, int sales[][NUM_QUARTERS]) {
    float wholeCompAvg = getSingleAverage(sales, regions.size(), quarters.size());
    cout << "Average sales across the whole company: $" << setprecision(2) << fixed << wholeCompAvg << endl;
    cout << endl;

    float quarterAvgs[4];
    getColAverage(sales, regions.size(), quarters.size(), quarterAvgs);
    cout << "Average sales per quarter across all regions: " << endl;
    for (int i = 0; i < quarters.size(); i++)
        cout << quarters[i] << ": $" << setprecision(2) << fixed << quarterAvgs[i] << endl;

    cout << endl;

    float regionAvgs[3];
    getRowAverage(sales, regions.size(), quarters.size(), regionAvgs);
    cout << "Average sales per region: " << endl;
    for (int i = 0; i < regions.size(); i++)
        cout << regions[i] << ": $" << setprecision(2) << fixed << regionAvgs[i] << endl;
}

int main() {
    vector<string> regions;
    cout << "Number of regions: ";
    int numRegions = readInt();
    for (int i = 0; i < numRegions; i++) {
        cout << "Region " << (i + 1) << ": ";
        regions.push_back(readWord());
    }

    cout << endl;

    vector<int> quarters;
    for (int i = 0; i < NUM_QUARTERS; i++) {
        cout << "Q" << (i + 1) << ": ";
        quarters.push_back(readInt());
    }

    cout << endl;

    int QuarterlySales[numRegions][NUM_QUARTERS];
    promptQuarterlySales(regions, quarters, QuarterlySales);

    cout << endl;

    printAverageStats(regions, quarters, QuarterlySales);

    cout << endl;

    cout << "Regions analyzed: " << endl;
    for (string region : regions)
        cout << "  " << region << endl;

    cout << endl;

    cout << "Quarters analyzed: " << endl;
    for (int quarter : quarters)
        cout << "  " << quarter << endl;
    return 0;
}
