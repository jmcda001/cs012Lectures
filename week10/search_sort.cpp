#include <iostream>
#include "wrapper.h"

using namespace std;

bool debug = false;

void test_divide_and_conquer();
void test_linear();

int main() {
    cout << "Testing linear..." << endl;
    test_linear();
    cout << "Testing divide and conquer..." << endl;
    test_divide_and_conquer();

    return 0;
}

void test_divide_and_conquer() {
    const int SIZE = 20;
    Wrapper v(0);
    v.set_divide_and_conquer();
    for (unsigned i = 0;i < SIZE;++i) { v.push_back(i); }
    v.scramble();

    cout << "Test searching an unsorted array (linear)..." << endl;
    int search_value = 8; // Search for first element (best case)
    cout << "Search for " << search_value << " in " << v << "..."; 
    int index = v.search(search_value);
    if (index >= 0) { cout << "Found in "; } 
    else { cout << "Not found after "; }
    cout << v.get_comparisons() << " comparisons." << endl;

    search_value = 15; // Search for middle element (average case) 
    cout << "Search for " << search_value << " in " << v << "..."; 
    index = v.search(search_value);
    if (index >= 0) { cout << "Found in "; } 
    else { cout << "Not found after "; }
    cout << v.get_comparisons() << " comparisons." << endl;

    search_value = 1; // Search for last elemeent (worst case)
    cout << "Search for " << search_value << " in " << v << "..."; 
    index = v.search(search_value);
    if (index >= 0) { cout << "Found in "; } 
    else { cout << "Not found after "; }
    cout << v.get_comparisons() << " comparisons." << endl;

    search_value = 21; // Search for non-existant element (worst case)
    cout << "Search for " << search_value << " in " << v << "..."; 
    index = v.search(search_value);
    if (index >= 0) { cout << "Found in "; } 
    else { cout << "Not found after "; }
    cout << v.get_comparisons() << " comparisons." << endl;

    int total_comparisons = 0;
    for (unsigned i = 0;i < v.size();i++) {
        v.search(v.at(i));
        total_comparisons += v.get_comparisons();
    }
    cout << "Average comparions: " << total_comparisons / v.size() << endl;
    cout << endl;

    cout << "Sorting the array..." << endl;
    cout << "Unsorted: " << v << endl;
    v.sort();
    cout << "Sorted: " << v << endl;
    cout << "Sort took " << v.get_comparisons() << " comparisons." << endl << endl;

    cout << "Test searching a sorted array (binary)..." << endl;
    search_value = 8; // Search for first element (best case)
    cout << "Search for " << search_value << " in " << v << "...";
    index = v.search(search_value);
    if (index >= 0) { cout << "Found in "; } 
    else { cout << "Not found after "; }
    cout << v.get_comparisons() << " comparisons." << endl;

    search_value = 15; // Search for middle element (average case) 
    cout << "Search for " << search_value << " in " << v << "...";
    index = v.search(search_value); 
    if (index >= 0) { cout << "Found in "; } 
    else { cout << "Not found after "; }
    cout << v.get_comparisons() << " comparisons." << endl;

    search_value = 1; // Search for last elemeent (worst case)
    cout << "Search for " << search_value << " in " << v << "...";
    index = v.search(search_value); 
    if (index >= 0) { cout << "Found in "; } 
    else { cout << "Not found after "; }
    cout << v.get_comparisons() << " comparisons." << endl;

    search_value = -1; // Search for non-existant element (worst case)
    cout << "Search for " << search_value << " in " << v << "...";
    index = v.search(search_value); 
    if (index >= 0) { cout << "Found in "; } 
    else { cout << "Not found after "; }
    cout << v.get_comparisons() << " comparisons." << endl;

    total_comparisons = 0;
    for (unsigned i = 0;i < v.size();++i) {
        v.search(v.at(i));
        total_comparisons += v.get_comparisons();
    }
    cout << "Average comparions: " << total_comparisons / v.size() << endl;
    cout << endl;
}

void test_linear() {
    const int SIZE = 20;
    Wrapper v(0);
    for (unsigned i = 0;i < SIZE;++i) { v.push_back(i); }
    v.scramble();

    cout << "Test searching an unsorted array (linear)..." << endl;
    int search_value = 8; // Search for first element (best case)
    cout << "Search for " << search_value << " in " << v << "..."; 
    int index = v.search(search_value);
    if (index >= 0) { cout << "Found in "; } 
    else { cout << "Not found after "; }
    cout << v.get_comparisons() << " comparisons." << endl;

    search_value = 15; // Search for middle element (average case) 
    cout << "Search for " << search_value << " in " << v << "..."; 
    index = v.search(search_value);
    if (index >= 0) { cout << "Found in "; } 
    else { cout << "Not found after "; }
    cout << v.get_comparisons() << " comparisons." << endl;

    search_value = 1; // Search for last elemeent (worst case)
    cout << "Search for " << search_value << " in " << v << "..."; 
    index = v.search(search_value);
    if (index >= 0) { cout << "Found in "; } 
    else { cout << "Not found after "; }
    cout << v.get_comparisons() << " comparisons." << endl;

    search_value = 21; // Search for non-existant element (worst case)
    cout << "Search for " << search_value << " in " << v << "..."; 
    index = v.search(search_value);
    if (index >= 0) { cout << "Found in "; } 
    else { cout << "Not found after "; }
    cout << v.get_comparisons() << " comparisons." << endl;

    int total_comparisons = 0;
    for (unsigned i = 0;i < v.size();i++) {
        v.search(v.at(i));
        total_comparisons += v.get_comparisons();
    }
    cout << "Average comparions: " << total_comparisons / v.size() << endl;
    cout << endl;

    cout << "Sorting the array..." << endl;
    cout << "Unsorted: " << v << endl;
    v.sort();
    cout << "Sorted: " << v << endl;
    cout << "Sort took " << v.get_comparisons() << " comparisons." << endl << endl;

    cout << "Test searching a sorted array (binary)..." << endl;
    search_value = 8; // Search for first element (best case)
    cout << "Search for " << search_value << " in " << v << "...";
    index = v.search(search_value);
    if (index >= 0) { cout << "Found in "; } 
    else { cout << "Not found after "; }
    cout << v.get_comparisons() << " comparisons." << endl;

    search_value = 15; // Search for middle element (average case) 
    cout << "Search for " << search_value << " in " << v << "...";
    index = v.search(search_value); 
    if (index >= 0) { cout << "Found in "; } 
    else { cout << "Not found after "; }
    cout << v.get_comparisons() << " comparisons." << endl;

    search_value = 1; // Search for last elemeent (worst case)
    cout << "Search for " << search_value << " in " << v << "...";
    index = v.search(search_value); 
    if (index >= 0) { cout << "Found in "; } 
    else { cout << "Not found after "; }
    cout << v.get_comparisons() << " comparisons." << endl;

    search_value = -1; // Search for non-existant element (worst case)
    cout << "Search for " << search_value << " in " << v << "...";
    index = v.search(search_value); 
    if (index >= 0) { cout << "Found in "; } 
    else { cout << "Not found after "; }
    cout << v.get_comparisons() << " comparisons." << endl;

    total_comparisons = 0;
    for (unsigned i = 0;i < v.size();++i) {
        v.search(v.at(i));
        total_comparisons += v.get_comparisons();
    }
    cout << "Average comparions: " << total_comparisons / v.size() << endl;
    cout << endl;
}

