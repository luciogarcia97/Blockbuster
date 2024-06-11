#include "genero.h"


Genero::Genero(){
    _numero=0;
    strcpy(_nombre,"vacio");
}

void Genero::setNombre(std::string no){
    if (no.size()<=40){
        strcpy(_nombre, no.c_str());
        setCaracteres(_nombre);
    }
    else {
        strcpy(_nombre, "error");
    }
}
std::string Genero::getNombre(){
    return _nombre;}

void Genero::setNumero(int numero){
    _numero=numero;
}

int Genero::getNumero(){
    return _numero;
}

Genero::Genero (int gn, std::string no, bool estado){
    setNumero(gn);
    setNombre(no);
    setEstado(estado);
}
bool Genero::getEstado(){
    return _estado;
}
void Genero::setEstado(bool es){
    _estado=es;
}