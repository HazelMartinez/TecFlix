#ifndef LISTNODE_H
#define LISTNODE_H
template <typename T>
class List;

template <typename T>
class listnode
{
    friend class List<T>;

public:
    listnode(T);
    T getData();

private:
    T data; //templatized data stored in node
    listnode* nextPtr; //pointer to the next node in list
};

#endif // LISTNODE_H
