#pragma once
#include "Personal.h"

class PersonalArchivo
{
    public:
        bool guardar (Personal registro);
        bool guardar (int index, Personal registro);
        Personal leer(int index);
        int buscarPersonal(int legajo);
        int getCantidadRegistrosPersonal();
        int getNuevoLegajo();
    private:


};
