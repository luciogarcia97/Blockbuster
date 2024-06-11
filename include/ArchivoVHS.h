#ifndef ARCHIVOVHS_H
#define ARCHIVOVHS_H
#include "VHS.h"
#include "Articulo.h"
#include <cstring>

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
private:
	
};

#endif

