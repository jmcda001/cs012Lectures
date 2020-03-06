#include "IntList.h"
#include <iostream>

using namespace std;

int main() {
    IntList list1;
    list1.push_front(11);
    list1.push_front(8);
    list1.push_front(5);
    list1.push_front(3);

    list1.printReverse();
    cout << endl;

    int sum = list1.sum();
    cout << "Sum: " << sum << endl;

    IntList list2;
    sum = list2.sum();
    cout << "Sum: " << sum << endl;

    list2.printReverse();
    cout << endl;

    return 0;
}

int IntList::sum() const {
    return sum(head);
}

int IntList::sum(IntNode *curr) const {
    if (curr == nullptr) {
        return 0;
    }
    return curr->data + sum(curr->next);
}

void IntList::printReverse() const {
    if (head == nullptr) {
        cout << "{ }";
        return;
    }
    cout << "{";
    printReverseRecurse(head->next);
    cout << head->data << "}";
}

void IntList::printReverseRecurse(IntNode* curr) const {
    if (curr == nullptr) {
        return;
    }
    printReverseRecurse(curr->next);
    cout << curr->data << ',';
    return;
}
