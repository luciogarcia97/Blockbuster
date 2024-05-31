#include "Fecha.h"

Fecha::Fecha(int d,int m,int a)
{//El constructor asigna los valores recibidos, si le son pasados como parametros
  if(d!=0){
  dia=d;mes=m;anio=a;
  }
  else{ //si no recibe valores asigna por defecto la fecha actual
    time_t tiempo;
    struct tm *tmPtr;
    tiempo = time(NULL);
    tmPtr = localtime(&tiempo);
    anio=tmPtr->tm_year+1900;
    mes=tmPtr->tm_mon+1;
    dia=tmPtr->tm_mday;
  }
}

int Fecha::getDia(){
  return dia;
}

int Fecha::getMes(){
  return mes;
}

int Fecha::getAnio(){
  return anio;
}

void Fecha::setDia(int d){
  if (d < 0 || d > 31)
  {
    std::cout << "Dia incorrecto, ingrese nuevamente: ";
    d = validarCinInt(); 
  }
  setDia(d);
}
void Fecha::setMes(int m){
  if (m < 0 || m > 12)
  {
    std::cout << "Mes incorrecto, ingrese nuevamente: ";
    m = validarCinInt(); 
  }
  setMes(m);
}
void Fecha::setAnio(int a){
  if (a < 0)
  {
    std::cout << "Mes incorrecto, ingrese nuevamente: ";
    a = validarCinInt(); 
  }
  setAnio(a);
}

void Fecha::cargarFecha(){
  int _dia, _mes, _anio;

  std::cout << "Ingrese el dia: ";
  _dia = validarCinInt();
  setDia(_dia);
  std::cout << "Ingrese el mes: ";
  _mes = validarCinInt();
  setMes(_mes);
  std::cout << "Ingrese el anio: ";
  _anio = validarCinInt();
  setAnio(_anio);
}

//Muestra la fecha en formato dd/mm/aaaa
void Fecha::MostrarFecha()
{
  std::cout<<dia<<"/"<<mes<<"/"<<anio;
}

std::string Fecha::fechaTexto(){
  return std::to_string(dia) + "/" + std::to_string(mes) + "/" + std::to_string(anio);
}
