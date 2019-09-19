#ifndef MANEJODEMEMORIA_H
#define MANEJODEMEMORIA_H
#include "linkedmovie.h"

class ManejoDeMemoria
{
public:
    ManejoDeMemoria();
    LinkedMovie* CargarPagina();
    LinkedMovie* mostrar_datos(LinkedMovie* controlador_actual);
    void CargarAtras();
    void CargarAdelante();
    void setmayor(int mayor);
    void setmenor (int menor);
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
