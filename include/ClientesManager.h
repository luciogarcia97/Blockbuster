#pragma once
#include <iostream>
#include "ClienteArchivo.h"
#include "Cliente.h"
#include "Persona.h"
#include "PersonaManager.h"
#include "funciones.h"
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
