#ifndef LIST_H
#define LIST_H
#include <iostream>
using namespace std;

#include "listnode.h"

template <typename T>
class List
{
public:
    List();
    ~List();
    void insertNewNode(T); //fucntion used to insert new node in order in the list
    void print(); //prints the contents of the linked list
    listnode<T>* search(T); //searches for a value in the linked list and returns the point to object that contains that value

private:
    listnode<T> *startPtr; //stores the pointer of first object in the linked list
    listnode<T> *endPtr; //stored the pointer of the last object in the linked list
    bool isEmpty(); //utility functions used to see if the list contains no elements
    void insertBegin(T); //inserts new node before the first node in the list
    void insertEnd(T); //inserts new node after the last node in the list
};

#endif // LIST_H

