#include <iostream>
#include <string>
#include "ListTemplate.h"

using namespace std;

int main() {
    List<int> list1;
    for (int i = 2; i < 200; i += i) {
        list1.insert(i);
    }
    cout << "List1: " << list1 << endl;

    for (int i = 1; i < 5; i++) {
        if (list1.search(i)) {
            cout << i << " FOUND" << endl;
        } else {
            cout << i << " NOT FOUND" << endl;
        }
    }

    cout << endl;

    cout << "Remove 4" << endl;
    list1.remove(4);
    cout << "List1: " << list1 << endl;

    for (int i = 1; i < 5; i++) {
        if (list1.search(i)) {
            cout << i << " FOUND" << endl;
        } else {
            cout << i << " NOT FOUND" << endl;
        }
    }

    cout << endl;

    List<char> list2;
    for (int i = 2; i < 200; i += i) {
        int j = 97 + (i % 26);
        char c = j;
        list2.insert(c);
    }
    cout << "List2: " << list2 << endl;

    for (int i = 1; i < 5; i++) {
        int j = 97 + (i % 26);
        char c = j;
        if (list2.search(c)) {
            cout << c << " FOUND" << endl;
        } else {
            cout << c << " NOT FOUND" << endl;
        }
    }

    return 0;
}