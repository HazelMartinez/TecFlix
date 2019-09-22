#ifndef MAINWINDOW_ATRAS_H
#define MAINWINDOW_ATRAS_H

#include <QMainWindow>

namespace Ui {
class MainWindow_atras;
}

class MainWindow_atras : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow_atras(QWidget *parent = 0);
    ~MainWindow_atras();

private:
    Ui::MainWindow_atras *ui;
};

#endif // MAINWINDOW_ATRAS_H
