
#ifndef TELEHASHTABLE_PART2_LISTTEMPLATE_H
#define TELEHASHTABLE_PART2_LISTTEMPLATE_H

#include "List.h"

// Constructor
template<class Type>
List<Type>::List() : Head(nullptr) {
}

// Destructor

template<class Type>
List<Type>::~List() {
    Node *temp;
    while (Head != nullptr) {
        temp = Head;
        Head = Head->Next;
        delete temp;
    }
}

// Empty

template<class Type>
bool List<Type>::empty() const {
    return (Head == nullptr);
}

// Delete

template<class Type>
bool List<Type>::remove(const Type &del_element) {
    if (empty()) {
        return false;
    } else {
        Node *temp = Head;
        Node *prev = nullptr;
        while ((temp->Element != del_element) && (temp->Next != nullptr)) {
            prev = temp;
            temp = temp->Next;
        }
        if (temp->Element == del_element) {
            if (prev == nullptr) {
                Head = Head->Next;
            } else {
                prev->Next = temp->Next;
            }
            delete temp;
            return true;
        } else {
            return false;
        }
    }
}

// Search

template<class Type>
bool List<Type>::search(Type &search_element) {
    if (empty()) {
        return false;
    } else {
        Node *temp = Head;
        while ((temp->Element != search_element) && (temp->Next != nullptr)) {
            temp = temp->Next;
        }
        if (temp->Element == search_element) {
            search_element = temp->Element;
            return true;
        } else {
            return false;
        }
    }
}

// Insert (simple insert at beginning)

template<class Type>
bool List<Type>::insert(const Type &new_element) {
    if (empty()) {
        Head = new Node(new_element);
        return true;
    } else {
        Node *temp = new Node(new_element, Head);
        Head = temp;
        return true;
    }
}

template<class Type>
ostream &operator<<(ostream &out_stream, const List<Type> &out_list) {
    typename List<Type>::Node *temp = out_list.Head;
    while (temp != nullptr) {
        out_stream << temp->Element << " ";
        temp = temp->Next;
    }
    return out_stream;
}

#endif //TELEHASHTABLE_PART2_LISTTEMPLATE_H
