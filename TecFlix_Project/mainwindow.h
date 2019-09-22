#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "manejodememoria.h"
#include "linkedmovie.h"
#include <iostream>
#include <QPushButton>
using namespace std;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);    
    ~MainWindow();
    ManejoDeMemoria *manager=new ManejoDeMemoria();
    int cantidadPeliculas =24; //el tamanio de pagina es fijo, pero se puede cambiar antes de la ejecucion
    void Linkear(string url);
    string Cambiar(string cadena);
private slots:
    //int contInferior=0;
    //int contSuperior=9;
    void prueba(int a);
    void on_downButton_clicked();

    void on_upButton_clicked();

    //void handleButton();

    void createButtons();





private:
    int contInferior=1;
    int contSuperior=cantidadPeliculas+contInferior;
    string video;
    Ui::MainWindow *ui;
    QWidget *ventanaP;
    QPushButton * m_pButton;
    QTabWidget* m_pTableWidget;
};



#endif // MAINWINDOW_H
