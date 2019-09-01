#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <iostream>
#include "generic_node.h"
template <class T>
class Linked_List {

private:

    generic_node<T> *head, *tail;

public:

    Linked_List<T>() {
        head = NULL;
        tail = NULL;
    }

    bool isEmpty();
    void display();
    void append(T value);
};

#endif // LINKED_LIST_H



