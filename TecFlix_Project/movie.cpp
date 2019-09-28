#include "movie.h"
#include <iostream>
#include <cstdlib>
using namespace std;


movie::movie()
{
    this->directorName = ""; //mostrar 1
    this->num_critic_for_reviews = "";
    this->duration = ""; //mostrar 3
    this->director_facebook_likes= "";
    this->actor_3_facebook_likes = "";
    this->actor_2_name = "";
    this->actor_1_facebook_likes = "";
    this->gross = "";
    this->genres = "";
    this->actor_1_name = "";
    this->movie_title = ""; //mostrar 11
    this->num_voted_users = "";
    this->cast_total_facebook_likes = "";
    this->actor_3_name = "";
    this->facenumber_in_poster = "";
    this->plot_keywords = "";
    this->movie_imdb_link = ""; // mostrar 17
    this->num_user_for_reviews = "";
    this->language = "";
    this->country = "";
    this->content_rating = "";
    this->budget = "";
    this->title_year = "";
    this->actor_2_facebook_likes = "";
    this->imdb_score = "";
    this->aspect_ratio = "";
    this->movie_facebook_likes = "";
    this->completeLine = "";

}

///
/// \brief movie:: este es un metodo para imprimir el contenido de la pelicula
///
void movie::imprimir(){
    cout<<this->directorName<<endl;
    cout<<this->duration<<endl;
    cout<<this->movie_title<<endl;
    cout<<this->movie_imdb_link<<endl;
    cout<<this->imdb_score<<endl;
}

