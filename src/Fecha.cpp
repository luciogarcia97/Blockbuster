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

//Devuelve true si el anio recibido es bisiesto.
bool Fecha::esbisiesto(int a)
{
  bool bisiesto=false;
  if(a%4==0)
     bisiesto=true;
  if((a%100==0) && (a%400!=0))
           bisiesto=false;
  return bisiesto;
}

//Muestra la fecha en formato dd/mm/aaaa
void Fecha::MostrarFecha()
{
  std::cout<<dia<<"/"<<mes<<"/"<<anio;
}
