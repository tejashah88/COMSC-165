/*
 * Name: Lab 4B-5
 * Class: COMSC-165
 * Date: 10/11/2018
 * Author: Tejas Shah
 * Description: Prompts the user for their favorite food, snack and drink, and then concatenates all of them and prints the result.
 */

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    string food, snack, drink;

    cout << "Enter your favorite food: ";
    cin >> food;

    cout << "Enter your favorite snack: ";
    cin >> snack;

    cout << "Enter your favorite drink: ";
    cin >> drink;

    cout << endl;

    cout << "Favorite food: " << food << endl;
    cout << "Favorite snack: " << snack << endl;
    cout << "Favorite drink: " << drink << endl;

    string concatenated = food + ", " + snack + " and " + drink;
    cout << "Favorite consumables: " << concatenated << endl;

    return 0;
}
