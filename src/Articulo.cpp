#include "Articulo.h"
#include "funciones.h"
#include <cstdlib>
#include <cstdio>
#include <iostream>
using namespace std;

Articulo::Articulo() {
	_numeroArt=0;
	_stock=0;
	_precio=0.0f;
	_estado=0;
}
Articulo::Articulo(int numeroArt, int stock, float precio, bool estado){
	setNumero(numeroArt);
	setStock(stock);
	setPrecio(precio);
	setEstado(estado);
}

void Articulo::setNumero(int numeroArt){
	_numeroArt=numeroArt;
}
void Articulo::setStock(int stock){
	_stock=stock;
}
void Articulo::setPrecio(float precio){
	_precio=precio;
}
void Articulo::setEstado(bool estado){
	_estado=estado;
}
int Articulo::getNumero(){
	return _numeroArt;
}
int Articulo::getStock(){
	return _stock;
}
int Articulo::getPrecio(){
	return _precio;
}
int Articulo::getEstado(){
	return _estado;
}
void Articulo::cargar(){
	int stock;
	float precio;
	bool estado;
	cin.ignore();
	cout<<"Stock: ";
	stock = validarCinInt();
	cin.ignore();
	cout<<"Precio: ";
	precio = validarCinFloat();
	cin.ignore();
	cout<<"Estado: ";
	estado = validarCinBool();
	setStock(stock);
	setPrecio(precio);
	setEstado(estado);
}
void Articulo::mostrar(){
	if(_estado==true){
	cout<<"Numero de Articulo: "<<_numeroArt<<endl;
	cout<<"Stock: "<<_stock<<endl;
	cout<<"Precio: "<<_precio<<endl;
	}
}
