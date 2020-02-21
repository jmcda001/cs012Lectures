#ifndef __INTNODE_H__
#define __INTNODE_H__

struct IntNode {
    int data;
    IntNode *next;

    IntNode(int data): data(data),next(nullptr) { }
};

#endif // __INTNODE_H__
