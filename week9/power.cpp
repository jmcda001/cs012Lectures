#include <iostream>

using namespace std;

double powerTo(double x,int y);

int main() {
    {
        int x = 2;
        int y = 3;
        cout << x << "^" << y << " = " << powerTo(x,y) << endl;
    }
    {
        int x = 3;
        int y = 2;
        cout << x << "^" << y << " = " << powerTo(x,y) << endl;
    }
    return 0;
}

double powerTo(double x,int y) {
    if (y == 0) {
        return 1;
    }
    return x * powerTo(x,y-1);
}

