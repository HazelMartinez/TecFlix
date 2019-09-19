#include <iostream>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "manejodememoria.h"
using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    // seteo los valores iniciales
    manager->setmayor(this->contSuperior); //establece el indice inferior
    manager->setmenor(this->contInferior);// establece el indice mayor
    manager->CargarInicial(cantidadPeliculas);// hace la carga inicial
    //manager->getActual()->display();
    //std::cout<<"*************************************************************"<<"\n";
    //manager->getNext()->display();
    //Aqui iria  la llamada al metodo de poner los datos en pantalla, el cual recibe una linkemovie que es manager.getActual
    manager->mostrar_datos(manager->getActual());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_movie1_pressed()
{
    cout<<"Press button 1"<<endl;
}

void MainWindow::on_downButton_clicked()
{
    if ((manager->getmayor()+cantidadPeliculas)<5044){ // verifica si no es el final
    manager->setmenor(manager->getmayor()); // setea los nuevos valores de los indices el menor ahora es el mayor
    manager->setmayor(manager->getmayor()+cantidadPeliculas); // el mayor es lo que tenia el mayor + la cantidad de peliculas a mostrar
    manager->CargarAdelante(); // carga las de adelante
    //llamar a manager.dislay ahora probar
    std::cout<<"Entrando a cargar adelante*****************************"<<"\n";
    }
}

void MainWindow::on_upButton_clicked()
{
    if ((manager->getmenor()-cantidadPeliculas)>0){// verifica si no es es el inicio
        manager->setmayor(manager->getmenor());// el mayor ahora es el menor
    manager->setmenor(manager->getmenor()-cantidadPeliculas); // el menor es el menor - la cantidad de peliculas a mostrar
    manager->CargarAtras();// carga atras
    std::cout<<"Entrando a cargar atras*****************************"<<"\n";
    }
}


