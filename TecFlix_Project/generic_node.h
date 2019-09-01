#ifndef GENERIC_NODE_H
#define GENERIC_NODE_H


template <class T>
struct generic_node {
    T data;

    struct generic_node *next;
    struct generic_node *prev;
};

#endif // GENERIC_NODE_H
