#include "mainwindow.h"
#include <QApplication>
#include "lectura.h"
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<fstream>
//#include "Linked_List.h"
#include "lista.h"
#include "manejodememoria.h"
using namespace std;


int main(int argc, char *argv[]){
/*
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
  */
    ManejoDeMemoria* manejo =  new ManejoDeMemoria();
    manejo->CargarPagina(2,4);


    //Lectura* lecturacsv= new Lectura();

    //lecturacsv->lectura();


    //lecturacsv->lectura("/home/hazel/Escritorio/Datos2_TecFlix/TecFlix/TecFlix_Project/movie_metadata.csv");
/*
    static char *s[] = {"black", "white", "pink", "violet"};
    char **ptr[] = {s+3, s+2, s+1, s}, ***p;
    p = ptr;
    cout<<"p: "<< &p<<
    ++p;
    printf("%s", **p+1);

    return 0;
*/
    //string texto = "HOLA SOY Hazel";
    //cout<< texto.length()<<endl;
    /*

   Linked_List<string> *generic_int_linked_list = new Linked_List<string>();
   generic_int_linked_list->append("Hazel ");
   generic_int_linked_list->append(" Martinez");
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
