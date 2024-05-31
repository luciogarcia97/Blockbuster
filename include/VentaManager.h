#pragma once
#include <iostream>
#include "Venta.h"
#include "ArchivoVenta.h"
#include "funciones.h"

class VentaManager
{
public:
   void menu();
private:
   void agregarVenta();
   void listarVenta();
   Venta crearVenta();
   void volverCargarVenta(Venta &reg);
   void mostrarVenta(Venta reg);
   void modificarVenta();
   void buscarVenta();
   ArchivoVenta _archivoVenta = ArchivoVenta("ventas.dat");
};



