#include "lectura.h"
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include "Linked_List.h"
#include "movie.h"
#include "linkedmovie.h"
using namespace std;

Lectura::Lectura()
{

}

///
/// \brief Lectura::lectura metodo de prueba para leer el archivo csv
///
void Lectura::lectura(){
    //ifstream ip("/home/hazel/Escritorio/Datos2_TecFlix/TecFlix/TecFlix_Project/movie_metadata.csv");
    ifstream archivocsv;
    //string texto; //para dar lectura al archivo, aca se guardaran las palabras

    archivocsv.open("/home/hazel/Escritorio/TecFlix_Proyecto1/TecFlix/TecFlix_Project/movie_metadata.csv", ios::in); //abrimos el archivo en modo lectura

    if(archivocsv.fail()){
        cout<<"No se pudo abrir el archivo";
        exit(1);
    }

    string completeLine;
    int contador=0;
    int indice = 0;
    //Linked_List<movie> *lista_peliculas=new lista_peliculas<movie>();
    Linked_List<movie> *generic_int_linked_list = new Linked_List<movie>();
    LinkedMovie *lista_peliculas= new LinkedMovie();
    for(int i = 0; !archivocsv.eof(); i++){
        getline(archivocsv, completeLine);
        string delimiter = ",";
        size_t pos= 0;
        string token;
        string data;
        movie *pelicula= new movie();//en cada linea se crea pelicula

        if (i < 2){
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
                //system(url);
            }

            if(indice == 19){
                pelicula->language = token;
                //cout << token << std::endl;
            }

            if(indice == 20){
                pelicula->country = token;
            }

            if(indice == 25){
                pelicula->imdb_score = token;
            }

            indice++;
        }
        lista_peliculas->append(pelicula);

        indice = 0;
    }
      contador=i;

    }
    //lista_peliculas->display();
    //cout << "Cantidad: "<<contador<<'\n';
 archivocsv.close();//se cierra el archivo

}

/*
LinkedMovie* Lectura::MostrarDatos(LinkedMovie* manager_actual){


}
*/


