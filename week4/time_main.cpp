#include <iostream>
#include "time.h"

using namespace std;

int main() {
    Time t;
    cout << "t  : " << t << endl;
    cout << "t++: " << t++ << endl;
    cout << "++t: " << ++t << endl;
    cout << "t + 65: " << t + 65 << endl;

    return 0;
}
