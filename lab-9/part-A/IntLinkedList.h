#ifndef INTLINKEDLIST_H
#define INTLINKEDLIST_H


class IntLinkedList {
    public:
        IntLinkedList() : head(nullptr) {}
        ~IntLinkedList();
        IntLinkedList(const IntLinkedList &other);

        void appendNode(const int num);
        void insertNode(const int num);
        void deleteNode(const int num);
        void displayList() const;
        void reverseList();

    private:
        struct ListNode {
            const int value;
            ListNode *next;
            ListNode(const int val) : value(val), next(nullptr) {}
        };

        ListNode *head = nullptr;
};

#endif // INTLINKEDLIST_H
