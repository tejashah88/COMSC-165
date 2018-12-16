/*
 * Name: Lab 1B-3
 * Class: COMSC-165
 * Author: Tejas Shah
 * Description: A program for letting the user order a choice of beverages and prints out the total cost once he/she is done.
 */

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    // used for pretty printing currency
    cout << setprecision(2) << fixed;

    const float COFFEE_PRICE = 1.00, TEA_PRICE = 0.75, HOT_CHOCO_PRICE = 1.25, CAPPU_PRICE = 2.50;

    bool requestedExit = false;
    float totalCost = 0;
    char input;

    cout << "Hot Beverage Menu" << endl;
    cout << "A: Coffee         $1.00" << endl;
    cout << "B: Tea            $0.75" << endl;
    cout << "C: Hot Chocolate  $1.25" << endl;
    cout << "D: Cappuccino     $2.50" << endl;
    cout << "E: Exit Menu" << endl;

    do {
        cout << endl << "Make a selection: ";
        cin >> input;

        if (input >= 'A' && input <= 'D') {
            float cupCount;
            // prompt for the number of cups of the requested beverage
            cout << "How many cups would you like: ";
            cin >> cupCount;

            float subTotalCost;
            // calculate the sub total from the input
            switch (input) {
                case 'A':
                    subTotalCost = cupCount * COFFEE_PRICE;
                    break;
                case 'B':
                    subTotalCost = cupCount * TEA_PRICE;
                    break;
                case 'C':
                    subTotalCost = cupCount * HOT_CHOCO_PRICE;
                    break;
                case 'D':
                    subTotalCost = cupCount * CAPPU_PRICE;
                    break;
            }

            totalCost += subTotalCost;
        } else if (input == 'E')
            // we are done, let's get out of this loop
            requestedExit = true;
        else
            cout << "Invalid input detected! Try again." << endl;
    } while (!requestedExit);

    if (totalCost > 0) {
        // display the total cost to the user
        cout << "Your total cost is $" << fixed << totalCost << endl;
    }

    cout << "Have a nice day!" << endl;

    return 0;
}
