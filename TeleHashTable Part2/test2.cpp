#include <iostream>
#include <string>
#include "ListTemplate.h"
#include "HashNodeTemplate.h"

using namespace std;

int main() {
    string names[8] = {"Alice", "Bob", "Chris", "Denise", "Ellen", "Fred", "George", "Hannah"};
    string exts[8] = {"123", "234", "345", "456", "567", "678", "789", "890"};
    int ages[8] = {21, 32, 43, 54, 65, 76, 87, 98};

    List<HashNode<string, string>> mylist1;
    for (int i = 0; i < 8; i++) {
        HashNode<string, string> h(names[i], exts[i]);
        mylist1.insert(h);
    }

    List<HashNode<string, int>> mylist2;
    for (int i = 0; i < 8; i++) {
        HashNode<string, int> h(names[i], ages[i]);
        mylist2.insert(h);
    }

    cout << "mylist1: " << mylist1 << endl;
    cout << "mylist2: " << mylist2 << endl;

    string searches[2] = {"Alice", "Andy"};
    for (int i = 0; i < 2; i++) {
        HashNode<string, string> h1(searches[i], "");
        if (mylist1.search(h1)) {
            cout << "mylist1: " << h1 << " FOUND" << endl;
        } else {
            cout << "mylist1: " << h1 << " NOT FOUND" << endl;
        }

        HashNode<string, int> h2(searches[i], 0);
        if (mylist2.search(h2)) {
            cout << "mylist2: " << h2 << " FOUND" << endl;
        } else {
            cout << "mylist2: " << h2 << " NOT FOUND" << endl;
        }
    }

    return 0;
}