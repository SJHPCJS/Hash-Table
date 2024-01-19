
#ifndef TELEHASHTABLE_PART2_HASHTABLE_H
#define TELEHASHTABLE_PART2_HASHTABLE_H

#include "ListTemplate.h"
#include "HashNodeTemplate.h"
#include<string>

using namespace std;

// Forward declaration of templates required for templated friend function
template<class T1, class T2>
class HashTable;

template<class T1, class T2>
ostream &operator<<(ostream &, const HashTable<T1, T2> &);

template<class T1, class T2>
class HashTable {
private:
    int tablesize;
    List <HashNode<T1, T2>> *table;
public:
    HashTable();

    HashTable(int size);

    ~HashTable();

    int hashFunction(T1 k);

    bool insert(T1 k, T2 v);

    bool update(T1 k, T2 v);

    bool lookup(T1 k, T2 &v);

    friend ostream &operator<<<T1, T2>(ostream &, const HashTable<T1, T2> &);

};

#endif //TELEHASHTABLE_PART2_HASHTABLE_H
