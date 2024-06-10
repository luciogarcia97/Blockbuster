#pragma once
#include <iostream>
#include <string>
#include "GeneroArchivo.h"
#include "Genero.h"
#include "funciones.h"

class GeneroManager{

    public:

        void menu();
        void buscarGeneroPorNumero();

    private:
        Genero crearGenero();
        void agregarGenero();
        void listarGenero();
        void mostrarGenero(Genero reg);
        void modificarGenero();
        void eliminarGenero();
        void volverCargarGenero(Genero &registro);
        GeneroArchivo _generoArchivo;
};


