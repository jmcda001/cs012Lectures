#include <iostream>
#include <fstream>
#include <vector>

#include <chrono>
using namespace std::chrono;

using namespace std;

unsigned int find_min_location(const vector<int> &v,unsigned start_index);
void selection_sort(vector<int> &v); 
bool verify_sorted(const vector<int> &v,bool ascending=false);
void display(const vector<int>& v);

void read_input(ifstream&,vector<int>&,bool=false);

#include "tests.h"

int main(int argc,char* argv[]) {
    run_tests();
    return 0;

    // (1) Hard coded filename (not as useful as you get more advanced)
    string filename = "large_input.txt";
    ifstream fin(filename);
    // (2) Pass filename in as a command line argument (check argc then access argv)
    /*if (argc >= 2) {
        filename = argv[1];
    }
    ifstream fin; 
    fin.open(filename.c_str()); // Pre C++11 standard needs a c string for .open()*/

    // (3) Ask user to enter the filename (may want to check if file exists)
    /* ifstream fin;
    do {
        cout << "Enter the name of the input file: ";
        cin >> filename;
        fin.open(filename);
    } while (!fin.is_open());*/

    // Check if the file is opened properly
    if (!fin.is_open()) {
        cout << "Error opening " << filename << endl;
        exit(1);
    }


    // Read data in from the file and populate a test_input vector
    vector<int> test_input;
    cout << "Reading from " << filename << endl;
    read_input(fin,test_input);

    // Close the file after use (Will close when it goes out of scope, but this is neater)
    cout << "Closing " << filename << endl;
    fin.close();

    cout << "Sorting input..." << endl;
    auto start = high_resolution_clock::now(); // Get time when algorithm starts
    selection_sort(test_input);
    auto stop = high_resolution_clock::now(); // Get time when algorithm completes
    auto duration = duration_cast<seconds>(stop - start); // Calculate the difference
    cout << "Sorting took: " << duration.count() << " s" << endl; // Output the time taken

    // Verify that the sort is correct
    cout << "Verifying sort...";
    if (verify_sorted(test_input)) { cout << "Passed" << endl; } 
    else { cout << "Failed" << endl; }

    return 0;
}

void read_input(ifstream &fin,vector<int> &v,bool csv) {
    int entry;
    // Read integers from fin stream until it fails (EOF or non-numeric character)
    // (1) Use extraction operator (>>) until it fails (typically EOF, unless file data is malformed)
    /*while (fin >> entry) {
        v.push_back(entry);
        // Ignore all characters until a comma [.ignore(n,delim)]
        if (csv) { fin.ignore(numeric_limits<streamsize>::max(),','); } 
        //if (csv) { fin.ignore(); } // Ignore the next character (comma)
        //cout << entry << ' ';
    }*/
    // (2) Check for EOF
    while (!fin.eof()) { // (EOF doesn't fail until after end of file)
        fin >> entry;
        if (fin.good()) { // Check if read was successful before using entry
            v.push_back(entry);
            //cout << entry << ' ';
            if (csv) { fin.ignore(numeric_limits<streamsize>::max(),','); } 
        } else if (!fin.eof()) { // File input incorrect and not end of file
            v.clear();
            cerr << "Error: Input file malformed" << endl;
            return;
        }
    }
    //cout << endl;
}

// We can't manually inspect very large inputs, so it helps to make a function to verify 
// if the vector is sorted. A vector is sorted (ascending) if for every entry i, that entry 
// is larger than the entry before it
bool verify_sorted(const vector<int> &v,bool ascending) {
    for (auto i = 1;i < v.size();i++) {
        if (!ascending && (v.at(i) < v.at(i-1))) {
            return false;
        } else if (ascending && (v.at(i) > v.at(i-1))) {
            return false;
        }
    }
    return true;
}

void selection_sort(vector<int> &v) {
    for (unsigned i = 0;i < v.size();i++) {
        // Uses the standard swap function
        swap(v.at(i),v.at(find_min_location(v,i)));
    }
}

unsigned int find_min_location(const vector<int> &v,unsigned start_index) {
    if (start_index > v.size()) {
        return -1;
    }
    int min_index = start_index;
    for (unsigned i = start_index+1 /* start with 0 */;i < v.size();i++) {
        if (v.at(i) < v.at(min_index)) {
            min_index = i;
        }
    }
    return min_index;
}

void display(const vector<int>& v) {
    for (unsigned i = 0;i < v.size();i++) {
        cout << v.at(i) << ' ';
    }
}

