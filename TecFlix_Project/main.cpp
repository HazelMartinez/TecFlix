#include "mainwindow.h"
#include <QApplication>
#include "lectura.h"
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<fstream>
//#include "Linked_List.h"
#include "lista.h"
using namespace std;


int main(int argc, char *argv[]){

    /*
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    */

    Lectura* lecturacsv= new Lectura();

    lecturacsv->lectura();

    //lecturacsv->lectura("/home/hazel/Escritorio/Datos2_TecFlix/TecFlix/TecFlix_Project/movie_metadata.csv");


    return 0;

    //string texto = "HOLA SOY Hazel";
    //cout<< texto.length()<<endl;
    /*

   Linked_List<string> *generic_int_linked_list = new Linked_List<string>();
   generic_int_linked_list->append("Hazel es la mujer mas linda del mundo ");
   generic_int_linked_list->append("Jason es el mas afortunado en tenerla como amigo");
   generic_int_linked_list->display();
    cout<< "Termino bien: " <<endl;
    //std::cout << list[1] << std::endl;

    return 0;
    system("pause");
    */
}



/*
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    Lectura* lectura = new Lectura;
    lectura->lectura();
    return a.exec();
}
*/
