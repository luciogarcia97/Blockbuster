#ifndef ARCHIVOJUEGO_H
#define ARCHIVOJUEGO_H
#include "Juego.h"
class ArchivoJuego {
public:
	bool guardar(Juego art);
	bool grabar(int index, Juego art);
	int buscarXnumero(int numeroArt);
	int buscarXtitulo();
	int buscarXgenero(int genero);
	Juego leerRegistro(int pos);
	bool listarRegistros();
	int contarRegistro();
private:
};

#endif

