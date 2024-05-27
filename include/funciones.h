#pragma once

#include <iostream>
using namespace std;

//TODO: Corregir la validacion, me tira error "Multiple definition of 'nombre de la funcion'"
inline int validarCinInt(){
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

inline float validarCinFloat(){
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

inline void headerVentas(){
    //TO DO, esto se puede mejorar con algunos repos de github donde crean una clase que te hace toda esta configuracion. (https://stackoverflow.com/questions/6755250/format-output-in-a-table-c)
    //Tiene formato de tabla
    cout << "Venta" << "\t\tCliente" << "\t\tFecha" << "\t\tVendedor" << "\t\tForma de pago" << endl;
}


