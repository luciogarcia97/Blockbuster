#pragma once
#include "ClienteArchivo.h"
#include "Cliente.h"
#include "Persona.h"
class ClienteManager{

public:
        void menu();
    private:

    Cliente crearCliente();
    void agregarCliente();
    void listarClientes();
    ClienteArchivo _clienteArchivo;


};
