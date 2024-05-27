#include <iostream>
#include "Alquiler.h"
#include "Venta.h"
#include "Fecha.h"
#include "funciones.h"
#include "ArchivoAlquiler.h"
#include "ArchivoVenta.h"
#include "DetalleAlquiler.h"

using namespace std;

int main()
{
    Venta obj, obj2;
    ArchivoVenta data("ventas.dat");

    obj2.cargarVenta();
//    obj2.mostrarVenta();
    system("pause");
//    obj2.setNumeroVenta(1234);
    system("cls");
//    data.agregarRegistroVenta(obj);
    data.agregarRegistroVenta(obj2);

    data.listarArchivo();

    return 0;
}
