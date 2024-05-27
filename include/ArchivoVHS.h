#ifndef ARCHIVOVHS_H
#define ARCHIVOVHS_H
#include "VHS.h"
#include "Articulo.h"

class ArchivoVHS {
public:
	ArchivoVHS();
	bool guardar(VHS art);
	int buscarXnumero(int numeroArt);
	VHS leerRegistro(int pos);
	bool listarRegistros();
	
private:
	
};

#endif

