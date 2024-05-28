#include "Persona.h"
#include <iostream>
#include <cstring>
using namespace std;

Persona::Persona()
{
    strcpy(_nombre, "SIN DATOS");
    strcpy(_apellido, "SIN DATOS");
    strcpy(_mail, "SIN DATOS");
    _cel= 0;
    _dni = 0;

}
Persona::Persona(string nombre,string apellido,string mail,int cel,int dni)
{
   setNombre(nombre);
   setApellido(apellido);
   setMail(mail);
   setCel(cel);
   setDni(dni);

}
void Persona::setNombre(string nombre)
{
    if(nombre.size() <= 30)
    {
        strcpy(_nombre, nombre.c_str());
    }
    else
    {
        strcpy(_nombre, "SIN DATOS");
    }
}

void Persona::setApellido(string apellido)
{
    if(apellido.size() <= 30)
    {
        strcpy(_apellido, apellido.c_str());
    }
    else
    {
        strcpy(_apellido, "SIN DATOS");
    }
}
void Persona::setMail(string mail)
{
    if(mail.size() <= 30)
    {
        strcpy(_mail, mail.c_str());
    }
    else
    {
        strcpy(_mail, "SIN DATOS");
    }
}
void Persona::setCel(int cel)
{
    if (cel > 0){
        _cel = cel;
    }
    else
    {
        _cel = 0;
    }
}

void Persona::setDni(int dni)
{
    if (dni > 0){
        _dni = dni;
    }
    else
    {
        _dni = 0;
    }
}

void Persona::cargarPersona()
{
    string nombre,apellido,mail;
    int cel,dni;

    cin.ignore();
    cout << "Ingrese el Nombre: " << endl;
    getline(cin, nombre);
    cout << "Ingrese el Apellido: " << endl;
    getline(cin, apellido);
    cout << "Ingrese el Email: " << endl;
    getline(cin,mail);
    cout << "Ingrese el numero de celular: " << endl;
    cin >> cel;
    cout << "Ingrese el numero de dni: " << endl;
    cin >> dni;

    setNombre(nombre);
    setApellido(apellido);
    setMail(mail);
    setCel(cel);
    setDni(dni);
}

void Persona::mostrarPersona()
{

    cout << "Nombre: " << getNombre() << endl;
    cout << "Apellido: " << getApellido() << endl;
    cout << "Mail: " << getMail() << endl;
    cout << "Cel: " << getCel() << endl;
    cout << "Dni: " << getDni() << endl;
}

string Persona::getNombre()
{
    return _nombre;
}
string Persona::getApellido()
{
    return _apellido;
}

string Persona::getMail()
{
    return _mail;
}

int Persona::getCel()
{
    return _cel;
}

int Persona::getDni()
{
    return _dni;
}
