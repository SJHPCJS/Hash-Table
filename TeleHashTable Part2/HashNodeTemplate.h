
#ifndef TELEHASHTABLE_PART2_HASHNODETEMPLATE_H
#define TELEHASHTABLE_PART2_HASHNODETEMPLATE_H

#include<iostream>
#include "HashNode.h"

template<class T1, class T2>
HashNode<T1, T2>::HashNode() {
    key = "";
    value = "";
}

template<class T1, class T2>
HashNode<T1, T2>::HashNode(T1 k, T2 v) {
    this->key = k;
    this->value = v;
}

/**
 * Overload the == operator
 */
template<class T1, class T2>
bool HashNode<T1, T2>::operator==(const HashNode<T1, T2> &oldnode) {
    return key == oldnode.key;
}

/**
 * Overload the != operator
 */
template<class T1, class T2>
bool HashNode<T1, T2>::operator!=(const HashNode<T1, T2> &oldnode) {
    return key != oldnode.key;
}

/**
 * Get the key
 */
template<class T1, class T2>
T1 HashNode<T1, T2>::getKey() {
    return key;
}

/**
 * Set the value
 */
template<class T1, class T2>
void HashNode<T1, T2>::setValue(T2 v) {
    value = v;
}

/**
 * Get the value
 */
template<class T1, class T2>
T2 HashNode<T1, T2>::getValue() {
    return value;
}

/**
 * Overload the << operator
 */
template<class T1, class T2>
std::ostream &operator<<(std::ostream &output, const HashNode<T1, T2> &hn) {
    output << hn.key << ":" << hn.value;
    return output;
}

#endif //TELEHASHTABLE_PART2_HASHNODETEMPLATE_H
