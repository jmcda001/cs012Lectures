#include <iostream>
#include <vector>
#include <assert.h>

using std::cout;
using std::endl;
using std::vector;
using std::swap;

// Function overloading: find_min_location has two declarations (and definitions), one with just the vector as a parameter, one with both the vector and the start index. Depending on how you call it, one of the two functions will be called
// Find the index (i) of the minimum value in the vector
unsigned int find_min_location(const vector<int> &v);
// Find the index (i) of the minimum value in the vector after (including) 'start_index'
unsigned int find_min_location(const vector<int> &v,unsigned start_index);
// Sort the vector 
void selection_sort(vector<int> &v); 

// Include the tests file we've created (we'll get to multiple file compilation later in the quarter)
#include "tests.h"

int main() {
    run_tests();

    return 0;
}

void selection_sort(vector<int> &v) {
    for (unsigned i = 0;i < v.size();i++) {
        swap(v.at(i),v.at(find_min_location(v,i)));
    }
}

unsigned int find_min_location(const vector<int> &v,unsigned start_index) {
    if (start_index > v.size()) {
        return -1;
    }
    int min_index = start_index;
    for (unsigned i = start_index+1 /* start with 0 */;i < v.size();i++) {
        if (v.at(i) < v.at(min_index)) {
            min_index = i;
        }
    }
    return min_index;
}

unsigned int find_min_location(const vector<int> &v) {
    if (v.empty()) { // Don't add this until showing there is an error
        return -1;
    }
    int min_index = 0;
    for (unsigned i = 1 /* start with 0 */;i < v.size();i++) {
        if (v.at(i) < v.at(min_index)) {
            min_index = i;
        }
    }
    return min_index;
}
