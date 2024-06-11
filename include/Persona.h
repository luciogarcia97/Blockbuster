#pragma once
#include <string>
#include "funciones.h"

class Persona{
protected:
    char _nombre [30];
    char _apellido [30];
    char _mail [30];
    int _cel;
    int _dni;

public:
    Persona();
    Persona(std::string nombre,std::string apellido,std::string mail,int cel,int dni);

    void setNombre(std::string nombre);
    void setApellido(std::string apellido);
    void setMail(std::string mail);
    void setCel(int cel);
    void setDni(int dni);

    std::string getNombre();
    std::string getApellido();
    std::string getMail();
    int getCel();
    int getDni();



};
