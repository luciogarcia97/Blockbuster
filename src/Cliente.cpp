#include "Cliente.h"
#include "Persona.h"
#include <iostream>
#include <cstring>
using namespace std;

Cliente::Cliente()
{
    _id_cliente = -1;
    _estado_cliente = 0;
    _estado_alquiler = 0;
}

Cliente::Cliente(int numero_cliente,bool estado_cliente,bool estado_alquiler)
{
    setIdCliente(numero_cliente);
    setEstadoCliente(estado_cliente);
    setEstadoAlquiler(estado_alquiler);

}

int Cliente::getIdCliente()
{
    return _id_cliente;
}

bool Cliente::getEstadoCliente()
{
    return _estado_cliente;
}

bool Cliente::getEstadoAlquiler()
{
    return _estado_alquiler;
}


void Cliente::setIdCliente(int id_cliente)
{
    if(id_cliente > 0)
    {
        _id_cliente = id_cliente;
    }
    else
    {
        _id_cliente = -1;
    }
}

void Cliente::setEstadoCliente(bool estado_cliente)
{
    _estado_cliente = estado_cliente;
}

void Cliente::setEstadoAlquiler(bool estado_alquiler)
{
    _estado_alquiler = estado_alquiler;
}

void Cliente::crearCliente()
{
    int id_cliente;
    bool estado_cliente = 0;
    bool estado_alquiler = 0;

    cin.ignore();
    Persona::cargarPersona();
    cout << "Ingrese el numero de cliente: " << endl;
    cin >> id_cliente;
    cout << "Ingrese el estado del cliente 1-activo 2-inactivo" << endl;
    cin >> estado_cliente;
    cout << "Ingrese el estado del alquiler del cliente 1-falta devolver 0-ya devolvio el producto: " << endl;
    cin >> estado_alquiler;

    setIdCliente(id_cliente);
    setEstadoCliente(estado_cliente);
    setEstadoAlquiler(estado_alquiler);
}

void Cliente::mostrarCliente()
{

    cout << "El nombre del Cliente es: " << Persona::getNombre() << endl;
    cout << "El apellido del Cliente es: " << Persona::getApellido()<< endl;
    cout << "El Mail del Cliente es: " << Persona::getMail()<< endl;
    cout << "El Nro de Celular del Cliente es: " << Persona::getCel() << endl;
    cout << "El Dni del Cliente es: " << Persona::getDni() << endl;
    cout << "Id cliente: " << getIdCliente() << endl;
    cout << "Estado del cliente: " << getEstadoCliente() << endl;
    cout << "Estado del alquiler del cliente: " << getEstadoAlquiler() << endl;

}
