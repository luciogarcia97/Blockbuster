#ifndef ARTICULOSMANAGER_H
#define ARTICULOSMANAGER_H
#include <iostream>
#include "Articulo.h"
#include "VHS.h"
#include "Juego.h"
#include "ArchivoVHS.h"
#include "ArchivoJuego.h"

using namespace std;

class ArticulosManager {
public:
	void menu();
	void menuVHS();
	void menuJuegos();
	void menuBuscarVHS();
	void menuBuscarJuegos();
	bool validarExistenciaId(int numero_articulo, int tipo);
private:
	void agregarVHS();
	VHS crearArticuloVHS();
	Juego crearArticuloJuego();
	Articulo cargarArticulo();
	void mostrarArticulo();
	void listarVHS();
	void mostrarVHS(VHS reg);
	void buscarVHS();
	void modificarValoresVHS(VHS &art);
	void modificarVHS();
	void eliminarVHS();
	void agregarJuego();
	void mostrarJuego(Juego reg);
	void modificarValoresJuegos(Juego &art);
	void listarJuego();
	void buscarJuego();
	void modificarJuego();
	void eliminarJuego();
	ArchivoVHS _archivoVHS;
	ArchivoJuego _archivoJuego;
};

#endif

