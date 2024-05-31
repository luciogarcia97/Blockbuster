#pragma once
#include <iostream>
#include <ctime>
#include <string>
#include "funciones.h"

class Fecha
{
  private:
    int dia;
    int mes;
    int anio;
  public:
    Fecha(int d=0,int m=0,int a=0);
    int getDia();
    int getMes();
    int getAnio();
    void setDia(int d);
    void setMes(int m);
    void setAnio(int a);
    void cargarFecha();
    void MostrarFecha();
    std::string fechaTexto();
};

