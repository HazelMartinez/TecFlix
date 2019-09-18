#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "manejodememoria.h"
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
    int cantidadPeliculas =9;

private slots:
    //int contInferior=0;
    //int contSuperior=9;
    void on_movie1_pressed();

    void on_downButton_clicked();

    void on_upButton_clicked();

private:
    int contInferior=1;
    int contSuperior=10;
    Ui::MainWindow *ui;
    QWidget *ventanaP;
};

#endif // MAINWINDOW_H
