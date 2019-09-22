#include "pagina_atras.h"
#include "ui_pagina_atras.h"
#include "mainwindow.h"

pagina_atras::pagina_atras(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::pagina_atras)
{
    ui->setupUi(this);
}

pagina_atras::~pagina_atras()
{
    delete ui;
}
