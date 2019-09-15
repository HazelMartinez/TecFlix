#include "manejodememoria.h"
#include "linkedmovie.h"
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include "movie.h"
#include "linkedmovie.h"
using namespace std;
ManejoDeMemoria::ManejoDeMemoria()
{

}
LinkedMovie* ManejoDeMemoria::CargarPagina(int menor, int mayor){
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
    LinkedMovie *lista_peliculas= new LinkedMovie();
    for(int i = 0; !archivocsv.eof(); i++){
        getline(archivocsv, completeLine);
        string delimiter = ",";
        size_t pos= 0;
        string token;
        string data;
        movie *pelicula= new movie();//en cada linea se crea pelicula

        if (i <= menor || i <mayor ){
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
            indice++;
        }
        lista_peliculas->append(pelicula);

        indice = 0;
    }
      contador=i;

    }
    lista_peliculas->display();
    cout << "Cantidad: "<<contador<<'\n';
 archivocsv.close();//se cierra el archivo


}

void ManejoDeMemoria::CargarAtras(){

}
void ManejoDeMemoria::CargarAdelante(){
    this->next = this->actual;
    this->actual = this->next;
    this->previa= this->next;
}
