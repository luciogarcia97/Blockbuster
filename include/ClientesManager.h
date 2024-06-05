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
    void mostrarCliente(Cliente reg);
    void volverCargarCliente(Cliente &registro);
    void modificarCliente();
    void eliminarCliente();
    ClienteArchivo _clienteArchivo;


};
