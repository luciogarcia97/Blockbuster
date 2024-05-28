#pragma once
#include<cstring>
#include "Alquiler.h"

class ArchivoAlquiler
{
    public:
        ArchivoAlquiler(std::string nombre);

        Alquiler leerRegistro(int posicion);
        int contarRegistros();
        int agregarRegistroAlquiler();
        int agregarRegistroAqluier(Alquiler obj);

        bool listarArchivo();

        void setNombre(std::string);
    private:
        char _nombre[30];
};

