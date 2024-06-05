#pragma once
#include "Cliente.h"


class ClienteArchivo
{
    public:
        bool guardar (Cliente registro);
        bool guardar (int index, Cliente registro);
        Cliente leer(int index);
        int buscarCliente(int id);
        int getCantidadRegistrosClientes();
        int getNuevoID();
    private:


};
