#pragma once
#include <iostream>
#include "Venta.h"
#include "ArchivoVenta.h"

class VentaManager
{
    public:
        void menu();
    private: 
        void agregarVenta();
        void listarVentas();
        ArchivoVenta _dataVentas = ArchivoVenta("ventas.dat");
};

