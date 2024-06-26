#pragma once
#include <iostream>

int validarCinInt();
float validarCinFloat();
bool validarCinBool();
bool validarPositivoInt(int value);
bool validarPositivoFloat(float value);
void headerVentas();
void headerAlquiler();
void headerAlquilerDetalle();
void headerVentaDetalle();
const char* stringToConstChar(std::string nombre, int caracteres);
void setCaracteres(char cad[]);
