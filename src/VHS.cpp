#include "VHS.h"
#include "funciones.h"
#include <cstring>
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

VHS::VHS() {
	strcpy(_tituloP, "");
	_generoP = 0;
	strcpy(_director, "");
	_duracion = 0;
}
VHS::VHS(std::string titulo, int genero, std::string director, int duracion){
	setTituloP(titulo);
	setGeneroP(genero);
	setDirector(director);
	setDuracion(duracion);
}
VHS::VHS(Articulo art,int numero, std::string titulo, int genero, std::string director, int duracion){
    setNumero(numero);
    setStock(art.getStock());
    setEstado(art.getEstado());
    setTituloP(titulo);
    setGeneroP(genero);
    setDirector(director);
    setDuracion(duracion);
}
void VHS::setTituloP(std::string titulo){
	if(titulo.size() <= 30){
	    strcpy(_tituloP, titulo.c_str());
	}
	else{
		strcpy(_tituloP, "ERROR AL CARGAR");
	}
	setCaracteres(_tituloP);
}
void VHS::setGeneroP(int genero){
	_generoP = genero;
}
void VHS::setDirector(std::string director){
	if(director.size() <= 30){
		strcpy(_director, director.c_str());
	}
	else{
		strcpy(_director, "ERROR AL CARGAR");
	}
	setCaracteres(_director);
}
void VHS::setDuracion(int duracion){
	_duracion=duracion;
}
std::string VHS::getTituloP(){
	return _tituloP;
}
int VHS::getGeneroP(){
	return _generoP;
}
std::string VHS::getDirector(){
	return _director;
}
int VHS::getDuracion(){
	return _duracion;
}
void VHS::setNumeroArtV(int numero){
	_numeroArt = numero;
}
int VHS::getNumeroArtV(){
	return _numeroArt;
}

/*
void VHS::cargar(){
	string titulo,director;
	int duracion, genero;
	Articulo::cargar();

	cin.ignore();
	cout << "Titulo: ";
	getline(cin, titulo);
	cout << "Genero: ";
	genero = validarCinInt();
	cin.ignore();
	cout << "Director: ";
	getline(cin, director);
	cout << "Duracion: ";
	duracion = validarCinInt();

	setTituloP(titulo);
	setGeneroP(genero);
	setDirector(director);
	setDuracion(duracion);
}
*/
void VHS::mostrar(){
	Articulo::mostrar();
	cout<<"Titulo: "<<  getTituloP() <<endl;
	cout<<"Genero: " << getGeneroP() <<endl;
	cout<<"Director: "<< getDirector() <<endl;
	cout<<"Duracion: "<< getDuracion() <<endl;
}
