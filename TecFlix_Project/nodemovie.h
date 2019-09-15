#ifndef NODEMOVIE_H
#define NODEMOVIE_H
#include "movie.h";

class nodemovie
{
    public:
        movie * value;
        nodemovie * next;
        nodemovie * prev;
        nodemovie();
};

#endif // NODEMOVIE_H
