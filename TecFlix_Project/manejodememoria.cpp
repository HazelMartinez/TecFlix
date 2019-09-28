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
///
/// \brief Este metodo es para cargar las peliculas en una lista, se encarca de leer los datos de la pelicula
/// \return Retorna una lista con las peliculas cargadas, simula una pagina
///
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
    for(int i = 0; !archivocsv.eof(); i++){ // este for es para reccorrer todos los datos de la pelicula
        getline(archivocsv, completeLine);// obtiene cada dato
        string delimiter = ",";
        size_t pos= 0;
        string token;
        string data;
        movie *pelicula= new movie();//en cada linea se crea pelicula

        if (i >= this->menor && i <this->mayor ){ // se carga solo el conjunto de peliculas de la pagina correpondiente
            // menor y mayor son los limites de donde hay que cargar los datos
        while ((pos = completeLine.find(delimiter)) != string::npos) {
            //va separando por el limitador
            token = completeLine.substr(0, pos); // obtiene el dato de delimitado por ,
            //cout << token << std::endl;
            completeLine.erase(0, pos + delimiter.length());
            if(indice == 1){ // toma el valor del nombre del director
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
            }

            if(indice == 20){
                pelicula->country = token;
            }

            if(indice == 25){
                pelicula->imdb_score = token;
            }
            indice++;
        }
        lista_peliculas->append(pelicula);// agrega la pelicula a la lista (pagina)

        indice = 0;
    }
      contador=i;

    }

 archivocsv.close();//se cierra el archivo
    return lista_peliculas;

}
///
/// \brief ManejoDeMemoria::CargarAtras
///Esta funcion se encarga de cargar las paginas cuando se presiona el boton de arriba o atras
void ManejoDeMemoria::CargarAtras(){
    this->temp = this->actual; // guarda el dato temporal
    this->actual = this->previa; // la actual ahora es la previa
    this->next = this->temp;// la siguiente es la que era la actual
    this->previa = CargarPagina(); // se carga una pagina para atras
}
///
/// \brief ManejoDeMemoria::CargarAdelante
///Esta funcion se encarga de cargar las paginas hacia adelante cuando se presiona el boton de down
void ManejoDeMemoria::CargarAdelante(){
    this->temp = this->actual;// se guarda el temporal
    this->actual = this->next;//la actual se convierte en la next
    this->previa = this->temp;// la previa en la que era la actual anteriormente
    this->next = CargarPagina();// se carga la pagina que sigue
}///
/// \brief ManejoDeMemoria::setmayor estanblece el menor
/// \param mayor indice mayor
///
void ManejoDeMemoria::setmayor(int mayor){
    this->mayor=mayor;
}
///
/// \brief ManejoDeMemoria::setmenor  establece
/// \param menor indice menor
///
void ManejoDeMemoria::setmenor(int menor){
    this->menor=menor;
}
///
/// \brief ManejoDeMemoria::CargarInicial
/// Este metodo se encarga de realizar la carga de los datos de acuerdo a los limites ya establecidos
/// \param cantidadPeliculas el parametro indica el tamano de la pagina
///
void ManejoDeMemoria::CargarInicial(int cantidadPeliculas){
    int menor1=this->menor,mayor1=this->mayor; // guarda los valores actuales
    this->actual=CargarPagina();// carga la pagina actual con la  cantidad de peliculas
    this->menor=this->mayor;// hace el corrimiento hacia adelante pone en el menor el que antes era mayor
    this->mayor=this->mayor+cantidadPeliculas; //Hace el corrimiento del indice mayor
    this->next=CargarPagina(); // carga la pagina con los valores actuales
    this->mayor=mayor1;// devuelve los valores iniciales para ser consistentes
    this->menor=menor1;
    if (this->menor<=1){ // en caso de que sea solo el inicio
        this->previa=NULL;

    }
    else{
        this->mayor=this->menor; // hace corrimiento hacia atras
        this->menor=this->menor-cantidadPeliculas; // establece las peliculas hacia atras
        this->previa=CargarPagina(); // carga los datos de acuerdo a los limites
    }
    this->mayor=mayor1;// establece los valores iniciales para ser consistentes
    this->menor=menor1;

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
///
/// \brief ManejoDeMemoria::mostrar_datos
/// Muestra los datos en pantalla
/// \param controlador_actual indica la lista de peliculas que quiere mostrar
/// \return Un string con los datos
///
string ManejoDeMemoria::mostrar_datos(LinkedMovie* controlador_actual){
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
                    return total;
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

///
/// \brief ManejoDeMemoria::establecerContadores
/// metodo para llamar en una pagina en especifico
/// \param numeroBoton indica el numero de pagina a la que se movera,
/// \param catidadPelicula es utilizado para cargar las nuevas paginas
///
///
void ManejoDeMemoria::establecerContadores(int numeroBoton, int catidadPelicula)
{
    this->menor=1+(numeroBoton-1)*catidadPelicula; // hace el corrimiento segun el corrimiento del valor del boton
    this->mayor=this->menor+catidadPelicula;// suma la cantidad de peliculas
    CargarInicial(catidadPelicula);// carga las nuevas paginas del boton correspondiente
}
