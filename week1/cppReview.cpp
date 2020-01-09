#include <iostream>
#include <vector>

// Include all definitions from the std namespace. 
// When working with multiple namespaces this can cause naming collisions.
// Including this line won't cause any issues during this quarter (and may be better because of the way the autograding is setup)
//using namespace std;

// Include only the definitions that you will be using
// Alternatively, everywhere you use a definition (e.g. cout), scope it to the namespace: std::cout
using std::cout;
using std::cin;
using std::endl;
using std::vector;

// Function declarations
// <return type> <function name>(<parameter list>); 
// Where <parameter list> is a comma separated ordered list of the types of the parameters 
// (optionally includes parameter name)
//void fillVector(vector<int> v); Passes v in 'by value' (makes a copy). 
// Any changes to v in the function won't affect the vector from the calling context
void fillVector(vector<int>& v); // Pass v 'by reference'
// Any changes to v in the function will appear in the vector from the calling context

void display(const vector<int>& v); // Pass v 'by const ref'
// Any attempt in the function to update the vector v will result in a compiler error
// const ref allows you to force the vector to not be updated, and avoids making a copy, which can be an expensive operation.

int main() {
    int size = 10;
    int default_val = 1;
    // Experiment with the different constructors
    //vector<int> data; // Default vector (empty)
    vector<int> data(size); // Vector of size 'size' (default constructor on int)
    //vector<int> data(size,default_val); // Vector of size 'size' with default value 'default_val')
    cout << data.size() << endl;

    // basic vector functions
    data.push_back(1); // Append the value '1' to the end of the vector
    cout << data.back() << endl; // View the last vale in the vector
    data.pop_back(); // Remove the last value in the vector ('1' in this case)
    // Populating a vector with values between 'a' and 'b'
    int RANGE_a = 1;
    int RANGE_b = 10;
    for (unsigned i = RANGE_a; i < RANGE_b;i++) {
        data.push_back(i);
    }

    // Check the data
    cout << data.size() << endl;
    data.resize(12); // Resize to size 12. If less, fill with default constructor, if more, pop
    cout << data.size() << endl;
    data.resize(20,-1); // Resize function with default (-1)
    cout << data.size() << endl;
    // Display the values 
    for (unsigned i = 0;i < data.size();i++) {
        cout << data.at(i) << ' ';
    }
    cout << endl;
    // display(data); cout << endl;

    return 0;
}

void fillVector(vector<int> &v) {
    int entry;
    cout << "Enter values for the vector (q to quit): ";
    while (cin >> entry) { // Breaks cin, but acceptable until next week when we cover streams in more detail
        v.push_back(entry);
    }
}

// Notice the lack of endl after. Sometimes you want to output "{ <vector contents> }" and you can't if you endl in the function
void display(const vector<int>& v) {
    for (unsigned i = 0;i < v.size();i++) {
        cout << v.at(i) << ' ';
    }
}
