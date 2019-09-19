#ifndef LINKEDMOVIE_H
#define LINKEDMOVIE_H
#include "nodemovie.h"

class LinkedMovie
{
private:
    nodemovie *head, *tail;
public:
    int length;
    LinkedMovie(){

        head=NULL;
        tail=NULL;
        length = 0;
    }
    //bool isEmpty();
    void display();
    void append(movie *value);
    nodemovie* GetNth(int n);
    //movie* get(int index);

};

#endif // LINKEDMOVIE_H

