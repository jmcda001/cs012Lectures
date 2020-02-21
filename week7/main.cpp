#include "IntList.h"
#include "IntNode.h"
#include "IntVector.h"
#include <iostream>

using namespace std;

void print_array_memory(int *arr,int size);

int main() {
    const int MAX = 10;

    IntList list1; // Statically allocate IntList object with default constructor
    int static_array[MAX]; // Statically allocated integer array
    int *dynamic_array = new int[MAX]; // Dynamically allocated integer array
    IntVector v(10);

    int *_ = nullptr;
    for (unsigned i = 0;i < MAX;i++) {
        if (_) { delete[] _; } // Make sure you delete the memory allocated
        list1.push_front(i); // Push integer 'i' onto front of list
        _ = new int[i*i]; // Nonsense data to fill heap to show memory separation
        dynamic_array[i] = MAX-1-i; // Add value to dynamic array
        static_array[i] = MAX-1-i; // Add value to static array
        v.at(i) = MAX-1-i; // Add value to IntVector
    }

    cout << "Constructing a copy of v..." << endl;
    IntVector v_copy_assignment = v;
    IntVector v_copy(v);
    cout << "Constructing a default IntVector to show '='..." << endl;
    IntVector v_assignment;
    cout << "v_assignment = v_copy... " << endl;
    v_assignment = v_copy;

    cout << "Memory mapping \"index: (address) value (diff with previous address)\"" << endl;
    cout << "Notice the contiguous memory is 4 bytes (sizeof(int)) away from each index" << endl;
    cout << "Where segmented memory is arbitrary." << endl;
    cout << "Memory mapping of linked list..." << endl;
    list1.print_memory();
    cout << endl;

    cout << "Memory mapping of dynamically allocated array..." << endl;
    print_array_memory(dynamic_array,MAX);
    cout << endl;

    cout << "Memory mapping of statically allocated array..." << endl;
    print_array_memory(static_array,MAX);
    cout << endl;

    cout << "Memory mapping of IntVector..." << endl;
    print_memory(v);
    cout << endl;

    cout << "Memory mapping of IntVector copy..." << endl;
    print_memory(v_copy);
    cout << endl;

    return 0;
}

void print_array_memory(int *arr,int size) {
    int diff = 0;
    for (unsigned i = 0;i < size-1;i++) {
        cout << i << ": (" << &arr[i] << ") " << arr[i];
        if (diff != 0) {
            cout << "\t(" << diff << ")";
        }
        diff = abs(reinterpret_cast<char*>(arr+i+1) - reinterpret_cast<char*>(arr+i));
        cout << endl;
    }
    cout << size-1 << ": (" << &arr[size-1] << ") " << arr[size-1] 
        << "\t(" << diff << ")" << endl;
}

void print_memory(const IntVector &v) {
    // print_memory is a friend of IntVector so we can access the data array directly
    print_array_memory(v.data,v.size());
}

