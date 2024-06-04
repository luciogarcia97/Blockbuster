#include "DetalleAlquiler.h"

DetalleAlquiler::DetalleAlquiler(int alquiler, int articulo, int cantidad, float precio)
{
    _numero_alquiler = alquiler;
    _numero_articulo = articulo;
    _cantidad = cantidad;
    _precio = precio;
}

int DetalleAlquiler::getNumeroAlquilerDetalle(){return _numero_alquiler;}
int DetalleAlquiler::getNumeroArticuloAlquilerDetalle(){return _numero_articulo;}
int DetalleAlquiler::getCantidad(){return _cantidad;}
float DetalleAlquiler::getPrecio(){return _precio;}

void DetalleAlquiler::setNumeroAlquilerDetalle(int alquiler){_numero_alquiler = alquiler;}
void DetalleAlquiler::setNumeroArticuloAlquilerDetalle(int articulo){_numero_articulo = articulo;}
void DetalleAlquiler::setCantidad(int cantidad){_cantidad = cantidad;}
void DetalleAlquiler::setPrecio(float precio){_precio = precio;}

