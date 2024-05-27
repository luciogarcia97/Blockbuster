#ifndef JUEGO_H
#define JUEGO_H
#include "Articulo.h"
#include <string>

class Juego : public Articulo {
public:
	Juego();
	Juego(std::string titulo, std::string genero, int plataforma);
	std::string getTituloJ();
	std::string getGeneroJ();
	int getPlataforma();
	void setTituloJ(std::string titulo);
	void setGeneroJ(std::string genero);
	void setPlataforma(int plataforma);
	void cargar();
	void mostrar();
private:
	char _tituloJ [30];
	char _generoJ [30];
	int _plataforma;
};

#endif

