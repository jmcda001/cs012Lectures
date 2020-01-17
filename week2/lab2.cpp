#include <iostream>

using namespace std;

int main() {
    string fn;
    cout << "Enter filename: ";
    cin >> fn;

    read_csv(fn);

    return 0;
}

void read_csv(string fn) {
    ifstream fin(fn);
    if (!fin.is_open()) {
        exit(1);
    }

    char ch;
    int n;
    while (cin >> n) {
        // Process n
        cout << n << ' ';
        cin.ignore(); // 1st Parameter is how many characters to ignore, second is the delimiter
    }
}

