#include <iostream>
#include "DynFloatQueue.h"

using namespace std;

void DynFloatQueue::enqueue(float val) {
    QueueNode * newNode = new QueueNode(val);

    if (isEmpty())
        front = newNode;
    else
        rear->next = newNode;
    rear = newNode;

    numItems++;
}

void DynFloatQueue::dequeue(float &output) {
    QueueNode *temp = nullptr; // Temporary pointer

    // First make sure the stack isn't empty.
    if (isEmpty()) {
        cout << "The queue is empty.\n";
    } else { // pop value off top of stack
        output = front->value;

        temp = front;
        front = front->next;
        delete temp;

        numItems--;
    }
}

void DynFloatQueue::clear() {
    float throwaway;
    while (!isEmpty())
        dequeue(throwaway);
}
