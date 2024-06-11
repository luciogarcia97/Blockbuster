#include "Juego.h"
#include "funciones.h"
#include <cstring>
#include <string>
#include <iostream>
using namespace std;

Juego::Juego() {
	strcpy(_tituloJ, "");
	strcpy(_generoJ, "");
	_plataforma = 0;
}
Juego::Juego(std::string titulo, std::string genero, int plataforma){
	setTituloJ(titulo);
	setGeneroJ(genero);
	setPlataforma(plataforma);
}
std::string Juego::getTituloJ(){
	return _tituloJ;
}
std::string Juego::getGeneroJ(){
	return _generoJ;
}
int Juego::getPlataforma(){
	return _plataforma;
}
void Juego::setTituloJ(std::string titulo){
	if(titulo.size() <= 30){
		strcpy(_tituloJ, titulo.c_str());
	}
	else{
		strcpy(_tituloJ, "ERROR DE CARGA");
	}
	setCaracteres(_tituloJ);
}
void Juego::setGeneroJ(std::string genero){
	if(genero.size() <= 30){
		strcpy(_generoJ, genero.c_str());
	}
	else{
		strcpy(_generoJ, "ERROR DE CARGA");
	}
	setCaracteres(_generoJ);
}
void Juego::setPlataforma(int plataforma){
	_plataforma=plataforma;
}
void Juego::cargar(){
	Articulo::cargar();
	cout<<"Titulo: ";
	cin>>_tituloJ;
	cout<<endl;
	cout<<"Genero: ";
	cin>>_generoJ;
	cout<<endl;
	cout<<"Plataforma: ";
	_plataforma = validarCinInt();
}
void Juego::mostrar(){
	Articulo::mostrar();
	cout<<"Titulo: "<<_tituloJ<<endl;
	cout<<"Genero: "<<_generoJ<<endl;
	cout<<"Plataforma: "<<_plataforma<<endl;
}
