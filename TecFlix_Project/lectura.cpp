#include "lectura.h"
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include "Linked_List.h"
#include "movie.h"
using namespace std;

Lectura::Lectura()
{

}


void Lectura::lectura(){
    //ifstream ip("/home/hazel/Escritorio/Datos2_TecFlix/TecFlix/TecFlix_Project/movie_metadata.csv");
    ifstream archivocsv;
    //string texto; //para dar lectura al archivo, aca se guardaran las palabras

    archivocsv.open("/home/hazel/Escritorio/TecFlix_Proyecto1/TecFlix/TecFlix_Project/movie_metadata.csv", ios::in); //abrimos el archivo en modo lectura

    if(archivocsv.fail()){
        cout<<"No se pudo abrir el archivo";
        exit(1);
    }
    /*
    string color;
    string directorName;
    string num_critic_for_reviews;
    string duration;
    string director_facebook_likes;
    string actor_3_facebook_likes;
    string actor_2_name;
    string actor_1_facebook_likes;
    string gross;
    string genres;
    string actor_1_name;
    string movie_title;
    string num_voted_users;
    string cast_total_facebook_likes;
    string actor_3_name;
    string facenumber_in_poster;
    string plot_keywords;
    string movie_imdb_link;
    string num_user_for_reviews;
    string language;
    string country,content_rating;
    string budget;
    string title_year;
    string actor_2_facebook_likes;
    string imdb_score;
    string aspect_ratio;
    string movie_facebook_likes;

*/

    string completeLine;

//    while(!archivocsv.eof()){
    int contador=0;
    int indice = 0;

    Linked_List<movie*> *lista_peliculas;


    for(int i = 0; !archivocsv.eof(); i++){
        getline(archivocsv, completeLine);
        string delimiter = ",";
        size_t pos= 0;
        string token;
        string data;
        movie* pelicula = new movie();//en cada linea se crea pelicula

        if (i == 2){
        while ((pos = completeLine.find(delimiter)) != string::npos) {
            // npos indicar cuando llegamos
            //definir un contador
            //hacer un objeto, si es 0 a color
            token = completeLine.substr(0, pos);
            //cout << token << std::endl;
            completeLine.erase(0, pos + delimiter.length());
            if(indice == 1){
                pelicula->directorName = token;
            }
            if(indice == 3){
                pelicula->duration = token;
            }
            if(indice == 11){
                pelicula->movie_title = token;
            }
            if(indice == 17){
                pelicula->movie_imdb_link=token;
                token= "google-chrome " + token;
                const char * url = token.c_str();
                system(url);
            }
            indice++;
        }
        indice = 0;
        //lista_peliculas->append(*pelicula);

        //pelicula->imprimir();

        //cout << completeLine << endl;
        } /*else{
            while ((pos = completeLine.find(delimiter)) != string::npos) {

            data = completeLine.substr(0,pos);
            cout<<"Esto es data: "<<data<<endl;
            generic_int_linked_list->append(data);
            completeLine.erase(0, pos + delimiter.length());
            }
         }*/

        //cout<< "NUEVO COMPLETELINE"<< i<<endl;
      contador=i;



//get line de complete line getline(completeline,directorName,)
      /*getline(archivocsv,directorName,',');
      getline(archivocsv,num_critic_for_reviews,',');
      getline(archivocsv,duration,',');
      getline(archivocsv,director_facebook_likes,',');
      getline(archivocsv,actor_3_facebook_likes,',');
      getline(archivocsv,actor_2_name,',');
      getline(archivocsv,actor_1_facebook_likes,',');
      getline(archivocsv,gross,',');
      getline(archivocsv,genres,',');
      getline(archivocsv,actor_1_name,',');
      getline(archivocsv,movie_title,',');
      getline(archivocsv,num_voted_users,',');
      getline(archivocsv,cast_total_facebook_likes,',');
      getline(archivocsv,actor_3_name,',');
      getline(archivocsv,facenumber_in_poster,',');
      getline(archivocsv,plot_keywords,',');
      getline(archivocsv,movie_imdb_link,',');
      getline(archivocsv,num_user_for_reviews,',');
      getline(archivocsv,language,',');
      getline(archivocsv,country, ',');
      getline(archivocsv,content_rating,',');
      getline(archivocsv,budget,',');
      getline(archivocsv,title_year,',');
      getline(archivocsv,actor_2_facebook_likes,',');
      getline(archivocsv,imdb_score,',');
      getline(archivocsv,aspect_ratio,',');
      getline(archivocsv,movie_facebook_likes,',');*/

      /*std::cout << "Color: "<< color<< '\n';
      std::cout << "Director Name: "<< directorName <<'\n';
      std::cout << "Number Critics for review: "<< num_critic_for_reviews<< '\n';
      std::cout << "Duration: "<< duration<<'\n';
      std::cout << "Director facebook likes,: "<< director_facebook_likes<< '\n';
      std::cout << "Actor3 facebook likes: "<< actor_3_facebook_likes<<'\n';
      std::cout << "Actor2 name: "<< actor_2_name<< '\n';
      std::cout << "Actor1 facebook likes: "<< actor_1_facebook_likes<<'\n';
      std::cout << "Gross: "<< gross<< '\n';
      std::cout << "Genres: "<< genres<<'\n';
      std::cout << "Actor1 name: "<< actor_1_name<< '\n';
      std::cout << "Movie Title: "<< movie_title<<'\n';
      std::cout << "Num Voted Users: "<< num_voted_users<< '\n';
      std::cout << "Cast Total Facebook Likes: "<<cast_total_facebook_likes <<'\n';
      std::cout << "Actor3 Name: "<< actor_3_name<< '\n';
      std::cout << "Facenumber in poster: "<< facenumber_in_poster<<'\n';
      std::cout << "Plot Keywords: "<< plot_keywords<< '\n';
      std::cout << "Movie IMBD link: "<< movie_imdb_link<<'\n';
      std::cout << "Num user for Reviews: "<< num_user_for_reviews<< '\n';
      std::cout << "Language: "<< language<<'\n';
      std::cout << "Country" << country<< '\n';
      std::cout << "content_rating: "<< content_rating<< '\n';
      std::cout << "Budget: "<< budget<<'\n';
      std::cout << "Title Year: "<< title_year<< '\n';
      std::cout << "actor_2_facebook_likes: "<< actor_2_facebook_likes<<'\n';
      std::cout << "IMBD Score: "<< imdb_score<< '\n';
      std::cout << "Aspect Ratio: "<< aspect_ratio <<'\n';
      std::cout << "movie_facebook_likes: "<<movie_facebook_likes<<'\n';
      std::cout << "-------------------" << '\n';
      cout<< "El numero de elementos es: " <<i<<endl;*/

    }
    cout << "Cantidad: "<<contador<<'\n';
    /*
    while(!archivocsv.eof()){
        getline(archivocsv, texto);//copiamos el contenido del acrhivo en texto
        cout<<texto<<endl;//mostramos el texto
    }
    */
    archivocsv.close();//se cierra el archivo
}


