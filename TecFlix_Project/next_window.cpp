#include "next_window.h"
#include "ui_next_window.h"

next_window::next_window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::next_window)
{
    ui->setupUi(this);
}

next_window::~next_window()
{
    delete ui;
}
