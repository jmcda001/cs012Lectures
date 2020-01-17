// First: Count the number of words (sequence of characters separated by white space)
// Next: Count the number of lines as well
// Next: Count the number of chars as well

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

// Timing specific library/namespace
#include <chrono>
using namespace std::chrono;

// Count words, lines and chars in one loop (ish). 
// Parameter: string filename
void count_together(string);
// Count the words in the string (parameter) using the string stream object. Returns the number of words
int count_words(string);

// Count words, lines and chars in 3 separate loops. 
// Parameter: string filename
void count_individual(string);
// Counts the words in the input filestream
int count_words(ifstream &);
// Counts the lines in the input filestream
int count_lines(ifstream &);
// Counts the chars in the input filestream
int count_chars(ifstream &);
// Resets the input filestream to the beginning, necessary for counting individually
void reset_file(ifstream &);

// Output the data (words, lines, chars)
void print_data(int words,int lines,int chars);

int main() {
    // Hard code input filename (makes it easier for testing purposes)
    string filename = "mlk.txt";

    cout << "Counting individually..." << endl;
    auto start = high_resolution_clock::now();
    count_individual(filename);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Took " << duration.count() << "us\n" << endl;

    cout << "Counting Together..." << endl;
    start = high_resolution_clock::now();
    count_together(filename);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Took " << duration.count() << "us" << endl;

    return 0;
}

void count_together(string fn) {
    // Open input filestream
    ifstream fin(fn);
    // Verify stream opened
    if (!fin.is_open()) {
        cout << "Error: Unable to open " << fn << endl;
        exit(1);
    }

    int lines = 0, words = 0, chars = 0;
    string line;
    while (getline(fin,line)) {
        lines++; // Counts the number of lines
        words += count_words(line); // Counts the number of words on the line
        chars += line.size() + 1; // Counts the number of characters (+1 for newline)
    }

    print_data(words,lines,chars);
}

int count_words(string str) {
    int words = 0;
    string word;
    stringstream ss;
    ss.str(str);
    while (ss >> word) { // Until >> fails (or EOF)
        words++;
    }
    return words;
}

void count_individual(string fn) {
    // Open input filestream
    ifstream fin(fn);
    // Verify stream opened
    if (!fin.is_open()) {
        cout << "Error: Unable to open " << fn << endl;
        exit(1);
    }

    // Count the number of words in file. (group of characters separated by whitespace)
    int words = count_words(fin);
    
    // Count the number of lines
    reset_file(fin); // Need to reset the file first
    int lines = count_lines(fin);

    // Count the number of chars
    reset_file(fin); // Need to reset the file first
    int chars = count_chars(fin);

    // Output the counts to cout
    print_data(words,lines,chars);
}

int count_words(ifstream &fin) {
    int words = 0;
    string word;
    // fin >> <string> tends not to fail unless EOF is reached 
    // as everything in a file can be read as a string (sequence of characters)
    while (fin >> word) { // >> will fail when EOF is reached
        words++;
    }
    return words;
}

int count_lines(ifstream &fin) {
    int lines = 0;
    string line;
    // getline(stream,string) will read up to a newline character 
    // and discard the newline character.
    // The extraction operator (stream >> type) will ignore leading white space
    //      Then read values in as long as they are of the right type
    //      Stops at white space and leaves it in the buffer
    // Combining getline and >> can cause problems. i.e.
    //      cin >> str; // Reads in a string but leaves the newline (or whitespace)
    //      getline(cin,str); // Reads the newline left in and stops
    while (getline(fin,line)) {
        lines++;
    }
    return lines;
}

int count_chars(ifstream &fin) {
    int chars = 0;
    char c;
    // stream.get(c) will get the next character in the buffer (white space included)
    // Stops when reaches EOF (or fails)
    while (fin.get(c)) {
        chars++;
    }
    return chars;
}

void reset_file(ifstream &fin) {
    // (1) Clear the flags, then reset to the beginning of the buffer
    fin.clear(); // Clear the stream
    fin.seekg(0,ios::beg); // Return to beginning of stream
    // (2) Close and reopen the file (needs the filename)
    //fin.close(); 
    //fin.open(filename);
}

void print_data(int words,int lines,int chars) {
    cout << fn << " contains " << words << " words. " << endl;
    cout << fn << " contains " << lines << " lines. " << endl;
    cout << fn << " contains " << chars << " characters. " << endl;
}

