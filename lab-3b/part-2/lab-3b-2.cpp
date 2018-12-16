/*
 * Name: Lab 3B-2
 * Class: COMSC-165
 * Date: 9/27/2018
 * Author: Tejas Shah
 * Description: A program that helps a restaurant owner keep track of how many pounds of food each category of diners eats each day during a typical week.
 */

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int getNumberFromInput();
float getAverage(int arr[], int length);
int getMaxIndex(int arr[], int length);
int getMinIndex(int arr[], int length);

void promptData(int diner_data[3][7]);
void printDinerData(int diner_data[3][7]);
void printAverageFoodEaten(int diner_data[3][7]);
void printMinFoodEatenByKids(int diner_data[3][7]);
void printMaxFoodEatenByAdults(int diner_data[3][7]);

int getNumberFromInput() {
    int input;
    cin >> input;
    while (cin.fail()) {
        cin.clear();
        cin.ignore();
        cin >> input;
    }
    return input;
}

float getAverage(int arr[], int length) {
    int sum;
    for (int i = 0; i < length; i++)
        sum += arr[i];

    return (float) sum / length;
}

int getMaxIndex(int arr[], int length) {
    int maxVal = arr[0];
    int maxIndex = 0;

    for (int i = 0; i < length; i++) {
        if (arr[i] > maxVal) {
            maxIndex = i;
            maxVal = arr[i];
        }
    }

    return maxIndex;
}

int getMinIndex(int arr[], int length) {
    int minVal = arr[0];
    int minIndex = 0;

    for (int i = 0; i < length; i++) {
        if (arr[i] < minVal) {
            minIndex = i;
            minVal = arr[i];
        }
    }

    return minIndex;
}

void promptData(int diner_data[3][7]) {
    const string CATEGORIES[] = {"Kids", "Adults", "Seniors"};
    int foodEaten;

    cout << "Enter the diner data for all 7 days for the following categories: " << endl;
    for (int cat = 0; cat < 3; cat++) {
        cout << CATEGORIES[cat] << ": ";
        for (int day = 0; day < 7; day++) {
            do {
                foodEaten = getNumberFromInput();
            } while (foodEaten < 0);
            diner_data[cat][day] = foodEaten;
        }
    }
}

void printDinerData(int diner_data[3][7]) {
    for (int cat = 0; cat < 3; cat++) {
        for (int day = 0; day < 7; day++) {
            cout << diner_data[cat][day] << '\t' << " ";
        }
        cout << endl;
    }
}

void printAverageFoodEaten(int diner_data[3][7]) {
    const string DAYS[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    for (int day_index = 0; day_index < 7; day_index++) {
        string day = DAYS[day_index];
        int sum = 0;

        for (int cat = 0; cat < 3; cat++) {
            sum += diner_data[cat][day_index];
        }

        cout << "Average food eaten on " << day << ": " << setprecision(2) << fixed << (sum / 3.0f) << " lbs" << endl;
    }
}

void printMinFoodEatenByKids(int diner_data[3][7]) {
    const string DAYS[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    const int KIDS_CAT_INDEX = 0;

    int minFood = 2147483647; // set this to the highest integer number possible, since we want to find the least amount of food
    int minCatIndex = -1;
    int minDayIndex = -1;

    for (int cat = 0; cat < 3; cat++) {
        for (int day = 0; day < 7; day++) {
            if (cat == KIDS_CAT_INDEX && diner_data[cat][day] < minFood) {
                minCatIndex = cat;
                minDayIndex = day;
                minFood = diner_data[minCatIndex][minDayIndex];
            }
        }
    }

    string day = DAYS[minDayIndex];
    cout << "The least amount of food eaten by kids was " << minFood << " lbs on " << day << endl;
}

void printMaxFoodEatenByAdults(int diner_data[3][7]) {
    const string DAYS[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    const int KIDS_ADULTS_INDEX = 1;

    int maxFood = -2147483648; // set this to the lowest integer number possible, since we want to find the most amount of food
    int maxCatIndex = -1;
    int maxDayIndex = -1;

    for (int cat = 0; cat < 3; cat++) {
        for (int day = 0; day < 7; day++) {
            if (cat == KIDS_ADULTS_INDEX && diner_data[cat][day] > maxFood) {
                maxCatIndex = cat;
                maxDayIndex = day;
                maxFood = diner_data[maxCatIndex][maxDayIndex];
            }
        }
    }

    string day = DAYS[maxDayIndex];
    cout << "The most amount of food eaten by adults was " << maxFood << " lbs on " << day << endl;
}

int main() {
    int diner_data[3][7];

    promptData(diner_data);
    cout << endl;

    printAverageFoodEaten(diner_data);
    cout << endl;

    printMinFoodEatenByKids(diner_data);
    printMaxFoodEatenByAdults(diner_data);
    return 0;
}
