#pragma once
#include<cstring>
#include "Alquiler.h"

class ArchivoAlquiler
{
    public:
        ArchivoAlquiler(std::string nombre);

        Alquiler leerRegistro(int posicion);
        int contarRegistros();
        int agregarRegistroAlquiler(Alquiler obj);
        int getNuevoId();
        int buscarRegistro(int id);
        bool guardarRegistro(int posicion, Alquiler reg);

        void setNombre(std::string);
    private:
        char _nombre[30];
};

