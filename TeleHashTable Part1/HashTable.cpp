/*
 * Name: Jiashuo Chang
 * ID: 2542762 (7802220127)
 * Module code: DI21011
 */

#include "HashTable.h"
#include <iostream>

using namespace std;

HashTable::HashTable() {
    tablesize = 10;
    table = new HashNode[10];
}

HashTable::HashTable(int size) {
    tablesize = size;
    table = new HashNode[size];
}

HashTable::~HashTable() {
    delete[] table;
}

/**
 * A method using as hash function.
 * It uses the total value of string (in ASCII) as the value to calculate the index.
 */
int HashTable::hashFunction(string k) {
    int sum = 0;
    for (char ch: k) {
        sum += int(ch);
    }
    return sum % tablesize;
}

/**
 * A method to insert the node using linear probing.
 */
bool HashTable::insert(string k, string v) {
    int index = hashFunction(k);

    if (index >= 0 && index < tablesize) {
        int distance = 0;

        while (!table[index].getKey().empty()) {
            int currentDistance = (index - hashFunction(table[index].getKey()) + tablesize) % tablesize;

            if (currentDistance >= distance) {
                HashNode temp = table[index];
                table[index] = HashNode(k, v);
                k = temp.getKey();
                v = temp.getValue();
                distance = currentDistance + 1;
            }

            index = (index + 1) % tablesize;
        }

        table[index] = HashNode(k, v);
        return true;
    }

    return false;
}

/**
 * A method to search the index by key.
 */
int HashTable::search(string k) {
    int index = hashFunction(k);

    if (index >= 0 && index < tablesize) {
        int distance = 0;

        while (!table[index].getKey().empty()) {
            if (table[index].getKey() == k) {
                return index;
            }

            index = (index + 1) % tablesize;
            distance++;
        }
    }

    return -1;
}

/**
 * A method to update the value of the existed node.
 */
bool HashTable::update(string k, string v) {
    int index = search(k);

    if (index != -1) {
        table[index].setValue(v);
        return true;
    }

    return false;
}

/**
 * A method to look up the value by key.
 */
string HashTable::lookup(string k) {
    int index = search(k);

    if (index != -1) {
        return table[index].getValue();
    } else {
        return "Key NOT found!";
    }
}

/**
 * Overload the output operator, prints "index: key:value" with newline
 */
ostream &operator<<(ostream &output, const HashTable &ht) {
    for (int i = 0; i < ht.tablesize; ++i) {
        output << i << ": " << ht.table[i] << endl;
    }
    return output;
}