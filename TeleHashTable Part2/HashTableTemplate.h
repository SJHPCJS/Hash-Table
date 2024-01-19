
#ifndef TELEHASHTABLE_PART2_HASHTABLETEMPLATE_H
#define TELEHASHTABLE_PART2_HASHTABLETEMPLATE_H

#include "HashTable.h"
#include<iostream>

using namespace std;
/**
 * Construct a new Hash Table<: Hash Table object
 */
template<class T1, class T2>
HashTable<T1, T2>::HashTable() {
    this->size = 10;
    table = new List<HashNode<T1, T2>>[this->size];
}

/**
 * Construct a new Hash Table<: Hash Table object
 */
template<class T1, class T2>
HashTable<T1, T2>::HashTable(int tablesize) {
    this->tablesize = tablesize;
    table = new List<HashNode<T1, T2>>[this->tablesize];
}

/**
 * Destroy the Hash Table<: Hash Table object
 */
template<class T1, class T2>
HashTable<T1, T2>::~HashTable() {
}

/**
 * Hash Function
 */
template<class T1, class T2>
int HashTable<T1, T2>::hashFunction(T1 k) {
    int sum = 0;
    for (char ch : k) {
        sum += int(ch);
    }
    return sum % tablesize;
}

/**
 * Insert a new element into the Hash Table
 */
template<class T1, class T2>
bool HashTable<T1, T2>::insert(T1 k, T2 v) {
    int index = hashFunction(k);
    HashNode <T1, T2> hn(k, v);
    if (table[index].search(hn)) {
        return false;
    } else {

        table[index].insert(hn);
        return true;
    }
}

/**
 * Update an element in the Hash Table
 */
template <class T1, class T2>
bool HashTable<T1,T2>::update(T1 k, T2 v){
    int index = hashFunction(k);

    HashNode<T1, T2> searchNode(k,v);
    if (table[index].search(searchNode)) {
        table[index].remove(searchNode);
        table[index].insert(HashNode<T1, T2>(k,v));
        return true;
    }else {
        return false;
    }
}

/**
 * Lookup an element in the Hash Table
 */
template <class T1, class T2>
bool HashTable<T1,T2>::lookup(T1 k, T2 &v){
    int index = hashFunction(k);

    HashNode<T1, T2> searchNode(k,v);
    if(table[index].search(searchNode)) {
        v = searchNode.getValue();
        return true;
    } else{
        return false;
    }
}

/**
 * Overload the << operator to print the Hash Table
 */
template<class T1, class T2>
std::ostream &operator<<(std::ostream &output, const HashTable<T1, T2> &ht) {
    for (int i = 0; i < ht.tablesize; i++) {
        output << i << " [ " << ht.table[i] <<" ]" << endl;
    }
    return output;
}

#endif //TELEHASHTABLE_PART2_HASHTABLETEMPLATE_H
