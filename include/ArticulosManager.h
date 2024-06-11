#ifndef ARTICULOSMANAGER_H
#define ARTICULOSMANAGER_H
#include <iostream>
#include "ArticulosManager.h"
#include "Articulo.h"
#include "VHS.h"
#include "Juego.h"
#include "ArchivoVHS.h"
class ArticulosManager {
public:
	void menu();
	void menuVHS();
	void menuJuegos();
	void menuBuscarVHS();
	void menuBuscarJuegos();
private:
	void agregarVHS();
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
};

#endif

