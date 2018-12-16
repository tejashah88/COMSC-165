/*
 * Name: Lab 3D-2
 * Class: COMSC-165
 * Date: 10/5/2018
 * Author: Tejas Shah
 * Description: Sorts an array using Bubble and Selection sort.
 */

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void swap_num(int &a, int &b);
int bubbleSort(int array[], const int size);
int selectionSort(int array[], const int size);

void swap_num(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int bubbleSort(int array[], const int size) {
    int maxE1ement;
    int index;
    int num_swaps = 0;
    for (maxE1ement = size - 1; maxE1ement > 0; maxE1ement--) {
        for (index = 0; index < maxE1ement; index++) {
            if (array[index] > array[index + 1]) {
                swap_num(array[index], array[index + 1]);
                num_swaps++;
            }
        }
    }

    return num_swaps;
}

int selectionSort(int array[], const int size) {
    int minIndex, minValue;
    int num_swaps = 0;
    for (int start = 0; start < (size - 1); start++) {
        minIndex = start;
        minValue = array[start];
        for (int index = start + 1; index < size; index++) {
            if (array[index] < minValue) {
                minValue = array[index];
                minIndex = index;
            }
        }
        swap_num(array[minIndex], array[start]);
        num_swaps++;
    }

    return num_swaps;
}

void printArray(int array[], const int size) {
    cout << "[ ";
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << "]";
}

int main() {
    int arr1[] = {
        5658845, 4520125, 7895122, 8777541, 8451277,
        1302850, 8080152, 4562555, 5552012, 5050552,
        7825877, 1250255, 1005231, 6545231, 3852085,
        7576651, 7881200, 4581002
    };

    int arr2[] = {
        5658845, 4520125, 7895122, 8777541, 8451277,
        1302850, 8080152, 4562555, 5552012, 5050552,
        7825877, 1250255, 1005231, 6545231, 3852085,
        7576651, 7881200, 4581002
    };

    const int ARR_SIZE = 18; // should be 20?

    cout << "Bubble sort results: " << endl;
    int num_swaps_bubble_sort = bubbleSort(arr1, ARR_SIZE);
    cout << "  ";
    printArray(arr1, ARR_SIZE);
    cout << endl;
    cout << "  Number of swaps: " << num_swaps_bubble_sort << endl;

    cout << endl;

    int num_swaps_selection_sort = selectionSort(arr2, ARR_SIZE);
    cout << "  ";
    printArray(arr2, ARR_SIZE);
    cout << endl;
    cout << "  Number of swaps: " << num_swaps_selection_sort << endl;

    return 0;
}
