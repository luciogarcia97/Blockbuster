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

void DetalleAlquiler::cargarAlquilerDetalle(){
    int numero_alquiler;
    int numero_articulo;
    int cantidad;
    float precio;

    cout << "Carga de datos para Ventas" << endl;
    cout << "--------------------------" << endl << endl;

    cout << "1) Ingrese el numero del alquiler: ";
    numero_alquiler = validarCinInt();
    setNumeroAlquilerDetalle(numero_alquiler);


    cout << "2) Ingrese el numero de articulo: ";
    numero_articulo = validarCinInt();
    setNumeroArticuloAlquilerDetalle(numero_articulo);


    cout << "3) Ingrese la cantidad de productos: ";
    cantidad = validarCinInt();
    setCantidad(cantidad);

    //TO DO: Carga de precio con Articulo => cantidad * precio_unitario

    system("cls");
    cout << "Se registro el alquilerDetalle correctamente!" << endl;
}
void DetalleAlquiler::mostrarAlquilerDetalle(){
    cout << _numero_alquiler << "\t\t" << _numero_articulo << "\t\t" << _cantidad << "\t\t" << _precio << endl;
}
