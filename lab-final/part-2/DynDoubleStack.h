#ifndef DYNDOUBLESTACK_H
#define DYNDOUBLESTACK_H

using namespace std;

class DynDoubleStack {
    public:
        DynDoubleStack() : top(nullptr) {}
        ~DynDoubleStack();

        void push(double val);
        void pop(double &output);
        bool isEmpty() const { return !top; };

    private:
        struct StackNode {
            const double value;
            StackNode *next;
            StackNode(const double val) : value(val), next(nullptr) {}
        };

        StackNode *top = nullptr;
};

#endif // DYNDOUBLESTACK_H
