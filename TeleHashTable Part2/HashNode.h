
#ifndef TELEHASHTABLE_PART2_HASHNODE_H
#define TELEHASHTABLE_PART2_HASHNODE_H

#include<string>
#include<iostream>

using namespace std;


template<class T1, class T2>
class HashNode;

template<class T1, class T2>
ostream &operator<<(ostream &, const HashNode<T1, T2> &);

template<class T1, class T2>
class HashNode {
private:
    T1 key;
    T2 value;
public:
    HashNode();

    HashNode(T1 k, T2 v);

    bool operator==(const HashNode<T1, T2> &othernode);

    bool operator!=(const HashNode<T1, T2> &othernode);

    T1 getKey();

    T2 getValue();

    void setValue(T2 v);

    friend ostream &operator<<<T1, T2>(ostream &, const HashNode<T1, T2> &);
};

#endif //TELEHASHTABLE_PART2_HASHNODE_H
