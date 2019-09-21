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

#include <QTextEdit>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    /*
    //Create the button
    m_pButton = new QPushButton("My Button", this);
    //set size and location of the button
    m_pButton->setGeometry(QRect( QPoint(100, 100),
    QSize(200, 50) ));
    //Connect button signal to appropriate slot
    connect(m_pButton, SIGNAL (released()),this, SLOT (handleButton()));
    */
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
    manager->mostrar_datos(manager->getActual());
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

/*
void MainWindow::handleButton(){
    //change the text
    m_pButton->setText("Example");
    //resize button
    m_pButton->resize(100,100);
}
*/

void MainWindow::createButtons(){
    int x = 8;
    int y = 10;
    int buttonwidth=50;
    int buttonheight=100;

    for(int i = 0; i<6 ;i++){
        for(int j = 0; j<17;j++){
            QPushButton *a = new QPushButton(ui->centralWidget);
                a->setGeometry(x, y,buttonwidth,buttonheight);
            //a->setGeometry(i*100, j*50, 50, 50);
            //a->setGeometry();
            x=x+55;
            a->show();
        }
        x=8;
        y=y+107;
        //x reset
        //ui->gridMovies->addWidget(a);
    }
}



void MainWindow::setButtons()
{
    /*
    const QSize btnSize = QSize(50, 50);
    for(int i = 0; i < 10; i++) {
        QPushButton *btn = new QPushButton(ui->centralWidget);
        btn->setText(QString::number(i));
        btn->resize(btnSize);
    }

    QGridLayout *btnLayout = new QGridLayout(ui->centralWidget);
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            btnLayout->addWidget(btn,i*100,j*50,80,40);
            btnLayout->setSpacing(0);
        }
    }
    centralWidget->setLayout(btnLayout);
    */
}
