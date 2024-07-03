#ifndef VHS_H
#define VHS_H
#include "Articulo.h"
#include <string>


class VHS : public Articulo {
public:
	VHS();
	VHS(std::string titulo, int genero, std::string director, int duracion);
	VHS(Articulo art,std::string titulo, int genero, std::string director, int duracion);
	std::string getTituloP();
	int getGeneroP();
	std::string getDirector();
	int getDuracion();
	void setTituloP(std::string titulo);
	void setGeneroP(int genero);
	void setDirector(std::string director);
	void setDuracion(int duracion);
	void cargar();
	void mostrar();
private:
	char _tituloP [30];
	int _generoP;
	char _director [30];
	int _duracion;
};

#endif

