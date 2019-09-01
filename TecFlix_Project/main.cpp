#include "mainwindow.h"
#include <QApplication>
#include "lectura.h"
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<fstream>
#include "List.h"
#include "listnode.h"
using namespace std;


int main(int argc, char *argv[]){

    /*
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    */
/*
    Lectura* lecturacsv= new Lectura();

    lecturacsv->lectura();

    //lecturacsv->lectura("/home/hazel/Escritorio/Datos2_TecFlix/TecFlix/TecFlix_Project/movie_metadata.csv");


    return 0;
*/

    //return a.exec();
    cout<< "Inicio bien: " <<endl;
    List<int> lista;
    string hola="wewe";
    //List<string> linkedList; //creates order linked list
    lista.insertNewNode(8);

    cout<< "Termino bien: " <<endl;
    //std::cout << list[1] << std::endl;

    return 0;
    system("pause");
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
