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
    /// seteo los valores iniciales
    manager->setmayor(this->contSuperior); ///&lt; establece el indice inferior
    manager->setmenor(this->contInferior);///&lt;establece el indice mayor
    manager->CargarInicial(cantidadPeliculas);///&lt;hace la carga inicial

    //manager->getActual()->display();
    //std::cout<<"*************************************************************"<<"\n";
    //manager->getNext()->display();
    //Aqui iria  la llamada al metodo de poner los datos en pantalla, el cual recibe una linkemovie que es manager.getActual

    createButtons();///&lt;se llama el metodo de crear botones al correr la aplicacion
    //manager->mostrar_datos(manager->getActual());
}

MainWindow::~MainWindow()
{
    delete ui;
}

///
/// \brief MainWindow::on_downButton_clicked
/// EL objetivo de la funcion es cargar la pagina al dar clic al boton para avanzar.
///
void MainWindow::on_downButton_clicked()
{

    std::cout<<"*****************Prueba en down Button********************"<<"\n";
    //if ((manager->getmayor()+cantidadPeliculas)<5044){ // verifica si no es el final
    manager->setmenor(manager->getmayor()); ///&lt; setea los nuevos valores de los indices el menor ahora es el mayor
    manager->setmayor(manager->getmayor()+cantidadPeliculas); ///&lt; el mayor es lo que tenia el mayor + la cantidad de peliculas a mostrar
    manager->CargarAdelante(); ///&lt; carga las de adelante
    createButtons();
    std::cout<<"Entrando a cargar adelante*****************************"<<"\n";
    //}
}

///
/// \brief MainWindow::on_upButton_clicked
/// El objetivo de la funcion es cargar la pagina al presionar el boton de retroceder
///
void MainWindow::on_upButton_clicked()
{
    //std::cout<<manager->getmenor()<<"\n";
    if ((manager->getmenor())>1){///&lt; verifica si no es es el inicio
        manager->setmayor(manager->getmenor());///&lt;el mayor ahora es el menor
    manager->setmenor(manager->getmenor()-cantidadPeliculas); ///&lt; el menor es el menor - la cantidad de peliculas a mostrar
    manager->CargarAtras();///&lt; carga atras
    createButtons();
    }
}

///
/// \brief MainWindow::prueba
/// \param a
///
void MainWindow::prueba(int a){
    std::cout<<"mal"<<"\n";
}


///
/// \brief MainWindow::Linkear funcion que nos permite observar el trailer de la pelicula
/// \param url sera el url de cada pelicula para observar el trailer
///
void MainWindow::Linkear(string url){
    std::cout<<"bien"<<"\n";
    url= "google-chrome " + url; ///&lt; forma de decir que se abra en un buscador en especifico
    const char * link = url.c_str(); ///&lt; se necesita convertir en un char pointer para convertir en una constante de strings
    system(link);  ///&lt; se invoca del comando del shell
}


///
/// \brief MainWindow::ventana_datos metodo dinamico el cual nos permite visualizar la informacion de la pelicula
/// Datos como: Nombre, Director, Duracion, La puntacion en IMBD, el pais donde se relizo y el idioma.
/// \param nodo
///
void MainWindow::ventana_datos(int nodo){

    QLabel* l = new QLabel(); ///&lt; Labels para la muestra de datos.
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


    QWidget *wdg = new QWidget; ///&lt; ventana donde se mostraran los datos
    QFont serifFont("Times", 30, QFont::Bold);
    QFont sansFont("Decorative", 24);

    string nombre,name_director,duracion_text,imdb_score,country,language; ///&lt;en estos strings se guardaran los datos de la pelicula

    wdg->setGeometry(100,100,800,800);
    QPalette Pal(palette());
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


///
/// \brief MainWindow::createButtons metodo para la creacion dinamica de botones
///
void MainWindow::createButtons(){

    QWidget* central_movie= new QWidget(ui->centralWidget);
    QFrame* movie_frame = new QFrame(central_movie); ///&lt; frame donde se crearan los botones

    central_movie->setGeometry(0,0,950, 670);
    movie_frame->setGeometry(0,0,950,670);
    central_movie->show();
    movie_frame->show();

    int x = 8; ///&lt;espaciado del boton en x
    int y = 10; ///&lt; espaciado del boton en y
    int buttonwidth=115; ///&lt; ancho del boton
    int buttonheight=200; ///&lt;alto del boton
    int tamanioListaPeli = manager->getActual()->length; ///&lt;manager tiene las listas
    int contador = 0; ///&lt; para acceder a la pelicula en una posicion especifica en la lista
    string url1="\n sdf",nombre;


    for(int i = 0; i<3 ;i++){ ///&lt;se crearan 3 filas de botones
        for(int j = 0; j<8;j++){ ///&lt;se crearan 8 botones por fila
            QPushButton *a = new QPushButton(central_movie); ///&lt;se crea el boton
            a->setGeometry(x, y,buttonwidth,buttonheight);
            x=x+buttonwidth + 5;

            if(tamanioListaPeli > contador){ ///&lt;si aun no se han cargado todos los datos de la pagina

                nombre=(manager->getActual()->GetNth(contador)->value->movie_title); ///&lt;se obtiene el nombre de la pelicula
                string movie_link = (manager->getActual()->GetNth(contador)->value->movie_imdb_link).c_str();
                nombre=Cambiar(nombre);
                a->setText(nombre.c_str());
                connect(a, &QPushButton::clicked, [=]() { ///paso por valor =
                    ///QPushButton emite una señal si un evento ocurre. Para manejar el botón conecte la señal apropiada a el slot:
                      Linkear(movie_link); ///&lt; para ver el trailer al presionar el boton
                      ventana_datos(contador); ///&lt; se abre la ventana al presionar el boton
                  });
                 contador++;
            }

            a->show();
        }
        x=8;
        y=y+buttonheight + 7;
    }
}

///
/// \brief MainWindow::Cambiar es un metodo que se realizo por que los nombres de las peliculas no calzaban en los botones
/// \param cadena representa el nombre de la pelicula
/// \return una cadena modificada, en lugar de espacios enter.
///
string MainWindow::Cambiar(string cadena){
    std::string x = " ", y = "\n";

    size_t pos;
    while ((pos = cadena.find(x)) != std::string::npos) { ///&lt;mientras no sea el final de la cadena.
        cadena.replace(pos, 1, y); ///&lt;remplace la cadena por un enter.
    }



    return cadena;
}



///
/// \brief MainWindow::on_zoom_in_clicked metodo que permite realizar el zoom
///

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
    this->buttonwidth = this->buttonwidth+plus_width; ///&lt;se incrementa el tamanio del boton al ser presionado
    this->buttonheight = this->buttonheight+plus_height;
    int tamanioListaPeli = manager->getActual()->length; ///&lt;manager tiene las listas
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
                connect(a, &QPushButton::clicked, [=]() { ///&lt;paso por valor =
                    ///&lt; QPushButton emite una señal si un evento ocurre. Para manejar el botón conecte la señal apropiada a el slot:
                      Linkear(movie_link);
                      ventana_datos(contador);///&lt; se abre la ventana al presionar el boton

                  });

                 contador++;
            }

            a->show();
        }
        x=8;
        y=y+buttonheight + 7;

    }
}

