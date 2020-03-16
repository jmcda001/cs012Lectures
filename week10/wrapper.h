#ifndef __WRAPPER_H__
#define __WRAPPER_H__

#include <ostream>
#include <vector>

class Wrapper {
    private:
        std::vector<int> v;
        int comparisons;
        bool sorted;
        bool divide_and_conquer;

    public:
        explicit Wrapper(int size) : v(size), sorted(false), divide_and_conquer(false) { }

        /* Mutators */
        void push_back(int val);// Define yourself
        void scramble();
        void sort();
        void set_divide_and_conquer(bool new_value = true) { divide_and_conquer = new_value; }

        /* Accessors */
        int get_comparisons() const { return comparisons; }
        int size() const { return v.size(); }
        int at(int i) const { return v.at(i); }
        int search(int); 
        void display() const; // Define yourself

        friend std::ostream& operator<<(std::ostream&,const Wrapper &); // Define yourself

    private:
        void display(int,int) const;

        int find_min_location(int);
        void selection_sort();
        void merge_sort(int,int,int=0);
        void merge(int,int,int);

        int linear_search(int);
        int binary_search(int);
        int binary_search(int,int,int);
};

#endif // __WRAPPER_H__
