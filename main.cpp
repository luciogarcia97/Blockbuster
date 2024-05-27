#include <iostream>
#include "Alquiler.h"
#include "Venta.h"
#include "Fecha.h"
#include "funciones.h"
#include "ArchivoAlquiler.h"
#include "ArchivoVenta.h"
#include "DetalleAlquiler.h"
#include "Persona.h"

using namespace std;

int main()
{
    Fecha fecha;
    Fecha fecha2(29,5,1997);
    Alquiler obj, obj1, obj2(123, 321, 2, 1010, fecha, fecha2, fecha, 1);
    ArchivoAlquiler data("Alquiler.dat");
//    obj.cargarAlquiler();
    data.agregarRegistroAqluier(obj);
    data.agregarRegistroAqluier(obj1);
    data.agregarRegistroAqluier(obj2);
    data.listarArchivo();


    return 0;
}
