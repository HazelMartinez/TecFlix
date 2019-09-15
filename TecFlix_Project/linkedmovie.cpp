#include "linkedmovie.h"


void LinkedMovie::append(movie* value) {

    nodemovie *new_node = new nodemovie();
    new_node->value = value;

    if(head==NULL) {
        // If head is null then list doesn't have any nodes, set head and tail to new node value.
        head=new_node;
        tail=new_node;
        new_node=NULL;
    } else {
        // else set current tail to be previous node on chain before new_node then set current tail next value to new_node
        // finally we set tail to be new node value and discard new_node by setting null.
        new_node->prev = tail;
        tail->next = new_node;
        tail = new_node;
        new_node = NULL;
    }
}

void LinkedMovie::display () {

    nodemovie *display_node=new nodemovie();
    display_node=head;

    while(display_node!=NULL) {
        std::cout<<display_node->value->directorName<<"\n";
        std::cout<<display_node->value->duration<<"\n";
        std::cout<<display_node->value->movie_imdb_link<<"\n";
        std::cout<<display_node->value->movie_title<<"\n";
        std::cout<<"---------------------------------------------"<<"\n";
        display_node=display_node->next;
    }
}

