#pragma once
#include "Persona.h"
#include <string>

class Personal:public Persona
{
private:
    int _legajo_personal;
    char _contrasena [30];
    char _cargo [30];
    float _sueldo;
    float _comision;

public:
    Personal();
    Personal(int legajo_personal, std::string contrasena, std::string cargo,float sueldo,float comision);

    int getLegajoPersonal();
    std::string getContrasena();
    std::string getCargo();
    float getSueldo();
    float getComision();


    void setLegajoPersonal(int legajo_personal);
    void setContrasena(std::string contrasena);
    void setCargo(std::string cargo);
    void setSueldo(float sueldo);
    void setComision(float comision);

    void cargarPersonal();
    void mostrarPersonal();



};
