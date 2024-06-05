#include "funciones.h"

//TODO: Corregir la validacion, me tira error "Multiple definition of 'nombre de la funcion'"
int validarCinInt(){
   int error;
   int value;
   do
   {
       error = 0;
       std::cin >> value;
       if (std::cin.fail())
       {
           std::cout << "Dato invalido, reingrese nuevamente" << std::endl;
           error = 1;
           std::cin.clear();
           std::cin.ignore(80, '\n');
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
        std::cin >> value;
        if (std::cin.fail())
        {
            std::cout << "Dato invalido, reingrese nuevamente" << std::endl;
            error = 1;
            std::cin.clear();
            std::cin.ignore(80, '\n');
        }
    }while(error == 1);
    return value;
}

void headerVentas(){
    //TO DO, esto se puede mejorar con algunos repos de github donde crean una clase que te hace toda esta configuracion. (https://stackoverflow.com/questions/6755250/format-output-in-a-table-c)
    //Tiene formato de tabla
    std::cout << "Venta" << "\t\tCliente" << "\t\tFecha" << "\t\tVendedor" << "\tForma de pago" << std::endl;
}

void headerAlquiler(){
    std::cout << "Alquiler" << "\tCliente" << "\t\tFecha Alquiler" << "\tVendedor" << "\tForma de pago" << "\tFecha de Devolucion" << "\t\tFecha de Entrega" << "\t\tEstado" << std::endl;
}

void headerAlquilerDetalle(){
    std::cout << "Alquiler" << "\tArticulo" << "\tCantidad" << "\tValor total" << std::endl;
}

const char* stringToConstChar(std::string nombre, int caracteres){
    if (nombre.size() <= caracteres)
    {
        return nombre.c_str();
    }
    return "ErrorEnNombrar";
}