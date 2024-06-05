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
    float _porcentaje_comision;
    float _comision_acumulada;
    bool _estado_personal;

public:
    Personal();
    Personal(int legajo_personal, std::string contrasena, std::string cargo,float sueldo,float porcentajeComision, float comision_acu,bool estado_personal);
    Personal(Persona obj,int legajo_personal, std::string contrasena, std::string cargo, float sueldo,float porcentajeComision, float comision_acu,bool estado_personal);

    int getLegajoPersonal();
    std::string getContrasena();
    std::string getCargo();
    float getSueldo();
    float getPorcentajeComision();
    float getComisionAcumulada();
    bool getEstadoPersonal();


    void setLegajoPersonal(int legajo_personal);
    void setContrasena(std::string contrasena);
    void setCargo(std::string cargo);
    void setSueldo(float sueldo);
    void setPorcentajeComision(float comision);
    void setComisionAcumulada(float comision);
    void setEstadoPersonal(bool estado_personal);

    void crearPersonal();
    void mostrarPersonal();
};
