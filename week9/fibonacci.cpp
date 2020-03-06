#include <iostream>

using namespace std;

int fibonacci(int);

int main() {
    cout << "fibonacci(0): " << fibonacci(0) << endl;
    cout << "fibonacci(1): " << fibonacci(1) << endl;
    cout << "fibonacci(2): " << fibonacci(2) << endl;
    cout << "fibonacci(3): " << fibonacci(3) << endl;
    cout << "fibonacci(4): " << fibonacci(4) << endl;
    cout << "fibonacci(5): " << fibonacci(5) << endl;
    cout << "fibonacci(6): " << fibonacci(6) << endl;

    return 0;
}


// fibonacci(n) = fibonacci(n-1) + fibonacci(n-2)
// n==0: 1
// n==1: 1
int fibonacci(int n) {
    if (n <= 1) { return 1; }
    return fibonacci(n-1) + fibonacci(n-2);
}
