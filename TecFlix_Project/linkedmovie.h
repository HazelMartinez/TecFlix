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
    /**
     * @brief display
     */
    void display();

    /**
     * @brief append
     * @param value
     */
    void append(movie *value);

    /**
     * @brief GetNth
     * @param n
     * @return
     */
    nodemovie* GetNth(int n);
    //movie* get(int index);

};

#endif // LINKEDMOVIE_H

