#ifndef LINKEDMOVIE_H
#define LINKEDMOVIE_H
#include "nodemovie.h"

class LinkedMovie
{
private:
    nodemovie *head, *tail;
public:
    LinkedMovie(){

        head=NULL;
        tail=NULL;
    }
    //bool isEmpty();
    void display();
    void append(movie *value);

};

#endif // LINKEDMOVIE_H

