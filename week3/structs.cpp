#include <vector>
#include <iostream> // Don't include at first
#include <string> // Show compiler error when not including this library (or iostream)
#include <limits>

using namespace std;

struct Exam {
    string username;
    double score;
}; // What error occurs when we don't include the ';'

void display(const vector<Exam>&);

int main() {
    int n; // Allocates memory

    Exam ex1; // Allocates memory

    // iostream library includes functions for the << operator on integers.
    // This doesn't work on ex1 because there is no << operator for Exam objects
    //cout << ex1 << endl; // What happens when we do this?
    
    // Show that junk is getting output when uninitialized (string has default constructor) 
    cout << '"' << ex1.username << "\": " << ex1.score << endl; // Access members with . operator

    // Now initialize the values and show it works
    ex1.username = "jmcda001";
    ex1.score = 9.5;
    cout << '"' << ex1.username << "\": " << ex1.score << endl; // Access members with . operator


    vector<Exam> midterm;
    Exam entry;
    cout << "Enter the students username: ";
    getline(cin,entry.username);
    cout << endl;
    while (entry.username != "quit") {
        cout << "Enter the score for " << entry.username << ": ";
        cin >> entry.score;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << endl;
        midterm.push_back(entry);
        cout << "Enter the students username (or 'quit' to quit): ";
        getline(cin,entry.username);
        cout << endl;
    }

    // Write the display function yourself with output format:
    // <username>: <score>
    // jdoe001: 9.5
    // ...
    for (unsigned i = 0;i < midterm.size();i++) {
        cout << '"' << midterm.at(i).username << "\": " 
            << midterm.at(i).score << endl; // Access members with . operator
    }
    display(midterm);

    return 0;
}

void display(const vector<Exam> &v) {
    for (auto ex : v) { // for each
        cout << ex.username << ": " << ex.score << endl;
    }
}
