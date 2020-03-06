#include <iostream>

using namespace std;

bool isPalindrome(string s);

int main() {
    {
        string word = "mom";
        cout << word;
        if (isPalindrome(word)) {
            cout << " is a palindrome." << endl;
        } else {
            cout << " is not a palindrome." << endl;
        }
    }
    {
        string word = "random";
        cout << word;
        if (isPalindrome(word)) {
            cout << " is a palindrome." << endl;
        } else {
            cout << " is not a palindrome." << endl;
        }
    }
    {
        string word = "Racecar";
        cout << word;
        if (isPalindrome(word)) {
            cout << " is a palindrome." << endl;
        } else {
            cout << " is not a palindrome." << endl;
        }
    }
    {
        string word = "racecar";
        cout << word;
        if (isPalindrome(word)) {
            cout << " is a palindrome." << endl;
        } else {
            cout << " is not a palindrome." << endl;
        }
    }

    return 0;
}

bool isPalindrome(string s) {
    if (s.size() <= 1) {
        return true;
    }
    if (s.front() != s.back()) {
        return false;
    }
    return isPalindrome(s.substr(1,s.size() - 2));
}

