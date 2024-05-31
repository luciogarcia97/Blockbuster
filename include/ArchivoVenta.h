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
        int agregarRegistro(Venta obj);
        int agregarRegistro(Venta obj, int posicion);
        int buscarRegistro(int id);
        int getNuevoId();
        void leerTodos(Venta registros[], int cantidad);

        void setNombre(std::string nombre);
    private:
        char _nombre[30];
};

