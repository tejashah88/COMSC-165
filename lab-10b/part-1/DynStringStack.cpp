#include <iostream>
#include "DynStringStack.h"

using namespace std;

DynStringStack::~DynStringStack() {
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

void DynStringStack::push(string val) {
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

void DynStringStack::pop(string &output) {
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
