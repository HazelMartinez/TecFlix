#include "mainwindow.h"
#include <QApplication>
#include "lectura.h"
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<fstream>
using namespace std;

int main(){
    Lectura* lecturacsv= new Lectura();

    lecturacsv->lectura();

    //lecturacsv->lectura("/home/hazel/Escritorio/Datos2_TecFlix/TecFlix/TecFlix_Project/movie_metadata.csv");


    system("pause");
    return 0;
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
