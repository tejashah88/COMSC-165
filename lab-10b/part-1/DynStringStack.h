#ifndef DYNSTRINGSTACK_H
#define DYNSTRINGSTACK_H

using namespace std;

class DynStringStack {
    public:
        DynStringStack() : top(nullptr) {}
        ~DynStringStack();

        void push(string val);
        void pop(string &output);
        bool isEmpty() const { return !top; };

    private:
        struct StackNode {
            const string value;
            StackNode *next;
            StackNode(const string val) : value(val), next(nullptr) {}
        };

        StackNode *top = nullptr;
};

#endif // DYNSTRINGSTACK_H
