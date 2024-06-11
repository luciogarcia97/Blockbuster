#pragma once
#include <iostream>
#include <cstring>
#include "funciones.h"

class Genero{

private:
    int _numero;
    char _nombre[40];
    bool _estado;

public:
    Genero();
    Genero (int gn, std::string no, bool estado);
    int getNumero();
    std::string getNombre();
    bool getEstado();
    void setEstado(bool es);
    void setNumero(int gn);
    void setNombre(std::string no);
};

