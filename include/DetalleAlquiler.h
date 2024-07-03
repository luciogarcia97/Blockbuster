#pragma once
#include "funciones.h"

class DetalleAlquiler
{
    public:
        DetalleAlquiler(int alquiler = 0, int articulo = 0, int tipo = 0, int cantidad = 0, float precio = 0);

        int getNumeroAlquilerDetalle();
        int getNumeroArticuloAlquilerDetalle();
        int getCantidad();
        float getPrecio();
        int getTipoArticulo();

        void setNumeroAlquilerDetalle(int alquiler);
        void setNumeroArticuloAlquilerDetalle(int articulo);
        void setCantidad(int cantidad);
        void setPrecio(float precio);
        void setTipoArticulo(int tipo);

    protected:

    private:
        int _numero_alquiler;
        int _numero_articulo;
        int _tipo_articulo;
        int _cantidad;
        float _precio;
};

