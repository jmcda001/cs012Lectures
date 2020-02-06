#include <iostream>

using namespace std;

void display_array(const int arr[],unsigned int size) {
    for (unsigned int i = 0;i < size;i++) {
        cout << arr[i] << ' ';
    }
}

int main() {
    //int arr[]; // Compiler error "error: storage size of 'arr' isn't known"
    //int arr[] = {1, 2, 3, 4, 5};
    //int arr[5] = {1, 2, 3, 4, 5}; // Just right
    //int arr[4] = {1, 2, 3, 4, 5}; // Compiler error "error: too many initializers for 'int [4]'
    int arr[10] = {1, 2, 3, 4, 5}; // too few
    //int arr[10]; // Array is not populated (contains junk values)
    //display_array(arr,10); cout << endl;
    display_array(arr,11); cout << endl; // Outputs after array max. What is that?
    arr[10] = -1; // Caused: *** stack smashing detected ***: <unknown> terminated
                  // Aborted (core dumped)
    display_array(arr,11); cout << endl; // Outputs after array max. What is that?
    return 0;

    /* ICE */
    const int ARRCAP = 10;
    unsigned int size = 0;

    int arr_capped[ARRCAP]; // = {0}; will set all values to 0 initially
    int entry;
    cout << "Enter numbers separated by spaces for the array: ";
    while (size < ARRCAP && cin >> entry) {
        arr_capped[size] = entry;
        size++;
    }
    for (unsigned int i = 0;i < size;i++) {
        cout << arr_capped[i] << ' ';
    }
    cout << endl;

    return 0;
}
