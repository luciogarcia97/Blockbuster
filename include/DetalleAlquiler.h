#pragma once
#include <iostream>
#include <cstdlib>
#include "funciones.h"
using namespace std;

class DetalleAlquiler
{
    public:
        DetalleAlquiler(int alquiler = 0, int articulo = 0, int cantidad = 0, float precio = 0);

        int getNumeroAlquilerDetalle();
        int getNumeroArticuloAlquilerDetalle();
        int getCantidad();
        float getPrecio();

        void setNumeroAlquilerDetalle(int alquiler);
        void setNumeroArticuloAlquilerDetalle(int articulo);
        void setCantidad(int cantidad);
        void setPrecio(float precio);

        void cargarAlquilerDetalle();
        void mostrarAlquilerDetalle();

    protected:

    private:
        int _numero_alquiler;
        int _numero_articulo;
        int _cantidad;
        float _precio;
};

