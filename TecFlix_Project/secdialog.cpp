#include "secdialog.h"
secDialog::secDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::secDialog)
{
    ui->setupUi(this);
    ui->tabWidget->setCurrentIndex(0);
}

secDialog::~secDialog()
{
    delete ui;
}

void secDialog::setText(const QString &text)
{
    ui->label->setText(text);
}

void secDialog::setTextL2(const QString &text)
{
    ui->label_2->setText(text);
}

void secDialog::setTextL3(const QString &text)
{
    ui->label_3->setText(text);
}

void secDialog::lineEdit(const QString &text)
{
    ui->lineEdit->setText(text);
}
