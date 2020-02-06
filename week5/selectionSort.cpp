#include <iostream>

using namespace std;

// Find the index (i) of the minimum value in the array after (including) 'start_index'
unsigned int find_min_location(const int arr[],unsigned start_index,unsigned int size);
// Sort the vector 
void selection_sort(int arr[],unsigned int size); 
void display(const int arr[],unsigned int);

// Include the tests file we've created (we'll get to multiple file compilation later in the quarter)
#include "tests.h"

int main() {
    run_tests();
    int size = 5;
    int test_input[size];
    size = size + 1;

    return 0;
}

void selection_sort(int arr[],unsigned int size) {
    for (unsigned i = 0;i < size;i++) {
        swap(arr[i],arr[find_min_location(arr,i,size)]);
    }
}

unsigned int find_min_location(const int arr[],unsigned start_index,unsigned int size) {
    if (start_index > size) {
        return -1;
    }
    int min_index = start_index;
    for (unsigned i = start_index+1;i < size;i++) {
        if (arr[i] < arr[min_index]) {
            min_index = i;
        }
    }
    return min_index;
}

void display(const int arr[],unsigned int size) {
    for (unsigned i = 0;i < size;i++) {
        cout << arr[i] << ' ';
    }
}

