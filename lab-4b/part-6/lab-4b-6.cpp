/*
 * Name: Lab 4B-6
 * Class: COMSC-165
 * Date: 10/11/2018
 * Author: Tejas Shah
 * Description: Counts the number of vowels in a sentence for each vowel.
 */

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    int vowelCounts[5] = {};
    const char VOWELS[5] = {'a', 'e', 'i', 'o', 'u'};

    for (int i = 0; i < 5; i++) {
        const char vowel = VOWELS[i];
        for (char ch : input) {
            if (tolower(ch) == vowel)
                vowelCounts[i]++;
        }
    }

    cout << "Entered string: " << input << endl;
    for (int i = 0; i < 5; i++) {
        cout << "There are " << vowelCounts[i] << " occurrences for the vowel " << VOWELS[i] << endl;
    }

    int sumVowels = 0;
    for (int count : vowelCounts)
        sumVowels += count;

    cout << "There are a total of " << sumVowels << " vowels in the input string." << endl;

    return 0;
}
