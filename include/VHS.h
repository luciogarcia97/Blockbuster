#ifndef VHS_H
#define VHS_H
#include "Articulo.h"
#include <string>


class VHS : public Articulo {
public:
	VHS();
	VHS(std::string titulo, std::string genero, std::string director, int duracion);
	std::string getTituloP();
	std::string getGeneroP();
	std::string getDirector();
	int getDuracion();
	void setTituloP(std::string titulo);
	void setGeneroP(std::string genero);
	void setDirector(std::string director);
	void setDuracion(int duracion);
	void cargar();
	void mostrar();
private:
	char _tituloP [30];
	char _generoP [30];
	char _director [30];
	int _duracion;
};

#endif

