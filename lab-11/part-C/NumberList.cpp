#include <iostream>
#include "NumberList.h"

using namespace std;

NumberList::~NumberList() {
    ListNode *currNode = head;
    ListNode *nextNode;

    while (currNode != nullptr) {
        nextNode = currNode->next;
        delete currNode;
        currNode = nextNode;
    }
}

NumberList::NumberList(const NumberList &other) {
    ListNode *othercurrNode = other.head;

    while (othercurrNode != nullptr) {
        this->appendNode(othercurrNode->value);
        othercurrNode = othercurrNode->next;
    }
}

void NumberList::appendNode(const double num) {
    ListNode *newNode = new ListNode(num);

    if (!head)
        head = newNode;
    else {
        ListNode *currNode = head;

        while (currNode->next)
            currNode = currNode->next;

        currNode->next = newNode;
    }
}

void NumberList::insertNode(const double num) {
    if (!head)
        head = new ListNode(num);
    else {
        ListNode *currNode = head;
        ListNode *previousNode = nullptr;
        ListNode *newNode = new ListNode(num);

        while (currNode != nullptr && currNode->value < num) {
            previousNode = currNode;
            currNode = currNode->next;
        }

        if (previousNode == nullptr) {
            head = newNode;
            newNode->next = currNode;
        } else {
            previousNode->next = newNode;
            newNode->next = currNode;
        }
    }
}

void NumberList::displayList() {
    ListNode *currNode = head;
    cout << "< ";

    while (currNode) {
        cout << currNode->value << " ";
        currNode = currNode->next;
    }

    cout << ">" << endl;
}

void NumberList::deleteNode(const double num) {
    if (!head)
        return;
    if (head->value == num) {
        ListNode *currNode = head->next;
        delete head;
        head = currNode;
    } else {
        ListNode *previousNode;
        ListNode *currNode = head;

        while (currNode != nullptr && currNode->value != num) {
            previousNode = currNode;
            currNode = currNode->next;
        }

        if (currNode) {
            previousNode->next = currNode->next;
            delete currNode;
        }
    }
}

void NumberList::reverseList() {
    ListNode *currNode = head;
    ListNode *previousNode = nullptr;
    ListNode *nextNode = nullptr;

    while (currNode != nullptr) {
        // shift over by one to the left
        nextNode = currNode->next;
        currNode->next = previousNode;

        // shift over by one to the right
        previousNode = currNode;
        currNode = nextNode;
    }

    head = previousNode;
}

double NumberList::calculateMaxNode(ListNode *nodePtr) const {
    if (nodePtr == nullptr)
        return INT_MIN; // we use INT_MIN to guarantee that the smallest int will be returned
    double currValue = nodePtr->value;
    double otherValue = calculateMaxNode(nodePtr->next);
    return currValue > otherValue ? currValue : otherValue;
}
