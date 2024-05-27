#include "VHS.h"
#include <cstring>
#include <string>
#include <iostream>
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
}
void VHS::setGeneroP(std::string genero){
	strcpy(_generoP, genero.c_str());
}
void VHS::setDirector(std::string director){
	strcpy(_director, director.c_str());
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
	Articulo::cargar();
	cout<<"Titulo: ";
    cin>>_tituloP;
	cout<<endl;
	cout<<"Genero: ";
	cin>>_generoP;
	cout<<endl;
	cout<<"Director: ";
	cin>>_director;
	cout<<endl;
	cout<<"Duracion: ";
	cin>>_duracion;
}
void VHS::mostrar(){
	Articulo::mostrar();
	cout<<"Titulo: "<<_tituloP<<endl;
	cout<<"Genero: "<<_generoP<<endl;
	cout<<"Director: "<<_director<<endl;
	cout<<"Duracion: "<<_duracion<<endl;
}
