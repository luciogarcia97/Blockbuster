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
        void listarGenero();
        bool validarExistenciaId(int numero);
    private:
        Genero crearGenero();
        void agregarGenero();
        void mostrarGenero(Genero reg);
        void modificarGenero();
        void eliminarGenero();
        void volverCargarGenero(Genero &registro);
        GeneroArchivo _generoArchivo;
};


