#include "wrapper.h"
#include <iostream>
#include <random>
#include <time.h>

extern bool debug;

using namespace std;

void Wrapper::scramble() {
    int SWAPS = v.size() * 10;
    srand(time(0));
    for (unsigned i = 0;i < SWAPS;++i) {
        swap(v.at(rand() % v.size()),v.at(rand()  % v.size()));
    }
    sorted = false;
}

/* Sort functions */
int Wrapper::find_min_location(int start) {
    int index = start;
    for (unsigned i = start+1;i < v.size();++i) {
        comparisons++;
        if (v.at(i) < v.at(index)) { index = i; }
    }
    return index;
}

void Wrapper::sort() { 
    if (divide_and_conquer) { merge_sort(0,v.size()); }
    else { selection_sort(); }
    sorted = true;
}

void Wrapper::selection_sort() {
    comparisons = 0;
    for (unsigned i = 0;i < v.size();i++) {
        swap(v.at(i),v.at(find_min_location(i)));
    }
}

void Wrapper::merge_sort(int beg,int end,int steps) {
    if ((end-beg) <= 1) { return; }
    int mid = beg + ((end - beg)/2);
    if (debug) {
        for (unsigned i = 0;i < steps;i++) { cout << '\t'; }
        cout << "Sorting "; 
        display(beg,end); 
        cout << endl;
    }
    merge_sort(beg,mid,steps+1); // Merge sort the left
    merge_sort(mid,end,steps+1); // Merge sort the right
    if (debug) {
        for (unsigned i = 0;i < steps;i++) { cout << '\t'; }
        cout << "Merging "; 
        display(beg,mid); cout << " and ";
        display(mid,end); cout << endl;
    }
    merge(beg,mid,end); // Merge left and right together
    if (debug) {
        for (unsigned i = 0;i < steps;i++) { cout << '\t'; }
        cout << "Sorted "; 
        display(beg,end); 
        cout << endl;
    }
}

void Wrapper::merge(int beg,int mid,int end) {
    unsigned i = beg, j = mid, curr = 0;
    vector<int> temp(end-beg);
    while (i < mid && j < end) {
        if (v.at(i) < v.at(j)) {
            temp.at(curr) = v.at(i);
            i++;
        } else {
            temp.at(curr) = v.at(j);
            j++;
        }
        curr++;
    }
    // Copy the rest of left into temp (does nothing if i == mid
    for (;i < mid;i++) { temp.at(curr) = v.at(i);curr++; }
    // Copy the rest of right into temp (does nothing if j == end
    for (;j < end;j++) { temp.at(curr) = v.at(j);curr++; }
    // Copy the temp into v[beg:end]
    for (unsigned cpy = 0;cpy < temp.size();cpy++) { v.at(beg+cpy) = temp.at(cpy); }
}

/* Search functions */
int Wrapper::binary_search(int key) { 
    comparisons = 0;
    return binary_search(key,0,v.size()); 
}

int Wrapper::binary_search(int key,int start,int end) {
    if (debug) {
        for (int i = 0;i < comparisons;i++) { cout << '\t'; }
        cout << "Searching for " << key << " in " << *this << endl;
    }
    if (start >= end) { return -1; }
    int mid = ((end - start) / 2) + start;
    comparisons++;
    if (key == v.at(mid)) { return mid; }
    else if (key < v.at(mid)) { return binary_search(key,start,mid); }
    else { return binary_search(key,mid + 1,end); }
}

int Wrapper::search(int key) {
    return sorted && divide_and_conquer? binary_search(key) : linear_search(key);
}

int Wrapper::linear_search(int key) {
    comparisons = 0;
    for (unsigned i = 0;i < v.size();++i) {
        comparisons++;
        if (v.at(i) == key) {
            return i;
        }
        if (sorted && v.at(i) > key) {
            return -1; // Early abandon
        }
    }
    return -1;
}
