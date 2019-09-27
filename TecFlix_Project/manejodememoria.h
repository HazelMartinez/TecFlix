#ifndef MANEJODEMEMORIA_H
#define MANEJODEMEMORIA_H
#include "linkedmovie.h"
using namespace std;
class ManejoDeMemoria
{
public:
    ManejoDeMemoria();
    LinkedMovie* CargarPagina();
    string mostrar_datos(LinkedMovie* controlador_actual);
    void CargarAtras();
    void CargarAdelante();
    void setmayor(int mayor);
    void setmenor (int menor);
    void establecerContadores(int numeroBoton, int catidadPelicula);
    int getmayor();
    int getmenor();
    void CargarInicial(int cantidadPeliculas);
    LinkedMovie* getActual();
    LinkedMovie* getPrevia();
    LinkedMovie* getNext();

private:
    LinkedMovie* actual;
    LinkedMovie* previa;
    LinkedMovie* next;
    LinkedMovie* temp;
    int menor;
    int mayor;
};

#endif // MANEJODEMEMORIA_H
