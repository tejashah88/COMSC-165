/*
 * Name: Lab 3B-3
 * Class: COMSC-165
 * Date: 9/27/2018
 * Author: Tejas Shah
 * Description: A program that determines if a user's pet is a popular pet.
 */

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

ifstream infile;

vector<string> PopulateVector(string filename, int &status);
bool IsPopular(string input_pet, vector<string> popular_pets);

vector<string> PopulateVector(string filename, int &status) {
    vector<string> popular_pets;
    status = 0;

    // read from input file
    infile.open(filename.c_str());
    if (!infile) {
        cout << "Unable to open the input file!" << endl;
        status = 1;
    }

    string popular_pet;
    while (getline(infile, popular_pet))
        popular_pets.push_back(popular_pet);

    return popular_pets;
}

bool IsPopular(string input_pet, vector<string> popular_pets) {
    for (int i = 0; i < popular_pets.size(); i++) {
        if (input_pet == popular_pets[i])
            return true;
    }

    return false;
}

int main() {
    int status;
    vector<string> popular_pets = PopulateVector("PopularPets.txt", status);
    if (status != 0)
        return status;

    cout << "What kind of pet do you have: ";
    string input_pet;
    getline(cin, input_pet);
    cout << "Your pet " << input_pet << " is " << (IsPopular(input_pet, popular_pets) ? "quite " : "not ") << "popular." << endl;
    return 0;
}
