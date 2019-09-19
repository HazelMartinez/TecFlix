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
LinkedMovie* ManejoDeMemoria::CargarPagina(){
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

        if (i >= this->menor && i <this->mayor ){
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
    //lista_peliculas->display();
    //cout << "Cantidad: "<<contador<<'\n';
 archivocsv.close();//se cierra el archivo
    return lista_peliculas;

}

void ManejoDeMemoria::CargarAtras(){
    this->temp = this->actual;
    this->actual = this->previa;
    this->next = this->actual;
    this->previa = CargarPagina();
}
void ManejoDeMemoria::CargarAdelante(){
    this->temp = this->actual;
    this->actual = this->next;
    this->previa = this->temp;
    this->next = CargarPagina();
}
void ManejoDeMemoria::setmayor(int mayor){
    this->mayor=mayor;
}
void ManejoDeMemoria::setmenor(int menor){
    this->menor=menor;
}
void ManejoDeMemoria::CargarInicial(int cantidadPeliculas){
    this->actual=CargarPagina();
    this->menor=this->mayor;
    this->mayor=this->mayor+cantidadPeliculas;
    this->next=CargarPagina();
    this->previa=NULL;
    //this->actual->display();

}
LinkedMovie* ManejoDeMemoria::getActual(){
    return this->actual;
}
LinkedMovie* ManejoDeMemoria::getNext(){
    return this->next;
}
LinkedMovie* ManejoDeMemoria::getPrevia(){
    return this->previa;
}
int ManejoDeMemoria::getmayor(){
    return this->mayor;
}
int ManejoDeMemoria::getmenor(){
    return this->menor;
}
LinkedMovie* ManejoDeMemoria::mostrar_datos(LinkedMovie* controlador_actual){
    //cout<<controlador_actual->length<<endl;
    //LinkedMovie* lista_pelicula_individual = new LinkedMovie();//lista de las peliculas individuales
    movie * pelicula_individual = new movie(); //los datos de la pelicula
    int contador = 0; //contador para obtener para una pelicula
    int indice_prueba = 0; //prueba para solo obtener para 1 pelicula
    string director_name;
    string duracion;
    string link;
    string nombre;
    string total;
    if( controlador_actual->length <= 9 ){ //si no se ha terminado de recorrer toda la lista
        if(indice_prueba <=1){
            for(int i = 0;i <= 3; i++){ //son 4 datos de la pelicula
                cout<<"Ciclo de obtener datos individuales de la pelicula"<<endl;
                if(i==0){ //si esta en la director name
                    //pelicula_individual->directorName = controlador_actual;
                    pelicula_individual = controlador_actual->GetNth(0)->value;
                    total = pelicula_individual->movie_title;
                    cout<<total<<endl;
                }
                if(i==1){
                    //pelicula_individual= controlador_actual->GetNth(1);
                }
                if(i==2){
                    //pelicula_individual= controlador_actual->GetNth(2);
                }
                if(i==3){
                    //pelicula_individual= controlador_actual->GetNth(3);
                }
                //lista_pelicula_individual->append(pelicula_individual);
            }

            contador = 0;
        }
    }
}
