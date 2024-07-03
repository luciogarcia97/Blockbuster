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
Juego::Juego(Articulo articulo, std::string titulo, int genero, int plataforma){
	setNumero(articulo.getNumero());
    setStock(articulo.getStock());
    setEstado(articulo.getEstado());
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
	
	cout<<"Genero: 1-Aventura 2-Accion 3-RPG 4-Deportes";
	genero = validarCinInt();

	while (genero != 1 && genero != 2 && genero != 3 && genero != 4)
    {
		cout << "Dato invalido, ingrese nuevamente :" << endl;
		genero = validarCinInt();
	}
	
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
	
	cout<<"Titulo: "<< getTituloJ()<<endl;
	
	if (getGeneroJ() == 1){
        cout << "Genero: Aventura" << endl;
	}
	else if(getGeneroJ()== 2){
        cout << "Genero: Accion" << endl;
	}
	else if(getGeneroJ() == 3){
        cout << "Genero: RPG " << endl;
	}else{
		cout << "Genero: Deportes " << endl;
	}

	if (getPlataforma() == 1){
        cout << "Plataforma: PC " << endl;
	}
	else if(getPlataforma()== 2){
        cout << "Plataforma: PSN " << endl;
	}
	else{
        cout << "Plataforma: XBOX " << endl;
	}

	Articulo::mostrar();
}
