#include <iostream>

using namespace std;

double arrayMax(const double arr[],int size);
void displayArray(const double arr[],int size);

int main() {
    {
        const int SIZE = 4;
        double arr[] = {4, 7, 1, 5};
        cout << "Max of ";
        displayArray(arr,SIZE);
        cout << ": " << arrayMax(arr,SIZE) << endl;
    }
    {
        const int SIZE = 6;
        double arr[] = {-3.1, -2.4, -6.7, -9.2, -4.0, -4.1 };
        cout << "Max of ";
        displayArray(arr,SIZE);
        cout << ": " << arrayMax(arr,SIZE) << endl;
    }
    {
        const int SIZE = 7;
        double arr[] = {1, 3, 6, 2, -2, 4, 5};
        cout << "Max of ";
        displayArray(arr,SIZE);
        cout << ": " << arrayMax(arr,SIZE) << endl;
    }
    {
        const int SIZE = 1;
        double arr[] = {-4.2};
        cout << "Max of ";
        displayArray(arr,SIZE);
        cout << ": " << arrayMax(arr,SIZE) << endl;
    }
    {
        const int SIZE = 7;
        double arr[] = {11, 6, 3, 2, -2, 4, 15};
        cout << "Max of ";
        displayArray(arr,SIZE);
        cout << ": " << arrayMax(arr,SIZE) << endl;
    }
    return 0;
}

double arrayMax(const double arr[],int size) {
    //cout << '\t';
    //displayArray(arr,size);
    //cout << endl;
    if (size == 1) { // Base case
        return arr[0]; 
    } 
    if (arr[0] > arr[size-1]) { 
        return arrayMax(arr,size - 1);
    }
    return arrayMax(arr + 1,size - 1);
}

void displayArray(const double arr[],int size) {
    if (size == 0) { 
        cout << "{ }";
        return;
    }
    cout << '{' << arr[0];
    for (int i = 1;i < size;++i) {
        cout << ',' << arr[i];
    }
    cout << '}';
}

