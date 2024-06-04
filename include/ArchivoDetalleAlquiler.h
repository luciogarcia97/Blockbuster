#pragma once
#include <cstring>
#include "DetalleAlquiler.h"
#include "funciones.h"

class ArchivoDetalleAlquiler
{
    public:
        ArchivoDetalleAlquiler(std::string nombre);

        DetalleAlquiler leerRegistro(int posicion);
        int contarRegistros();
        int contarRegistrosRepetidos(int id);
        int agregarRegistroAlquilerDetalle(DetalleAlquiler obj);
        int getNuevoId();
        int buscarRegistro(int id);

        void setNombre(std::string nombre);
    protected:

    private:
        char _nombre[30];
};

