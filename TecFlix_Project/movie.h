#ifndef MOVIE_H
#define MOVIE_H
#include <iostream>
//using namespace std;

class movie
{
public:

    std::string directorName;
    std::string num_critic_for_reviews;
    std::string duration;
    std::string director_facebook_likes;
    std::string actor_3_facebook_likes;
    std::string actor_2_name;
    std::string actor_1_facebook_likes;
    std::string gross;
    std::string genres;
    std::string actor_1_name;
    std::string movie_title;
    std::string num_voted_users;
    std::string cast_total_facebook_likes;
    std::string actor_3_name;
    std::string facenumber_in_poster;
    std::string plot_keywords;
    std::string movie_imdb_link;
    std::string num_user_for_reviews;
    std::string language;
    std::string country;
    std::string content_rating;
    std::string budget;
    std::string title_year;
    std::string actor_2_facebook_likes;
    std::string imdb_score;
    std::string aspect_ratio;
    std::string movie_facebook_likes;
    std::string completeLine;


    void obtener_link_video();
    void muestra_nombre_pelicula_clik();
    void muestra_nombre_autor_clik();
    void muestra_nombre_linkVideo_clik();
    void muestra_nombre_duracion_clik();
    void imprimir();
    movie();

};

#endif // MOVIE_H
