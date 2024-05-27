#include "Personal.h"
#include "Persona.h"
#include <iostream>
#include <cstring>
using namespace std;

Personal::Personal()
{
    _legajo_personal = -1;
    strcpy(_contrasena, "SIN DATOS");
    strcpy(_cargo,"SIN DATOS");
    _sueldo = 0.0f;
    _comision = 0.0f;
}

Personal::Personal(int legajo_personal,string contrasena,string cargo,float sueldo,float comision)
{
    setLegajoPersonal(legajo_personal);
    setContrasena(contrasena);
    setCargo(cargo);
    setSueldo(sueldo);
    setComision(comision);
}

int Personal::getLegajoPersonal()
{
    return _legajo_personal;
}
string Personal::getContrasena()
{
    return _contrasena;
}
string Personal::getCargo()
{
    return _cargo;
}
float Personal::getSueldo()
{
    return _sueldo;
}
float Personal::getComision()
{
    return _comision;
}

void Personal::setLegajoPersonal(int legajo_personal)
{
    if (legajo_personal > 0)
    {
        _legajo_personal = legajo_personal;
    }
    else
    {
        _legajo_personal = -1;
    }
}

void Personal::setContrasena(string contrasena)
{
    if (contrasena.size() <=30)
    {
        strcpy(_contrasena,contrasena.c_str());
    }
    else
    {
        strcpy (_contrasena, "SIN DATOS");
    }
}

void Personal::setCargo(string cargo)
{
    if (cargo.size() <= 30)
    {
        strcpy(_cargo, cargo.c_str());
    }
    else
    {
        strcpy (_cargo, "SIN DATOS");
    }
}

void Personal::setSueldo(float sueldo)
{
    if (sueldo > 0)
    {
        _sueldo = sueldo;
    }
    else
    {
        _sueldo = 0.0f;
    }
}

void Personal::setComision(float comision)
{
    if (comision > 0)
    {
        _comision = comision;
    }
    else
    {
        _comision = 0.0f;
    }
}


void Personal::cargarPersonal()
{
    int legajo_personal;
    string contrasena,cargo;
    float sueldo,comision;

    cin.ignore();
    Persona::cargarPersona();
    cout << "Ingrese el Nro legajo del Personal: " << endl;
    cin >> legajo_personal;
    cout << "Ingrese la contrasena del Personal: " << endl;
    cin >> contrasena;
    cout << "Ingrese el Cargo del Personal :" << endl;
    cin >> cargo;
    cout << "Ingrese el Sueldo del Personal: " << endl;
    cin >> sueldo;
    cout << "Ingrese la comision del Personal: " << endl;
    cin >> comision;

    setLegajoPersonal(legajo_personal);
    setContrasena(contrasena);
    setCargo(cargo);
    setSueldo(sueldo);
    setComision(comision);
}

void Personal::mostrarPersonal()
{
    cout << "El nombre es: " << Persona::getNombre() << endl;
    cout << "El Apellido es: " << Persona::getApellido() << endl;
    cout << "El Mail es: " << Persona::getMail() << endl;
    cout << "El Numero de celular es: " << Persona::getCel() << endl;
    cout << "El numero de dni es: " << Persona::getDni() << endl;
    cout << "El Nro de Legajo es: " << getLegajoPersonal() << endl;
    cout << "La contraseña del Personal es: " << getContrasena() << endl;
    cout << "El cargo del Personal es: " << getCargo() << endl;
    cout << "El sueldo del Personal es: " << getSueldo() << endl;
    cout << "La comision del Personal es: " << getComision() << endl;
}
