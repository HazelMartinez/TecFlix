#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "manejodememoria.h"
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
    //manager->getNext()->display();
    //Aqui iria el la llamada al metodo de poner los datos en pantalla, el cual recibe una linkemovie que es manager.getActual

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_movie1_pressed()
{

}

void MainWindow::on_downButton_clicked()
{
    if ((manager->getmayor()+cantidadPeliculas)<54044){ // verifica si no es el final
    manager->setmenor(manager->getmayor()); // setea los nuevos valores de los indices el menor ahora es el mayor
    manager->setmayor(manager->getmayor()+cantidadPeliculas); // el mayor es lo que tenia el mayor + la cantidad de peliculas a mostrar
    manager->CargarAdelante(); // carga las de adelante
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
