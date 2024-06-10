#include <iostream>
#include "ArticulosManager.h"
#include "Articulo.h"
#include "VHS.h"
#include "Juego.h"
#include "ArchivoVHS.h"
using namespace std;


void ArticulosManager::agregarVHS(){
	VHS art;
	ArchivoVHS archiVHS;
	art.cargar();
	archiVHS.guardar(art);
}
void ArticulosManager::listarVHS(){
	ArchivoVHS archiVHS;
	archiVHS.listarRegistros();
}
void ArticulosManager::mostrarVHS(VHS reg) {
	cout << "Numero de Articulo: " << reg.getNumero() << endl;
	cout << "Titulo: " << reg.getTituloP() << endl;
	cout << "Genero: " << reg.getGeneroP() << endl;
	cout << "Director: " << reg.getDirector() << endl;
	cout << "Duracion: " << reg.getDuracion() << endl;
	cout << "Stock: " << reg.getStock() << endl;
	cout << "Precio: " << reg.getPrecio() << endl;
}
void ArticulosManager::modificarValoresVHS(VHS &art){
	int stock;
	float precio;
	cout<<"Ingresar nuevo valor de STOCK: ";
	stock = validarCinInt();
	cout<<endl;
	cout<<"Ingresar nuevo valor de PRECIO: ";
	precio = validarCinFloat();
	cout<<endl;
	art.setStock(stock);
	art.setPrecio(precio);
}

void ArticulosManager::modificarVHS(){
	int id, index;
	VHS art;
	ArchivoVHS archi;
	cout<<"Ingrese numero de articulo: ";
	id = validarCinInt();
	index = archi.buscarXnumero(id);
	if(index != -2){
		art = archi.leerRegistro(index);
		mostrarVHS(art);
	}
	else{
		cout<<"Producto NO encontrado..."<<endl;
	}
	modificarValoresVHS(art);
}
void ArticulosManager::menu(){
	int opc;
	while(true){
		system("cls");
		cout<<"   MENU ARTICULOS  "<<endl;
		cout<<"===================="<<endl;
		cout<<"1) VHS"<<endl;
		cout<<"2) JUEGOS"<<endl;
		cout<<"===================="<<endl;
		cout<<"0) SALIR"<<endl;
		opc = validarCinInt();
		system("cls");
		switch(opc){
		case 1:
			menuVHS();
			system("pause");
			break;
		case 2:
//			menuJuegos();
			system("pause");
			break;
		}
	}
}
void ArticulosManager::menuVHS(){
	int opc;
	while(true){
		system("cls");
		cout<<"         VHS        "<<endl;
		cout<<"===================="<<endl;
		cout<<"1) Agregar VHS"<<endl;
		cout<<"2) Modificar VHS"<<endl;
		cout<<"3) Listar VHS"<<endl;
		cout<<"4) Buscar VHS"<<endl;
		cout<<"5) Eliminar registro"<<endl;
		cout<<"===================="<<endl;
		cout<<"0) SALIR"<<endl;
		opc = validarCinInt();
		system("cls");
		switch(opc){
		case 1:
			agregarVHS();
			system("pause");
			break;
		case 2:

			system("pause");
			break;
		case 3:
			listarVHS();
			system("pause");
			break;
		case 4:

			system("pause");
			break;
		case 5:

			system("pause");
			break;
		}
	}
}


