#pragma once
#include "Cliente.h"


class ClienteArchivo
{
    public:
        bool guardar (Cliente registro);
        Cliente leer(int index);
        int getCantidadRegistrosClientes();
    private:


};
