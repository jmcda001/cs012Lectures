#include <iostream>
#include <iomanip>

using namespace std;

void display(int *arr,int size,bool newline = true) {
    for (int i = 0;i < size;++i) { cout << arr[i] << ' '; }
    if (newline) { cout << endl; }
}

int main() {
    int uninitialized;
    cout << "Uninitialized: " << uninitialized << endl;
    // Declare and initiate integer n and m
    int n = 10;
    int m = 20;
    cout << "Regular variables..." << endl;
    cout << " n: " << n << endl;
    cout << "&n: " << &n << endl;
    cout << endl;
    cout << "  sizeof(n): " << sizeof(n) << endl;
    cout << "sizeof(int): " << sizeof(int) << endl;
    cout << endl;
    //cout << "*n: " << *n << endl; // compiler error (n is not an int *)
    // error: invalid type argument of unary '*' (have 'int')
    cout << " m: " << m << endl;
    cout << "&m: " << &m << endl;
    cout << endl;


    int *uninitializedPtr; // Should be = nullptr
    cout << "uninitializedPtr: " << uninitializedPtr << endl;
    cout << "*uninitializedPtr: " << *uninitializedPtr << endl;
    // Declare an integer pointer intPtr and initializes it to 30
    // <data_type> * <variable_name>; declare a variable as a pointer to type <data_type>
    // n * m; binary operator* (multiplication)
    // *m; unary operator* (dereference)
    int *intPtr = new int(30); 
    cout << "Raw pointers..." << endl;
    cout << setw(35) << "intPtr: (value of intPtr): " << intPtr << endl; // intPtr holds an address
    cout << setw(35) << "*intPtr (value intPtr points to): " << *intPtr << endl; // value at intPtr address
    cout << setw(35) << "&intPtr (address of intPtr): " << &intPtr << endl; // address of intPtr
    cout << setw(35) << "sizeof(intPtr): " << sizeof(intPtr) << endl;
    cout << setw(35) << "sizeof(*intPtr): " << sizeof(*intPtr) << endl;
    cout << endl;
    // Disclaimer: the folowing is an example, not actual values for this program
    // 0x00  -----------
    // 0x01 |  0x03     | intPtr -
    // 0x02 |           |        | points to 0x03
    // 0x03 |  30       |<------- holds value 30
    // 0x04 |           |
    //       -----------
    // &intPtr == 0x01
    // intPtr == 0x03
    // *intPtr == 30

    cout << "delete intPtr..." << endl;
    delete intPtr; // Delete the memory allocated at intPtr (new) before reassigning
    //intPtr = nullptr; // Causes the below to segmentation fault (* and &)
    cout << setw(35) << "intPtr: (value of intPtr): " << intPtr << endl; // intPtr holds an address
    cout << setw(35) << "*intPtr (value intPtr points to): " << *intPtr << endl; // value at intPtr address
    cout << setw(35) << "&intPtr (address of intPtr): " << &intPtr << endl; // address of intPtr
    cout << endl;

    cout << "Pointer pointing to another variable..." << endl;
    intPtr = &n;
    cout << setw(35) << "&intPtr (address of intPtr): " << &intPtr << endl; // address of intPtr
    cout << setw(35) << "intPtr: (value of intPtr): " << intPtr << endl; // intPtr holds an address
    cout << setw(35) << "address of 'n': " << &n << endl;
    cout << setw(35) << "*intPtr (value intPtr points to): " << *intPtr << endl; // value at intPtr address
    cout << setw(35) << "value of 'n': " << n << endl;
    cout << endl;
    cout << "Assigning n to 15..." << endl;
    n = 15;
    cout << setw(35) << "*intPtr (value intPtr points to): " << *intPtr << endl; // value at intPtr address
    cout << setw(35) << "value of 'n': " << n << endl;
    cout << endl;
    cout << "Assigning n to 20 through *intPtr..." << endl;
    *intPtr = 20;
    cout << setw(35) << "*intPtr (value intPtr points to): " << *intPtr << endl; // value at intPtr address
    cout << setw(35) << "value of 'n': " << n << endl;
    cout << endl;
    //delete intPtr; // Delete here fails, intPtr (n) not dynamically allocated
    // munmap_chunk(): invalid pointer
    // Aborted (core dumped)


    // Declare an array as a integer pointer (arrPtr) and as an array (arrArray)
    int *arrPtr = new int[6] {2,4,6,8,10,12};
    int arrArray[6] = {1,3,5,7,9,11};

    cout << "Arrays..." << endl;
    cout << setw(15) << "arrPtr: " << arrPtr << endl;
    cout << setw(15) << "arrPtr + 2: " << arrPtr + 2 << endl; // Notice +2 is +8
    cout << setw(15) << "&arrPtr[2]: " << &arrPtr[2] << endl << endl;

    cout << setw(15) << "arrArray: " << arrArray << endl;
    cout << setw(15) << "arrArray + 2: " << arrArray + 2 << endl; // Notice +2 is +8
    cout << setw(15) << "&arrArray[2]: " << &arrArray[2] << endl;
    cout << endl;

    cout << "arrPtr: ";
    display(arrPtr,6);
    cout << setw(15) << "*(arrPtr + 2): " << *(arrPtr + 2) << endl;
    cout << setw(15) << "arrPtr[2]: " << arrPtr[2] << endl << endl;

    cout << "arrArray: ";
    display(arrArray,6);
    cout << setw(17) << "*(arrArray + 2): " << *(arrArray + 2) << endl;
    cout << setw(17) << "arrArray[2]: " << arrArray[2] << endl;

    cout << "Assigning arrPtr = arrArray..." << endl;
    {
        int *temp = arrPtr;
        arrPtr = arrArray; // arrPtr has leaked here.
        //arrArray = arrPtr; // Compiler error: incompatible types in assignment of 'int*' to 'int [6]'
        cout << setw(10) << "arrArray: " << arrArray << endl;
        cout << setw(10) << "arrPtr: " << arrPtr << endl;
        cout << "What's pointing to " << temp << " now?" << endl;
        delete[] temp; // Free the memory dynamically allocated (new)
    }
    // cout << temp << endl; // Notice the compiler error because it is out of scope.
    cout << endl;
    cout << setw(10) << "arrArray: ";
    display(arrArray,6);
    cout << setw(10) << "arrPtr: ";
    display(arrPtr,6);

    return 0;
}

