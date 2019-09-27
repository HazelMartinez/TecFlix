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

    //manager->getActual()->display();
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
    QLabel* imdb = new QLabel();
    QLabel* imdb_label = new QLabel();
    QLabel* pais = new QLabel();
    QLabel* pais_label = new QLabel();
    QLabel* idioma_label = new QLabel();
    QLabel* idioma = new QLabel();
    QLabel* marca = new QLabel();
    QLabel* marca_label = new QLabel();


    QWidget *wdg = new QWidget;
    QFont serifFont("Times", 30, QFont::Bold);
    QFont sansFont("Decorative", 24);

    string nombre,name_director,duracion_text,imdb_score,country,language;

    wdg->setGeometry(100,100,800,800);
    //wdg->setStyleSheet("background-color:: #738FA7");
    QPalette Pal(palette());
    // Asignar el color de fondo como Negro
    //Pal.setColor(QPalette::Background, Qt::black);
    //QColor color(115,143,167);
    QColor color(12,65,96);
    Pal.setColor (QPalette::Background, color);
    wdg->setAutoFillBackground(true);
    wdg->setPalette(Pal);

    nombre=         (manager->getActual()->GetNth(nodo)->value->movie_title);
    name_director = (manager->getActual()->GetNth(nodo)->value->directorName);
    duracion_text = (manager->getActual()->GetNth(nodo)->value->duration);
    imdb_score =    (manager->getActual()->GetNth(nodo)->value->imdb_score);
    country =       (manager->getActual()->GetNth(nodo)->value->country);
    language =      (manager->getActual()->GetNth(nodo)->value->language);

    l->setText(nombre.c_str());
    l->setFont(serifFont);
    l->setParent(wdg);
    l->setGeometry(0,0,800,100);

    marca->setText("*************************************************");
    marca->setGeometry(0,30,800,100);
    marca->setFont(serifFont);
    marca->setParent(wdg);

    label_diractor->setText("Director: ");
    label_diractor->setFont(sansFont);
    label_diractor->setParent(wdg);
    label_diractor->setGeometry(0,50,800,100);

    director->setText(name_director.c_str());
    director->setFont(sansFont);
    director->setParent(wdg);
    director->setGeometry(150,50,800,100);

    duracion->setText("Duración: ");
    duracion->setFont(sansFont);
    duracion->setParent(wdg);
    duracion->setGeometry(0,100,800,100);

    label_duracion->setText(duracion_text.c_str());
    label_duracion->setFont(sansFont);
    label_duracion->setParent(wdg);
    label_duracion->setGeometry(150,100,800,100);

    imdb->setText("IMDB Score: ");
    imdb->setFont(sansFont);
    imdb->setParent(wdg);
    imdb->setGeometry(0,150,800,100);

    imdb_label->setText(imdb_score.c_str());
    imdb_label->setFont(sansFont);
    imdb_label->setParent(wdg);
    imdb_label->setGeometry(200,150,800,100);

    pais->setText("País: ");
    pais->setFont(sansFont);
    pais->setParent(wdg);
    pais->setGeometry(0,200,800,100);

    pais_label->setText(country.c_str());
    pais_label->setFont(sansFont);
    pais_label->setParent(wdg);
    pais_label->setGeometry(80,200,800,100);

    idioma->setText("Idioma: ");
    idioma->setFont(sansFont);
    idioma->setParent(wdg);
    idioma->setGeometry(0,250,800,100);

    idioma_label->setText(language.c_str());
    idioma_label->setFont(sansFont);
    idioma_label->setParent(wdg);
    idioma_label->setGeometry(120,250,800,100);

    wdg->show();

}

