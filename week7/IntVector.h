#ifndef INTVECTOR_H
#define INTVECTOR_H

class IntVector {
    private:
        unsigned _size;
        unsigned _capacity;
        int* data;

    /* In class demo */
    public:
        friend void print_memory(const IntVector &);
        IntVector(const IntVector &copy);
        IntVector &operator=(const IntVector &copy);

    /* Lab public interface */
    public:
        IntVector();
        unsigned size() const;
        unsigned capacity() const;
        bool empty() const;
        const int& at(unsigned) const;
        const int& front() const;
        const int& back() const;

    /* Assignment public interface */
    public:
        IntVector(unsigned, int = 0);
        ~IntVector();
        int& at(unsigned);
        void insert(unsigned, int);
        void erase(unsigned);
        int& front();
        int& back();
        void assign(unsigned, int);
        void push_back(int);
        void pop_back();
        void clear();
        void resize(unsigned, int = 0);
        void reserve(unsigned);
     private:
       void expand();
       void expand(unsigned amount);
};

#endif // INTVECTOR_H
