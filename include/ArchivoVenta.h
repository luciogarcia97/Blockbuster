#pragma once
#include<cstring>
#include "Venta.h"

using namespace std;

class ArchivoVenta
{
    public:
        ArchivoVenta(std::string nombre);

        Venta leerRegistro(int posicion);
        int contarRegistros();
        int agregarRegistroVenta();
        int agregarRegistroVenta(Venta obj);

        bool listarArchivo();
        void setNombre(std::string nombre);
    private:
        char _nombre[30];
};

