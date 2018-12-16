#ifndef NUMBERLIST_H
#define NUMBERLIST_H

struct ListNode {
    const double value;
    ListNode *next;
    ListNode(const double val) : value(val), next(nullptr) {}
};

class NumberList {
    private:
        ListNode *head;

    public:
        NumberList() : head(nullptr) {}
        ~NumberList();
        NumberList(const NumberList &other);

        void appendNode(const double num);
        void insertNode(const double num);
        void deleteNode(const double num);
        void displayList();
        void reverseList();

        double calculateMaxNode(ListNode *nodePtr) const;
        double maxNode() const { return calculateMaxNode(head); };
};

#endif // NUMBERLIST_H
