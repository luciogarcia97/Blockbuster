#pragma once
#include "DetalleAlquiler.h"
#include "ArchivoDetalleAlquiler.h"
#include "ArticulosManager.h"

class AlquilerDetalleManager
{
    public:
        void menu();
        void cargarDetalleAlquiler(int numeroAlquiler);
    private:
        void agregarAlquilerDetalle(DetalleAlquiler obj);
        void listarAlquilerDetalle();
        void listarAlquilerDetalleById();
        void mostrarAlquilerDetalle(DetalleAlquiler reg);
        DetalleAlquiler* buscarAlquilerDetalle(int id);
        ArchivoDetalleAlquiler _archivoAlquilerDetalle = ArchivoDetalleAlquiler("alquilerDetalle.dat");
};

