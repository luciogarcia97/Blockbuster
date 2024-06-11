#include "VHS.h"
#include "funciones.h"
#include <cstring>
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

VHS::VHS() {
	strcpy(_tituloP, "");
	strcpy(_generoP, "");
	strcpy(_director, "");
	_duracion = 0;
}
VHS::VHS(std::string titulo, std::string genero, std::string director, int duracion){
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
void VHS::setGeneroP(std::string genero){
	if(genero.size() <= 30){
		strcpy(_generoP, genero.c_str());
	}
	else{
		strcpy(_generoP, "ERROR AL CARGAR");
	}
	setCaracteres(_generoP);
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
std::string VHS::getGeneroP(){
	return _generoP;
}
std::string VHS::getDirector(){
	return _director;
}
int VHS::getDuracion(){
	return _duracion;
}
void VHS::cargar(){
	string titulo, genero, director;
	int duracion;
	Articulo::cargar();
	cin.ignore();
	cout << "Titulo: ";
	getline(cin, titulo); 
	cout << "Genero: ";
	getline(cin, genero);
	cout << "Director: ";
	getline(cin, director); 
	cout << "Duracion: ";
	duracion = validarCinInt();
	cin.ignore();
	setTituloP(titulo);
	setGeneroP(genero);
	setDirector(director);
	setDuracion(duracion);
}
void VHS::mostrar(){
	Articulo::mostrar();
	cout<<"Titulo: "<<_tituloP<<endl;
	cout<<"Genero: "<<_generoP<<endl;
	cout<<"Director: "<<_director<<endl;
	cout<<"Duracion: "<<_duracion<<endl;
}
