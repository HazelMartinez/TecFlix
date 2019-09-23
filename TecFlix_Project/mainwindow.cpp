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

    manager->getActual()->display();
    std::cout<<"*****************Prueba en down Button********************"<<"\n";
    //if ((manager->getmayor()+cantidadPeliculas)<5044){ // verifica si no es el final
    manager->setmenor(manager->getmayor()); // setea los nuevos valores de los indices el menor ahora es el mayor
    manager->setmayor(manager->getmayor()+cantidadPeliculas); // el mayor es lo que tenia el mayor + la cantidad de peliculas a mostrar
    manager->CargarAdelante(); // carga las de adelante
    //manager->getActual()->display();
    createButtons();
    std::cout<<"Entrando a cargar adelante*****************************"<<"\n";
    //}
}

void MainWindow::on_upButton_clicked()
{
    //std::cout<<manager->getmenor()<<"\n";
    if ((manager->getmenor())>1){// verifica si no es es el inicio
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

void MainWindow::ventana_datos(int nodo){
    QLabel* l = new QLabel();
    QLabel* director = new QLabel();
    QLabel* duracion = new QLabel();
    QLabel* label_diractor = new QLabel();
    QLabel* label_duracion = new QLabel();
    QWidget *wdg = new QWidget;
    QFont serifFont("Times", 30, QFont::Bold);
    QFont sansFont("Decorative", 24);

    string nombre,name_director,duracion_text;

    wdg->setGeometry(100,0,800,500);
    //wdg->setStyleSheet("background-color:: #738FA7");
    QPalette Pal(palette());
    // Asignar el color de fondo como Negro
    //Pal.setColor(QPalette::Background, Qt::black);
    //QColor color(115,143,167);
    QColor color(12,65,96);
    Pal.setColor (QPalette::Background, color);
    wdg->setAutoFillBackground(true);
    wdg->setPalette(Pal);

    nombre=(manager->getActual()->GetNth(nodo)->value->movie_title);
    name_director = (manager->getActual()->GetNth(nodo)->value->directorName);
    duracion_text = (manager->getActual()->GetNth(nodo)->value->duration);

    l->setText(nombre.c_str());
    l->setFont(serifFont);
    l->setParent(wdg);
    l->setGeometry(0,0,800,100);

    director->setText(name_director.c_str());
    director->setFont(sansFont);
    director->setParent(wdg);
    director->setGeometry(150,50,800,100);

    label_diractor->setText("Director: ");
    label_diractor->setFont(sansFont);
    label_diractor->setParent(wdg);
    label_diractor->setGeometry(0,50,800,100);

    label_duracion->setText(duracion_text.c_str());
    label_duracion->setFont(sansFont);
    label_duracion->setParent(wdg);
    label_duracion->setGeometry(150,80,800,100);

    duracion->setText("Duración: ");
    duracion->setFont(sansFont);
    duracion->setParent(wdg);
    duracion->setGeometry(0,80,800,100);


    wdg->show();

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
                    //QPushButton emite una señal si un evento ocurre. Para manejar el botón conecte la señal apropiada a el slot:
                      Linkear(movie_link);
                      ventana_datos(contador);


                    //Linkear(MainWindow);

                  });
                /*

                connect(a, &QPushButton::clicked, [=](){
                    ventana_datos();

                });

*/
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




