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
        int agregarRegistroAlquilerDetalle();
        int agregarRegistroAlquilerDetalle(DetalleAlquiler obj);
        bool listarArchivo();
        void setNombre(std::string nombre);
    protected:

    private:
        char _nombre[30];
};

