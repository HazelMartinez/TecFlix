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
    static QWidget* movie_central;

private slots:

    /**
     * @brief prueba
     * @param a
     */
    void prueba(int a);

    /**
     * @brief on_downButton_clicked
     */
    void on_downButton_clicked();

    /**
     * @brief on_upButton_clicked
     */
    void on_upButton_clicked();

    /**
     * @brief createButtons
     */
    void createButtons();

    /**
     * @brief ventana_datos
     * @param contador
     */
    void ventana_datos(int contador);

    /**
     * @brief on_zoom_in_clicked
     */
    void on_zoom_in_clicked();

    /**
     * @brief on_zoom_out_clicked
     */
    void on_zoom_out_clicked();

    /**
     * @brief on_page1_clicked
     */
    void on_page1_clicked();

    /**
     * @brief on_page2_clicked
     */
    void on_page2_clicked();

    /**
     * @brief on_page3_clicked
     */
    void on_page3_clicked();

    /**
     * @brief on_page4_clicked
     */
    void on_page4_clicked();

    /**
     * @brief on_page5_clicked
     */
    void on_page5_clicked();

    /**
     * @brief on_page6_clicked
     */
    void on_page6_clicked();

    /**
     * @brief on_paginaatras_clicked
     */
    void on_paginaatras_clicked();

    /**
     * @brief on_paginaadelante_clicked
     */
    void on_paginaadelante_clicked();

    /**
     * @brief on_pushButton_clicked
     */
    void on_pushButton_clicked();

private:
    int contInferior=1;
    int contSuperior=cantidadPeliculas+contInferior;
    int buttonwidth=115;
    int buttonheight=200;
    string video;
    Ui::MainWindow *ui;
    QWidget *ventanaP;
    QPushButton * m_pButton;
    QTabWidget* m_pTableWidget;

};



#endif // MAINWINDOW_H
