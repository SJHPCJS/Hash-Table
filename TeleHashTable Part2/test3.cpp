#include <iostream>
#include <string>
#include "HashTableTemplate.h"
using namespace std;

int main() {
    string names[11] = {"Alice", "Bob", "Chris", "Denise", "Ellen", "Fred", "George", "Hannah", "Iain", "Jenny", "Kevin"};
    string exts[11] = {"123", "234", "345", "456", "567", "678", "789", "890", "901", "135", "246"};

    HashTable<string,string> abook(13);

    for(int i=0; i<11; i++){
        abook.insert(names[i], exts[i]);
    }

    cout << abook << endl;

    string s = "";
    if(abook.lookup("Alice", s)){
        cout << "Alice has ext #" << s << endl;;
    }

    cout << "Update..." << endl;

    abook.update("Alice", "987");
    if(abook.lookup("Alice", s)){
        cout << "Alice has ext #" << s << endl;;
    }

    return 0;
}
