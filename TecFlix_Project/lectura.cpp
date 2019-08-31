#include "lectura.h"
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
using namespace std;

Lectura::Lectura()
{

}
void Lectura::lectura(){
    ifstream archivocsv;
    string texto; //para dar lectura al archivo, aca se guardaran las palabras

    archivocsv.open("/home/hazel/Escritorio/Datos2_TecFlix/TecFlix/TecFlix_Project/movie_metadata.csv", ios::in); //abrimos el archivo en modo lectura

    if(archivocsv.fail()){
        cout<<"No se pudo abrir el archivo";
        exit(1);
    }
    while(!archivocsv.eof()){
        getline(archivocsv, texto);//copiamos el contenido del acrhivo en texto
        cout<<texto<<endl;//mostramos el texto
    }
    archivocsv.close();//se cierra el archivo
}

/*
void lectura(){
    ifstream archivocsv;
    string texto; //para dar lectura al archivo, aca se guardaran las palabras

    archivocsv.open("movie_metadata.csv", ios::in); //abrimos el archivo en modo lectura

    if(archivocsv.fail()){
        cout<<"No se pudo abrir el archivo";
        exit(1);
    }
    while(!archivocsv.eof()){
        getline(archivocsv, texto);//copiamos el contenido del acrhivo en texto
        cout<<texto<<endl;//mostramos el texto
    }
    archivocsv.close();//se cierra el archivo
}
*/
