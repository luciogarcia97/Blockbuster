#pragma once
#include "funciones.h"

class Detalleventa{

private:
  int _numero_venta, _numero_articulo, _tipo_articulo, _cantidad;
  float _precio;

public:
    Detalleventa();
    Detalleventa(int alquiler, int tipo, int articulo, int cantidad, float precio);
    int getnumventa();
    int getnumarticulo();
    int getcantidad();
    float getprecio();
    int getTipoArticulo();

    void setnumventa(int id);
    void setnumarticulo(int articulo);
    void setprecio(float precio);
    void setcantidad(int cantidad);
    void setTipoArticulo(int tipo);
};

