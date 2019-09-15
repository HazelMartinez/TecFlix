#ifndef MANEJODEMEMORIA_H
#define MANEJODEMEMORIA_H
#include "linkedmovie.h"

class ManejoDeMemoria
{
public:
    ManejoDeMemoria();
    LinkedMovie* CargarPagina(int menor, int mayor);
    void CargarAtras();
    void CargarAdelante();
private:
    LinkedMovie* actual;
    LinkedMovie* previa;
    LinkedMovie* next;
};

#endif // MANEJODEMEMORIA_H
