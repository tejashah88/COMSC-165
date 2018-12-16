#ifndef DYNFLOATQUEUE_H
#define DYNFLOATQUEUE_H

class DynFloatQueue {
    public:
        DynFloatQueue() : front(nullptr), rear(nullptr), numItems(0) {};
        ~DynFloatQueue() { clear(); };

        // Queue operations
        void enqueue(float val);
        void dequeue(float &output);
        bool isEmpty() const { return numItems <= 0; };
        void clear();

    private:
        struct QueueNode {
            const float value;
            QueueNode *next;
            QueueNode(const float val) : value(val), next(nullptr) {}
        };

        QueueNode *front;
        QueueNode *rear;
        int numItems;
};

#endif // DYNFLOATQUEUE_H
