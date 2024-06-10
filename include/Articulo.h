#ifndef ARTICULO_H
#define ARTICULO_H

#include "funciones.h"

class Articulo {
public:
	Articulo();
	Articulo(int numeroArt, int stock, float precio, bool estado);
	int getNumero();
	int getStock();
	int getPrecio();
	int getEstado();
	void setNumero(int numeroArt);
	void setStock(int stock);
	void setPrecio(float precio);
	void setEstado(bool estado);
	void mostrar();
	void cargar();
protected:
	int _numeroArt;
	int _stock;
	float _precio;
	bool _estado;
};

#endif

