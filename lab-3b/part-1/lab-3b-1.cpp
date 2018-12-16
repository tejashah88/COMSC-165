/*
 * Name: Lab 3B-1
 * Class: COMSC-165
 * Date: 9/27/2018
 * Author: Tejas Shah
 * Description: It grades a 20-question multiple choice exam and gives the student a pass or fail grade.
 */

#include <iostream>
#include <string>

using namespace std;

void promptAnswers(char answers[20]);
void checkAnswers(char answers[20], char answer_key[20]);

void promptAnswers(char answers[20]) {
    char answer;
    int questionNum = 1;

    cout << "Enter the given answers for all the questions: " << endl;
    while (questionNum <= 20) {
        cin >> answer;
        if (answer < 'A' || answer > 'D') {
            cout << "Got an invalid input: '" << answer << "'! Skipping..." << endl;
        } else {
            answers[questionNum - 1] = answer;
            questionNum++;
        }
    }
}

void checkAnswers(char answers[20], const char answer_key[20], int incorrect_answers[20], int &correct, int &incorrect) {
    for (int i = 0; i < 20; i++)
        incorrect_answers[i] = -1;

    for (int i = 0; i < 20; i++) {
        if (answers[i] == answer_key[i])
            correct++;
        else {
            incorrect_answers[incorrect] = (i + 1);
            incorrect++;
        }
    }
}

int main() {
    const int CORRECT_FOR_PASSING = 14;
    const char ANSWER_KEY[] = { 'A', 'D', 'B', 'B', 'C', 'B', 'A', 'B', 'C', 'D', 'A', 'C', 'D', 'B', 'D', 'C', 'C', 'A', 'D', 'B' };

    string names[100];
    char students_answers[20];
    int incorrect_answers[20];
    int correct, incorrect;
    int numExams;

    cout << "How many exams are to be graded: " << endl;
    cin >> numExams;

    for (int i = 0; i < numExams; i++) {
        cout << "What the student's name: " << endl;
        cin.ignore(); // ignore the extra newline in preparation for getline
        string name;
        getline(cin, name);
        names[i] = name;

        correct = incorrect = 0;
        promptAnswers(students_answers);
        checkAnswers(students_answers, ANSWER_KEY, incorrect_answers, correct, incorrect);

        cout << names[i] << " " << (correct >= CORRECT_FOR_PASSING ? "passed" : "failed") << " the exam!" << endl;
        cout << "Number of correct answers is " << correct << ", and number of incorrect answers is " << incorrect << endl;

        int index = 0;
        if (incorrect_answers[0] != -1) {
            cout << "Incorrect answers found at questions ";
            while (index < 20 && incorrect_answers[index] != -1)
                cout << incorrect_answers[index++] << ((index < 20 && incorrect_answers[index + 1] != -1) ? ", " : "");
            cout << endl;
        }

        cout << endl;
    }

    cout << endl << "Graded " << numExams << " exams from the following students:" << endl;
    for (int i = 0; i < numExams; i++) {
        cout << "  - " << names[i] << endl;
    }

    return 0;
}
