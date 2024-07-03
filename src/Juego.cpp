#include "Juego.h"
#include "funciones.h"
#include <cstring>
#include <string>
#include <iostream>
using namespace std;

Juego::Juego() {
	strcpy(_tituloJ, "");
	_generoJ = 0;
	_plataforma = 0;
}
Juego::Juego(std::string titulo, int genero, int plataforma){
	setTituloJ(titulo);
	setGeneroJ(genero);
	setPlataforma(plataforma);
}
std::string Juego::getTituloJ(){
	return _tituloJ;
}
int Juego::getGeneroJ(){
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
void Juego::setGeneroJ(int genero){
	_generoJ = genero;
}
void Juego::setPlataforma(int plataforma){
	_plataforma=plataforma;
}
void Juego::cargar(){
	string titulo;
	int plataforma, genero;
	
	
	cin.ignore();
	cout<<"Titulo: ";
	getline(cin, titulo); 
	
	cout<<"Genero: ";
	genero = validarCinInt();
	
	cout<<"Plataforma: 1-PC 2-PSN 3-XBOX" << endl;
    plataforma = validarCinInt();

	while (plataforma != 1 && plataforma != 2 && plataforma !=3)
    {
    cout << "Dato invalido, ingrese nuevamente :" << endl;
    plataforma = validarCinInt();
	}

	Articulo::cargar();
	
	setTituloJ(titulo);
	setGeneroJ(genero);
	setPlataforma(plataforma);
}
void Juego::mostrar(){
	Articulo::mostrar();

	cout<<"Titulo: "<< getTituloJ()<<endl;
	cout<<"Genero: "<<getGeneroJ()<<endl;

	if (getPlataforma() == 1){
        cout << "Plataforma: PC " << endl;
	}
	else if(getPlataforma()== 2){
        cout << "Plataforma: PSN " << endl;
	}
	else{
        cout << "Plataforma: XBOX " << endl;
	}
}
