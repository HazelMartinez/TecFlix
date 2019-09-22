#include "mainwindow_atras.h"
#include "ui_mainwindow_atras.h"

MainWindow_atras::MainWindow_atras(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow_atras)
{
    ui->setupUi(this);
}

MainWindow_atras::~MainWindow_atras()
{
    delete ui;
}
