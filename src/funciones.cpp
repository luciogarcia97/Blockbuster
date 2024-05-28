#include "funciones.h"

//TODO: Corregir la validacion, me tira error "Multiple definition of 'nombre de la funcion'"
int validarCinInt(){
   int error;
   int value;
   do
   {
       error = 0;
       cin >> value;
       if (cin.fail())
       {
           cout << "Dato invalido, reingrese nuevamente" << endl;
           error = 1;
           cin.clear();
           cin.ignore(80, '\n');
       }
   }while(error == 1);
   return value;
}

float validarCinFloat(){
    int error;
    float value;
    do
    {
        error = 0;
        cin >> value;
        if (cin.fail())
        {
            cout << "Dato invalido, reingrese nuevamente" << endl;
            error = 1;
            cin.clear();
            cin.ignore(80, '\n');
        }
    }while(error == 1);
    return value;
}

void headerVentas(){
    //TO DO, esto se puede mejorar con algunos repos de github donde crean una clase que te hace toda esta configuracion. (https://stackoverflow.com/questions/6755250/format-output-in-a-table-c)
    //Tiene formato de tabla
    cout << "Venta" << "\t\tCliente" << "\t\tFecha" << "\t\tVendedor" << "\t\tForma de pago" << endl;
}

void headerAlquiler(){
    cout << "Alquiler" << "\tCliente" << "\t\tFecha Alquiler" << "\tVendedor" << "\tForma de pago" << "\tFecha de Devolucion" << "\t\tFecha de Entrega" << "\t\tEstado" << endl;
}

void headerAlquilerDetalle(){
    cout << "Alquiler" << "\tArticulo" << "\tCantidad" << "\tTotal" << endl;
}

const char* stringToConstChar(std::string nombre, int caracteres){
    if (nombre.size() <= caracteres)
    {
        return nombre.c_str();
    }
    return "ErrorEnNombrar";
}