///
/// \brief MainWindow::on_zoom_out_clicked metodo que permite realizar el zoom out
///
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
    int tamanioListaPeli = manager->getActual()->length; ///&lt;manager tiene las listas
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
                connect(a, &QPushButton::clicked, [=]() { ///&lt;paso por valor =
                    ///&lt;QPushButton emite una señal si un evento ocurre. Para manejar el botón conecte la señal apropiada a el slot:
                      Linkear(movie_link);
                      ventana_datos(contador);///&lt; se abre la ventana al presionar el boton
                  });

                 contador++;
            }

            a->show();
        }
        x=8;
        y=y+buttonheight + 7;

    }
}

///
/// \brief MainWindow::on_page1_clicked metodo si se presiona el primer boton carga las peliculas correspondientes
///
void MainWindow::on_page1_clicked()
{
    manager->establecerContadores(ui->page1->text().toInt(),this->cantidadPeliculas);
    createButtons();

}

///
/// \brief MainWindow::on_page2_clicked  metodo si se presiona el segundo boton carga las peliculas correspondientes
///
void MainWindow::on_page2_clicked()
{
    manager->establecerContadores(ui->page2->text().toInt(),this->cantidadPeliculas);
    createButtons();
}

///
/// \brief MainWindow::on_page3_clicked  metodo si se presiona el tercer boton carga las peliculas correspondientes
///
void MainWindow::on_page3_clicked()
{
    manager->establecerContadores(ui->page3->text().toInt(),this->cantidadPeliculas);
    createButtons();
}


///
/// \brief MainWindow::on_page4_clicked  metodo si se presiona el cuarto boton carga las peliculas correspondientes
///
void MainWindow::on_page4_clicked()
{
    manager->establecerContadores(ui->page4->text().toInt(),this->cantidadPeliculas);
    createButtons();
}

///
/// \brief MainWindow::on_page5_clicked  metodo si se presiona el quinto boton carga las peliculas correspondientes
///
void MainWindow::on_page5_clicked()
{
    manager->establecerContadores(ui->page5->text().toInt(),this->cantidadPeliculas);
    createButtons();
}

///
/// \brief MainWindow::on_page6_clicked  metodo si se presiona el sexto boton carga las peliculas correspondientes
///
void MainWindow::on_page6_clicked()
{
    manager->establecerContadores(ui->page6->text().toInt(),this->cantidadPeliculas);
    createButtons();
}


///
/// \brief MainWindow::on_paginaatras_clicked metodo para el boton de retoceder
///
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

///
/// \brief MainWindow::on_paginaadelante_clicked metodo para el boton de avanzar
///
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
///
/// \brief MainWindow::on_pushButton_clicked
///metodo encargado de hacer el calculo de memoria
void MainWindow::on_pushButton_clicked()
{

    int nodemovietamano=sizeof(nodemovie),movieTamano=sizeof(movie),LinkedMovieTamano=sizeof(LinkedMovie),manejoMemoriaTamano=sizeof(manejoMemoriaTamano),
            mainwindowTamano=sizeof(MainWindow);
    int total=3*(LinkedMovieTamano+(manager->getActual()->length)*(nodemovietamano+movieTamano))+manejoMemoriaTamano+mainwindowTamano;
    int total2=5044*(nodemovietamano+movieTamano)+LinkedMovieTamano;

    cout<<"Con paginacion: "<<total<<endl;
    cout<<"Sin paginacion: "<<total2<<endl;

    //long tamano= ;
  //  std::cout<<nodemovietamano<<"\n";
}
