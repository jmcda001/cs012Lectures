#include <iostream>
#include <chrono>

using namespace std;

int factorial(int);
int factorial_iterative(int);

int main() {
    {
        int num = 0;
        cout << "Recursive: " << num << "! = " << factorial(num) << endl;
        cout << "Iterative: " << num << "! = " << factorial_iterative(num) << endl;
    }
    {
        int num = 5;
        cout << "Recursive: " << num << "! = " << factorial(num) << endl;
        cout << "Iterative: " << num << "! = " << factorial_iterative(num) << endl;
    }
    {
        int num = 10;
        cout << "Recursive: " << num << "! = " << factorial(num) << endl;
        cout << "Iterative: " << num << "! = " << factorial_iterative(num) << endl;
    }

    return 0;
}

/* Factorial: n! = n * (n - 1)!
4! = 4 * 3!
3! = 3 * 2!
2! = 2 * 1!
1! = 1
0! = 1
*/
int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n-1);
}

int factorial_iterative(int n) {
    int fact = 1;
    for (int i = 1;i <= n;++i) {
        fact *= i;
    }
    return fact;
}
