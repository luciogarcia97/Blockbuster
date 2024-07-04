#include "VentaDetalle.h"
Detalleventa::Detalleventa(){
    _numero_venta = 0;
    _numero_articulo = 0;
    _cantidad = 0;
    _precio = 0.0f;
}

Detalleventa::Detalleventa(int nv, int na, int t, int c, float p){
    setnumventa(nv);
    setnumarticulo(na);
    setcantidad(c);
    setprecio(p);
    setTipoArticulo(t);
}

int Detalleventa::getnumventa(){
    return _numero_venta;
}

int Detalleventa::getnumarticulo(){
    return _numero_articulo;
}

int Detalleventa::getcantidad(){
    return _cantidad;
}

int Detalleventa::getTipoArticulo(){
    return _tipo_articulo;
}

float Detalleventa::getprecio(){
    return _precio;
}

void Detalleventa::setnumventa(int nv){
    if (validarPositivoInt(nv)) _numero_venta = nv;
    else _numero_venta = 0;
}

void Detalleventa::setnumarticulo(int na){
    if (validarPositivoInt(na)) _numero_articulo = na;
    else _numero_articulo = 0;
}

void Detalleventa::setprecio(float p){
    if (validarPositivoFloat(p)) _precio = p;
    else _precio = 0.0f;
}

void Detalleventa::setcantidad(int c){
    if (validarPositivoInt(c)) _cantidad = c;
    else _cantidad = 0;
}

void Detalleventa::setTipoArticulo(int t){
    _tipo_articulo = t;
}


// void Detalleventa::cargardetalleventa(){
//     int numventa;
//     int numarticulo;
//     int cantidad;
//     float precio;

//     cout<< "Carga de datos para Detalle de Ventas"<<endl;
//     cout<<"----------------------"<<endl<<endl;

//     cout<<"Por favor ingresar numero de venta: "<<endl;
//     cin>> numventa;
//     setnumventa(numventa);
//     cout<<endl;
//     cout<<"Por favor ingresar numero de articulo:: "<<endl;
//     cin>> numarticulo;
//     setnumarticulo(numarticulo);
//     cout<<endl;
//     cout<<"Por favor ingrese la cantidad: "<<endl;
//     cin>> cantidad;
//     setcantidad(cantidad);
//     cout<<endl;
//     cantidad*precio= precio
//     }

//     void Detalleventa::mostrardetalleventa(){}

