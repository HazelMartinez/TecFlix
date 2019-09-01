#include "listnode.h"

template <typename T>
listnode<T>::listnode(T dataIn)
{
    data = dataIn; //stores data in node
    nextPtr = 0; //initializes point to next node to null
}

template <typename T>
T listnode<T>::getData() //returns data stored in node
{
    return data;
}
