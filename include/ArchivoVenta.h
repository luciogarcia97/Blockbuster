#pragma once
#include <iostream>
#include<cstring>
#include "Venta.h"

using namespace std;

class ArchivoVenta
{
    public:
        ArchivoVenta(const char* nombre);

        Venta leerRegistro(int posicion);
        int contarRegistros();
        int agregarRegistroVenta();
        int agregarRegistroVenta(Venta obj);

        bool listarArchivo();

    protected:

    private:
        char _nombre[30];
};

