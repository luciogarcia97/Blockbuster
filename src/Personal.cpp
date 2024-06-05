#include "Personal.h"
#include "Persona.h"
#include "PersonalManager.h"
#include "PersonaManager.h"
#include "PersonalArchivo.h"
#include <iostream>
#include <cstring>
using namespace std;

Personal::Personal()
{
    _legajo_personal = 0;
    strcpy(_contrasena, "SIN DATOS");
    strcpy(_cargo,"SIN DATOS");
    _sueldo = 0.0f;
    _porcentaje_comision = 0.0f;
    _comision_acumulada = 0.0f;
}

Personal::Personal(int legajo_personal, std::string contrasena, std::string cargo,float sueldo,float porcentajeComision, float comision_acu,bool estado_personal)
{
    setLegajoPersonal(legajo_personal);
    setContrasena(contrasena);
    setCargo(cargo);
    setSueldo(sueldo);
    setPorcentajeComision(porcentajeComision);
    setComisionAcumulada(comision_acu);
    setEstadoPersonal(estado_personal);
}
Personal::Personal(Persona obj,int legajo_personal, std::string contrasena, std::string cargo, float sueldo,float porcentajeComision, float comision_acu,bool estado_personal)
{
    setNombre(obj.getNombre());
    setApellido(obj.getApellido());
    setMail(obj.getMail());
    setCel(obj.getCel());
    setDni(obj.getDni());
    setLegajoPersonal(legajo_personal);
    setContrasena(contrasena);
    setCargo(cargo);
    setSueldo(sueldo);
    setPorcentajeComision(porcentajeComision);
    setComisionAcumulada(comision_acu);
    setEstadoPersonal(estado_personal);


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
float Personal::getPorcentajeComision()
{
    return _porcentaje_comision;
}
float Personal::getComisionAcumulada()
{
    return _comision_acumulada;
}
bool Personal::getEstadoPersonal()
{
    return _estado_personal;
}

void Personal::setLegajoPersonal(int legajo_personal)
{
    if (legajo_personal > 0)
    {
        _legajo_personal = legajo_personal;
    }
    else
    {
        _legajo_personal = 0;
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

void Personal::setPorcentajeComision(float comision)
{
    if (comision > 0)
    {
        _porcentaje_comision = comision;
    }
    else
    {
        _porcentaje_comision = 0.0f;
    }
}
void Personal::setComisionAcumulada(float comision)
{
    if (comision > 0)
    {
        _comision_acumulada = comision;
    }
    else
    {
        _comision_acumulada = 0.0f;
    }
}
void Personal::setEstadoPersonal(bool estado_personal)
{
    if (estado_personal == 1 || estado_personal == 0){
        _estado_personal = estado_personal;
    }
}

void Personal::crearPersonal()
{
    PersonaManager obj;
    obj.cargarPersona();
}


void Personal::mostrarPersonal()
{
    cout << "El nombre es: " << Persona::getNombre() << endl;
    cout << "El Apellido es: " << Persona::getApellido() << endl;
    cout << "El Mail es: " << Persona::getMail() << endl;
    cout << "El Numero de celular es: " << Persona::getCel() << endl;
    cout << "El numero de dni es: " << Persona::getDni() << endl;
    cout << "El Nro de Legajo es: " << getLegajoPersonal() << endl;
    cout << "La contrase�a del Personal es: " << getContrasena() << endl;
    cout << "El cargo del Personal es: " << getCargo() << endl;
    cout << "El sueldo del Personal es: " << getSueldo() << endl;
    cout << "El porcentaje de comision del Personal es: " << getPorcentajeComision() << "%" << endl;
    cout << "La comision acumulada del Personal para este periodo es: $" << getComisionAcumulada() << endl;
}
