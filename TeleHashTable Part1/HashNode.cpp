/**
 * Name: Jiashuo Chang
 * ID: 2542762 (7802220127)
 * Module code: DI21011
 */

#include <iostream>
#include "HashNode.h"

/**
 * Default constructor, initializes key and value to empty strings
 */
HashNode::HashNode() {
    key = "";
    value = "";
}

/**
 * Parameterized constructor, sets key and value to given values
 */
HashNode::HashNode(string k, string v) {
    key = k;
    value = v;
}

/**
 * Get the value of the key
 */
string HashNode::getKey() {
    return key;
}

/**
 * Set the value of the value
 */
void HashNode::setValue(string v) {
    value = v;
}

/**
 * Pget the value of the value
 */
string HashNode::getValue() {
    return value;
}

/**
 * Overload the output operator, prints "key:value" without newline
 */
ostream &operator<<(ostream &output, const HashNode &hn) {
    output << hn.key << ":" << hn.value;
    return output;
}
