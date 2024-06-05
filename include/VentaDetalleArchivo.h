#pragma once
#include <cstring>
#include "VentaDetalle.h"
#include "funciones.h"

class ArchivoDetalleVenta
{
    public:
        ArchivoDetalleVenta(std::string nombre);

        Detalleventa leerRegistro(int posicion);
        int contarRegistros();
        int contarRegistrosRepetidos(int id);
        int agregarRegistroVentaDetalle(Detalleventa obj);
        int getNuevoId();
        int buscarRegistro(int id);

        void setNombre(std::string nombre);
    protected:

    private:
        char _nombre[30];
};

