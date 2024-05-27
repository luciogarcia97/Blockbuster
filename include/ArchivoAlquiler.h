#pragma once
#include <iostream>
#include<cstring>
#include "Alquiler.h"

class ArchivoAlquiler
{
    public:
        ArchivoAlquiler(const char* nombre);

        Alquiler leerRegistro(int posicion);
        int contarRegistros();
        int agregarRegistroAlquiler();
        int agregarRegistroAqluier(Alquiler obj);

        bool listarArchivo();
    private:
        char _nombre[30];
};

