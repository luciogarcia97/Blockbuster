#pragma once
#include "Personal.h"

class PersonalArchivo
{
    public:
        bool guardar (Personal registro);
        Personal leer(int index);
        int getCantidadRegistrosPersonal();
    private:


};
