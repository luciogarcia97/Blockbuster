#pragma once
#include "Genero.h"

using namespace std;

class GeneroArchivo
{
    public:

        Genero leerRegistro(int posicion);
        int contarRegistros();
        int agregarRegistro(Genero obj);
        int agregarRegistro(Genero obj, int posicion);
        int buscarRegistro(int id);
        int getNuevoId();

    private:

};



