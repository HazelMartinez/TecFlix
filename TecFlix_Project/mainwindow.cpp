#include <iostream>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "manejodememoria.h"
#include "QFrame"
#include "QLabel"
#include "QPushButton"
#include <QCoreApplication>
#include <QTableWidget>
#include <QWidget>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QGroupBox>
#include "mainwindow_atras.h"
#include <QtGui>

#include <QTextEdit>

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

    createButtons();
    //manager->mostrar_datos(manager->getActual());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_downButton_clicked()
{
    if ((manager->getmayor()+cantidadPeliculas)<5044){ // verifica si no es el final
    manager->setmenor(manager->getmayor()); // setea los nuevos valores de los indices el menor ahora es el mayor
    manager->setmayor(manager->getmayor()+cantidadPeliculas); // el mayor es lo que tenia el mayor + la cantidad de peliculas a mostrar
    manager->CargarAdelante(); // carga las de adelante
    createButtons();
    std::cout<<"Entrando a cargar adelante*****************************"<<"\n";
    }
}

void MainWindow::on_upButton_clicked()
{
    if ((manager->getmenor()-cantidadPeliculas-1)>0){// verifica si no es es el inicio
        manager->setmayor(manager->getmenor());// el mayor ahora es el menor
    manager->setmenor(manager->getmenor()-cantidadPeliculas); // el menor es el menor - la cantidad de peliculas a mostrar
    manager->CargarAtras();// carga atras
    createButtons();
    }
}

/*
void MainWindow::handleButton(){
    //change the text
    m_pButton->setText("Example");
    //resize button
    m_pButton->resize(100,100);
}
*/
void MainWindow::prueba(int a){
    std::cout<<"mal"<<"\n";
}
void MainWindow::Linkear(string url){
    std::cout<<"bien"<<"\n";
    url= "google-chrome " + url;
    const char * link = url.c_str();
    system(link);
}
void MainWindow::createButtons(){
    int x = 8;
    int y = 10;
    int buttonwidth=115;
    int buttonheight=200;
    int tamanioListaPeli = manager->getActual()->length; //manager tiene las listas
    int contador = 0;
    string url1="\n sdf",nombre;


    for(int i = 0; i<3 ;i++){
        for(int j = 0; j<8;j++){
            QPushButton *a = new QPushButton(ui->centralWidget);
            a->setGeometry(x, y,buttonwidth,buttonheight);
            x=x+buttonwidth + 5;

            if(tamanioListaPeli > contador){
                nombre=(manager->getActual()->GetNth(contador)->value->movie_title);
                string movie_link = (manager->getActual()->GetNth(contador)->value->movie_imdb_link).c_str();
                nombre=Cambiar(nombre);
                a->setText(nombre.c_str());
                connect(a, &QPushButton::clicked, [=]() { //paso por valor =
                      Linkear(movie_link);
                    //Linkear(MainWindow);

                  });
                 contador++;
            }

            a->show();
        }
        x=8;
        y=y+buttonheight + 7;
        //x reset
        //ui->gridMovies->addWidget(a);
    }
}
string MainWindow::Cambiar(string cadena){
    std::string x = " ", y = "\n";

    size_t pos;
    while ((pos = cadena.find(x)) != std::string::npos) {
        cadena.replace(pos, 1, y);
    }



    return cadena;
}




