
#ifndef TELEHASHTABLE_PART2_LIST_H
#define TELEHASHTABLE_PART2_LIST_H

#include <iostream>

using namespace std;

template<class Type>
class List;

template<class Type>
ostream &operator<<(ostream &, const List<Type> &);

template<class Type>
class List {
protected:
    class Node {
    public:
        Type Element;
        Node *Next;

        Node() : Next(nullptr) {}

        Node(Type data, Node *pnode = nullptr) :
                Element(data), Next(pnode) {}
    };

    Node *Head;
public:
    List();

    virtual ~List();

    virtual bool empty() const;

    virtual bool insert(const Type &new_element);

    virtual bool remove(const Type &del_element);

    virtual bool search(Type &search_element);

    friend ostream &operator<<<Type>(ostream &, const List<Type> &);
};

#endif //TELEHASHTABLE_PART2_LIST_H
