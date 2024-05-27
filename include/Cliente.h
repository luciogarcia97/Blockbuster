#pragma once
#include "Persona.h"
#include <string>

class Cliente:public Persona
{
private:
        int _id_cliente;
        bool _estado_cliente;
        bool _estado_alquiler;

public:
        Cliente();
        Cliente(int id_cliente,bool estado_cliente,bool estado_alquiler);

        int getIdCliente();
        bool getEstadoCliente();
        bool getEstadoAlquiler();


        void setIdCliente(int id_cliente);
        void setEstadoCliente(bool estado_cliente);
        void setEstadoAlquiler(bool estado_alquiler);

        void crearCliente();
        void mostrarCliente();
};
