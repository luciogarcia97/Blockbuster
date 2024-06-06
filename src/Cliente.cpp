#include "Cliente.h"
#include "Persona.h"
#include "ClienteArchivo.h"
#include "ClientesManager.h"
#include "PersonaManager.h"
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
Cliente::Cliente(Persona obj,int id_cliente,bool estado_cliente,bool estado_alquiler)
{

    setNombre(obj.getNombre());
    setApellido(obj.getApellido());
    setMail(obj.getMail());
    setCel(obj.getCel());
    setDni(obj.getDni());
    setIdCliente(id_cliente);
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

void Cliente::mostrarCliente()
{


    ///cout << "El nombre del Cliente es: " << _datos_persona.getNombre()<< endl;
    ///cout << "El apellido del Cliente es: " << _datos_persona.getApellido()<< endl;
    ///cout << "El Mail del Cliente es: " << _datos_persona.getMail()<< endl;
    //cout << "El Nro de Celular del Cliente es: " << _datos_persona.getCel() << endl;
    ///cout << "El Dni del Cliente es: " << _datos_persona.getDni() << endl;
    cout << "Id cliente: " << getIdCliente()<< endl;
    cout << "Estado del cliente: " << getEstadoCliente() << endl;
    cout << "Estado del alquiler del cliente: " << getEstadoAlquiler() << endl;

}
