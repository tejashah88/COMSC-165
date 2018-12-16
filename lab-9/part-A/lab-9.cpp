/*
 * Name: Lab 9
 * Class: COMSC-165
 * Date: 11/10/2018
 * Author: Tejas Shah
 * Description: A linked-list demonstration.
 */

#include "IntLinkedList.cpp"

using namespace std;

int main() {
    IntLinkedList firstList;
    firstList.appendNode(2);
    firstList.appendNode(4);
    firstList.appendNode(6);
    firstList.displayList();

    IntLinkedList secondList = firstList;
    secondList.displayList();

    firstList.insertNode(5);
    firstList.displayList();

    firstList.deleteNode(6);
    firstList.displayList();

    secondList.displayList();

    secondList.reverseList();
    secondList.displayList();
    return 0;
}
