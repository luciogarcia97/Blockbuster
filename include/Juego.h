#ifndef JUEGO_H
#define JUEGO_H
#include "Articulo.h"
#include <string>

class Juego : public Articulo {
public:
	Juego();
	Juego(std::string titulo, int genero, int plataforma);
	Juego(Articulo articulo, int numero,std::string titulo, int genero, int plataforma);
	std::string getTituloJ();
	int getGeneroJ();
	int getPlataforma();
	int getNumeroArtJ();
	void setNumeroArtJ(int numero);
	void setTituloJ(std::string titulo);
	void setGeneroJ(int genero);
	void setPlataforma(int plataforma);
	void cargar();
	void mostrar();
private:
	char _tituloJ [30];
	int _generoJ;
	int _plataforma;
	int _numeroArt;
};

#endif