void MainWindow::createButtons(){
    //this->movie_central->setGeometry(10,10,951,681);
    //static QWidget MainWindow::movie_central = new QWidget(ui->centralWidget);
    //movie_central->setGeometry(0,0,951,681);
    //movie_central->show();

    QWidget* central_movie= new QWidget(ui->centralWidget);
    QFrame* movie_frame = new QFrame(central_movie);

    central_movie->setGeometry(0,0,950, 670);
    movie_frame->setGeometry(0,0,950,670);
    central_movie->show();
    movie_frame->show();



    //this->movie_central->setGeometry(0,0,951, 681);
    //this->movie_central->show();

    int x = 8;
    int y = 10;
    int buttonwidth=115;
    int buttonheight=200;
    int tamanioListaPeli = manager->getActual()->length; //manager tiene las listas
    int contador = 0;
    string url1="\n sdf",nombre;


    for(int i = 0; i<3 ;i++){
        for(int j = 0; j<8;j++){
            QPushButton *a = new QPushButton(central_movie);
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





void MainWindow::on_zoom_in_clicked(){



    QWidget* window = new QWidget(ui->centralWidget);
    window->resize(951, 681);
    window->show();
    QWidget* central_movie= new QWidget(ui->centralWidget);
    QFrame* movie_frame = new QFrame(central_movie);
    central_movie->setGeometry(0,0,950, 670);
    movie_frame->setGeometry(0,0,950,670);
    central_movie->show();
    movie_frame->show();




    int plus_width = 2;
    int plus_height = 2;
    int x = 8;
    int y = 10;
    this->buttonwidth = this->buttonwidth+plus_width;
    this->buttonheight = this->buttonheight+plus_height;
    int tamanioListaPeli = manager->getActual()->length; //manager tiene las listas
    int contador = 0;
    string url1="\n sdf",nombre;


    for(int i = 0; i<3 ;i++){
        for(int j = 0; j<8;j++){
            QPushButton *a = new QPushButton(movie_frame);
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



void MainWindow::on_zoom_out_clicked()
{

    QWidget* window = new QWidget(ui->centralWidget);


    window->resize(951, 681);
    window->show();


    QWidget* central_movie= new QWidget(ui->centralWidget);
    QFrame* movie_frame = new QFrame(central_movie);

    central_movie->setGeometry(0,0,951, 681);
    movie_frame->setGeometry(0,0,951,681);
    central_movie->show();
    movie_frame->show();

    int minus_width = 2;
    int minus_height = 2;

    int x = 8;
    int y = 10;
    this->buttonwidth = this->buttonwidth-minus_width;
    this->buttonheight = this->buttonheight-minus_height;
    //int buttonwidth=115 + plus_width;
    //int buttonheight=200 + plus_height;
    int tamanioListaPeli = manager->getActual()->length; //manager tiene las listas
    int contador = 0;
    string url1="\n sdf",nombre;


    for(int i = 0; i<3 ;i++){
        for(int j = 0; j<8;j++){
            QPushButton *a = new QPushButton(movie_frame);
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

void MainWindow::on_page1_clicked()
{
    manager->establecerContadores(ui->page1->text().toInt(),this->cantidadPeliculas);
    createButtons();

}

void MainWindow::on_page2_clicked()
{
    manager->establecerContadores(ui->page2->text().toInt(),this->cantidadPeliculas);
    createButtons();
}

void MainWindow::on_page3_clicked()
{
    manager->establecerContadores(ui->page3->text().toInt(),this->cantidadPeliculas);
    createButtons();
}

void MainWindow::on_page4_clicked()
{
    manager->establecerContadores(ui->page4->text().toInt(),this->cantidadPeliculas);
    createButtons();
}

void MainWindow::on_page5_clicked()
{
    manager->establecerContadores(ui->page5->text().toInt(),this->cantidadPeliculas);
    createButtons();
}

void MainWindow::on_page6_clicked()
{
    manager->establecerContadores(ui->page6->text().toInt(),this->cantidadPeliculas);
    createButtons();
}



void MainWindow::on_paginaatras_clicked()
{
    if (ui->page1->text().toInt()!=1){ // pregunta si es el minimo
        int i1=ui->page1->text().toInt()-6; // resta 6 a cada valor de las posicion
        int i2=ui->page2->text().toInt()-6;
        int i3=ui->page3->text().toInt()-6;
        int i4=ui->page4->text().toInt()-6;
        int i5=ui->page5->text().toInt()-6;
        int i6=ui->page6->text().toInt()-6;
        ui->page1->setText(to_string(i1).c_str());// establece el nuevo texto
        ui->page2->setText(to_string(i2).c_str());
        ui->page3->setText(to_string(i3).c_str());
        ui->page4->setText(to_string(i4).c_str());
        ui->page5->setText(to_string(i5).c_str());
        ui->page6->setText(to_string(i6).c_str());
    }
}

void MainWindow::on_paginaadelante_clicked()
{
    if (ui->page6->text().toInt()<=5044){// pregunta si es el maximo
        int i1=ui->page1->text().toInt()+6;// suma 6 a cada valor de los botones
        int i2=ui->page2->text().toInt()+6;
        int i3=ui->page3->text().toInt()+6;
        int i4=ui->page4->text().toInt()+6;
        int i5=ui->page5->text().toInt()+6;
        int i6=ui->page6->text().toInt()+6;
        ui->page1->setText(to_string(i1).c_str());// establece el nuevo de texto
        ui->page2->setText(to_string(i2).c_str());
        ui->page3->setText(to_string(i3).c_str());
        ui->page4->setText(to_string(i4).c_str());
        ui->page5->setText(to_string(i5).c_str());
        ui->page6->setText(to_string(i6).c_str());
    }
}
