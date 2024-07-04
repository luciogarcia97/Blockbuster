#pragma once
#include <iostream>
#include "Alquiler.h"
#include "Cliente.h"
#include "ArchivoAlquiler.h"
#include "AlquilerDetalleManager.h"

class AlquilerManager
{
    public:
        void menu();
        bool validarExistencia(int numero);
    private:
        void agregarAlquiler();
        void listarAlquiler();
        Alquiler crearAlquiler();
        void mostrarAlquiler(Alquiler reg);
        Alquiler buscarAlquiler();
        void devolucionAlquiler();
        bool validarIgualdadFechas(Fecha fecha1, Fecha fecha2);
        ArchivoAlquiler _archivoAlquiler = ArchivoAlquiler("alquiler.dat");
};

