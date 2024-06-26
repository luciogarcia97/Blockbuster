#ifndef ARCHIVOVHS_H
#define ARCHIVOVHS_H
#include "VHS.h"
#include "Juego.h"
#include "ArchivoJuego.h"
#include "Articulo.h"
#include <cstring>
#include <iostream>
#include "funciones.h"

using namespace std;

class ArchivoVHS {
public:
	bool guardar(VHS art);
	bool grabar(int index, VHS art);
	int buscarXnumero(int numeroArt);
	int buscarXtitulo();
	int buscarXgenero();
	VHS leerRegistro(int pos);
	bool listarRegistros();
	int contarRegistro();
	int getNumeroArticuloV();
private:
	
};

#endif

