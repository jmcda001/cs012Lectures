#include "IntNode.h"
#include <iostream>

class IntList {
    private:
        IntNode *head;
        IntNode *tail;

    /* Helper functions */
    private:
        int size() const;

    /* Public interface for class demo */
    public:
        void print_memory() const;

    /* Lab public interface */
    public:
        /* Constructor/destructor */
        IntList();
        ~IntList();

        /* Mutators */
        void push_front(int);
        void pop_front();

        /* Accessors */
        bool empty() const;
        const int &front() const;
        const int &back() const; 

        /* Friends */
        friend std::ostream &operator<<(std::ostream &,const IntList &);

    /* Assignment public interface */
    public:
        /* New constructors */
        IntList(const IntList &);

        /* Mutators */
        void push_back(int);
        void clear();
        void selection_sort();
        void insert_ordered(int);
        void remove_duplicates();
};
