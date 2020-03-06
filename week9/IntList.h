#ifndef __INTLIST_H__
#define __INTLIST_H__

struct IntNode {
    int data;
    IntNode *next;
    IntNode(int data) : data(data), next(nullptr) { }
};

class IntList {
    private:
        IntNode *head;
        IntNode *tail;
    public:
        IntList();
        void push_front(int value);
        int sum() const;
        void printReverse() const;
    private:
        int sum(IntNode *) const;
        void printReverseRecurse(IntNode *) const;
};

#endif // __INTLIST_H__
