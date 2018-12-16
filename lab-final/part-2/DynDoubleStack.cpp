#include <iostream>
#include "DynDoubleStack.h"

using namespace std;

DynDoubleStack::~DynDoubleStack() {
    StackNode *nodePtr = nullptr, *nextNode = nullptr;

    // Position nodePtr at the top of the stack.
    nodePtr = top;

    // Traverse the list deleting each node
    while (nodePtr != nullptr) {
        nextNode = nodePtr->next;
        delete nodePtr;
        nodePtr = nextNode;
    }
}

void DynDoubleStack::push(double val) {
    StackNode *newNode = new StackNode(val);

    // If there are no nodes in the list make newNode the first node.
    if (isEmpty()) {
        top = newNode;
        newNode->next = nullptr;
    } else { // Otherwise, insert NewNode before top.
        newNode->next = top;
        top = newNode;
    }
}

void DynDoubleStack::pop(double &output) {
    StackNode *temp = nullptr; // Temporary pointer

    // First make sure the stack isn't empty.
    if (isEmpty()) {
        cout << "The stack is empty.\n";
    } else { // pop value off top of stack
        output = top->value;
        temp = top->next;
        delete top;
        top = temp;
    }
}
