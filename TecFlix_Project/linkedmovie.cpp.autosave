#include "linkedmovie.h"

///
/// \brief LinkedMovie::append metodo que permite agregar peliculas a la lista enlazada
/// \param value representa el valor por agregar
/// modificado de: http://www.cplusplus.com/articles/E3wTURfi/
///
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
    this->length++;
}


///
/// \brief LinkedMovie::display metodo que permite observar lo que contiene la lista de peliculas
/// tomado de:   http://www.cplusplus.com/articles/E3wTURfi/
///
void LinkedMovie::display () {

    nodemovie *display_node=new nodemovie();
    display_node=head;

    while(display_node!=NULL) {
        std::cout<<display_node->value->directorName<<"\n";
        std::cout<<display_node->value->duration<<"\n";
        std::cout<<display_node->value->movie_imdb_link<<"\n";
        std::cout<<display_node->value->movie_title<<"\n";
        std::cout<<display_node->value->imdb_score<<"\n";
        std::cout<<display_node->value->language<<"\n";
        std::cout<<display_node->value->country<<"\n";
        std::cout<<"---------------------------------------------"<<"\n";
        display_node=display_node->next;
    }
}

///
/// \brief LinkedMovie::GetNth metodo que permite obtener un respectivo nodo de la lista
/// \param n el indice del nodo por accesar
/// \return un objeto tipo nodo de pelicula
///
nodemovie* LinkedMovie::GetNth(int n)
{
    int contador = 0;
    nodemovie *display_node=new nodemovie();
    display_node=head;

    while(contador < n) {

        display_node=display_node->next;
        contador++;
    }
    return display_node;
}


