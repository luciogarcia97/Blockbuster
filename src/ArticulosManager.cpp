#include <iostream>
#include "ArticulosManager.h"
#include "Articulo.h"
#include "VHS.h"
#include "Juego.h"
#include "ArchivoVHS.h"
#include "ArchivoJuego.h"
using namespace std;


void ArticulosManager::agregarVHS(){
	ArchivoVHS archiVHS;
	
	if(archiVHS.guardar(crearArticuloVHS()) == 1){
		cout<<"Agregado correctamente..."<<endl;
		system("pause");
	}
	ArticulosManager::menuVHS();
}
VHS ArticulosManager::crearArticuloVHS(){
	string titulo, genero, director;
	int duracion, numeroArt;
	Articulo articulo;
	
	articulo.cargar();
	
	cout<<"Numero de Articulo: ";
	numeroArt = validarCinInt();
	cin.ignore();
	cout << "Titulo: ";
	getline(cin, titulo); 
	cout << "Genero: ";
	getline(cin, genero);
	cout << "Director: ";
	getline(cin, director); 
	cout << "Duracion: ";
	duracion = validarCinInt();

	return VHS (titulo, genero, director, duracion);
}

void ArticulosManager::listarVHS(){
	ArchivoVHS archiVHS;
	int cantidad = archiVHS.contarRegistro();


	for(int i=0;i<cantidad;i++){
		VHS reg = archiVHS.leerRegistro(i);
		ArticulosManager::mostrarVHS(reg);
	}
}
void ArticulosManager::mostrarVHS(VHS reg) {
	cout << "Numero de Articulo: " << reg.getNumero() << endl;
	cout << "Titulo: " << reg.getTituloP() << endl;
	cout << "Genero: " << reg.getGeneroP() << endl;
	cout << "Director: " << reg.getDirector() << endl;
	cout << "Duracion: " << reg.getDuracion() << endl;
	cout << "Stock: " << reg.getStock() << endl;
	cout << "Precio: " << reg.getPrecio() << endl;
	cout << "------------------------------------" << endl;
}
void ArticulosManager::modificarValoresVHS(VHS &art){
	int stock;
	float precio;
	cout<<"Ingresar nuevo valor de STOCK: ";
	stock = validarCinInt();
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
		modificarValoresVHS(art);
		if(archi.grabar(index, art)){
		cout<<"Articulo modificado correctamente..."<<endl;
		}
		else{
			cout<<"No se pudo modificar el articulo..."<<endl;
		}
	}
	else{
		cout<<"Articulo no encontrado..."<<endl;
	}
}
void ArticulosManager::eliminarVHS(){
	int id, index;
	VHS art;
	ArchivoVHS archi;
	bool resp;
	cout<<"Ingrese numero de articulo: ";
	id = validarCinInt();
	index = archi.buscarXnumero(id);
	if(index != -2){
		art = archi.leerRegistro(index);
		mostrarVHS(art);
		cout<<"Desea eliminar el registro? (1-Si / 0-No)"<<endl;
		resp = validarCinBool();
		if(resp){
			art.setEstado(false);
			if(archi.grabar(index, art)){
				cout<<"Articulo eliminado correctamente..."<<endl;
			}
			else{
				cout<<"No se pudo eliminar el articulo..."<<endl;
			}
		}
	}
	else{
		cout<<"Articulo no encontrado..."<<endl;
	}
}
void ArticulosManager::menu(){
	int opc;
	do{
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
			menuJuegos();
			system("pause");
			break;
		}
	}while(opc != 0);
}
void ArticulosManager::menuVHS(){
	int opc;
	do{
		system("cls");
		cout<<"            VHS          "<<endl;
		cout<<"==========================="<<endl;
		cout<<"1) Agregar"<<endl;
		cout<<"2) Modificar"<<endl;
		cout<<"3) Listar"<<endl;
		cout<<"4) Buscar"<<endl;
		cout<<"5) Eliminar registro"<<endl;
		cout<<"==========================="<<endl;
		cout<<"0) SALIR"<<endl;
		opc = validarCinInt();
		system("cls");
		switch(opc){
		case 1:
			agregarVHS();
			system("pause");
			break;
		case 2:
			modificarVHS();
			system("pause");
			break;
		case 3:
			listarVHS();
			system("pause");
			break;
		case 4:
			menuBuscarVHS();
			system("pause");
			break;
		case 5:
			eliminarVHS();
			system("pause");
			break;
		default:
			cout << "Opci�n inv�lida. Intente nuevamente..." << endl;
			break;
		}
		}while(opc != 0);
	}
void ArticulosManager::menuBuscarVHS(){
	int opc;
	while(true){
		system("cls");
		cout<<"        BUSCAR POR         "<<endl;
		cout<<"==========================="<<endl;
		cout<<"1) Nuemro de Articulo"<<endl;
		cout<<"2) Titulo"<<endl;
		cout<<"3) Genero"<<endl;
		cout<<"4) Volver al menu anterior"<<endl;
		cout<<"==========================="<<endl;
		cout<<"0) SALIR"<<endl;
		opc = validarCinInt();
		system("cls");
		switch(opc){
		case 1:
			ArchivoVHS arch;
			int pos, nArt;
			cout<<"Ingresar numero de articulo: ";
			nArt = validarCinInt();
			pos = arch.buscarXnumero(nArt);
			ArticulosManager::mostrarVHS(arch.leerRegistro(pos));
			system("pause");
			break;
		case 2:
			pos = arch.buscarXtitulo();
			ArticulosManager::mostrarVHS(arch.leerRegistro(pos));
			system("pause");
			break;
		case 3:
			pos = arch.buscarXgenero();
			ArticulosManager::mostrarVHS(arch.leerRegistro(pos));
			system("pause");
			break;
		case 4:
			menuVHS();
			system("pause");
			break;
        }
     }
}



void ArticulosManager::agregarJuego(){
	Juego art;
	ArchivoJuego archiJ;
	art.cargar();
	if(archiJ.guardar(art)==1){
		cout<<"Agregado correctamente..."<<endl;
		system("pause");
	}
	ArticulosManager::menuJuegos();
}
void ArticulosManager::listarJuego(){
	ArchivoJuego archiJ;
	int cantidad = archiJ.contarRegistro();


	for(int i=0;i<cantidad;i++){
		Juego reg = archiJ.leerRegistro(i);
		ArticulosManager::mostrarJuego(reg);
	}
}
void ArticulosManager::mostrarJuego(Juego reg){
	cout << "Numero de Articulo: " << reg.getNumero() << endl;
	cout << "Titulo: " << reg.getTituloJ() << endl;
	cout << "Genero: " << reg.getGeneroJ() << endl;
	cout << "Plataforma: " << reg.getPlataforma() << endl;
	cout << "Stock: " << reg.getStock() << endl;
	cout << "Precio: " << reg.getPrecio() << endl;
	cout << "------------------------------------" <<endl;
}
void ArticulosManager::modificarValoresJuegos(Juego &art){
	int stock;
	float precio;
	cout<<"Ingresar nuevo valor de STOCK: ";
	stock = validarCinInt();
	cout<<"Ingresar nuevo valor de PRECIO: ";
	precio = validarCinFloat();
	cout<<endl;
	art.setStock(stock);
	art.setPrecio(precio);
}
void ArticulosManager::modificarJuego(){
	int id, index;
	Juego art;
	ArchivoJuego archi;
	cout<<"Ingrese numero de articulo: ";
	id = validarCinInt();
	index = archi.buscarXnumero(id);
	if(index != -2){
		art = archi.leerRegistro(index);
		mostrarJuego(art);
		modificarValoresJuegos(art);
		if(archi.grabar(index, art)){
			cout<<"Articulo modificado correctamente..."<<endl;
		}
		else{
			cout<<"No se pudo modificar el articulo..."<<endl;
		}
	}
	else{
		cout<<"Articulo no encontrado..."<<endl;
	}
}
void ArticulosManager::eliminarJuego(){
	int id, index;
	Juego art;
	ArchivoJuego archi;
	bool resp;
	cout<<"Ingrese numero de articulo: ";
	id = validarCinInt();
	index = archi.buscarXnumero(id);
	if(index != -2){
		art = archi.leerRegistro(index);
		mostrarJuego(art);
		cout<<"�Desea eliminar el registro? (1-Si / 0-No)"<<endl;
		resp = validarCinBool();
		if(resp){
			art.setEstado(false);
			if(archi.grabar(index, art)){
				cout<<"Articulo eliminado correctamente..."<<endl;
			}
			else{
				cout<<"No se pudo eliminar el articulo..."<<endl;
			}
		}
	}
	else{
		cout<<"Articulo no encontrado..."<<endl;
	}
}

bool ArticulosManager::validarExistenciaId(int numero_articulo, int tipo){
	ArchivoJuego objArchivoJuego;
	ArchivoVHS objArchivoVHS;
	switch (tipo)
	{
	case 1:
		if(objArchivoVHS.buscarXnumero(numero_articulo) >= 0){
			return true;
		}
		return false;
		break;
	case 2:
		if(objArchivoJuego.buscarXnumero(numero_articulo) >= 0){
			return true;
		}
		return false;
		break;
	default:
		return false;
		break;
	}
}

void ArticulosManager::menuJuegos(){
	int opc;
	while(true){
		system("cls");
		cout<<"           JUEGOS          "<<endl;
		cout<<"==========================="<<endl;
		cout<<"1) Agregar "<<endl;
		cout<<"2) Modificar "<<endl;
		cout<<"3) Listar "<<endl;
		cout<<"4) Buscar "<<endl;
		cout<<"5) Eliminar registro"<<endl;
		cout<<"6) Volver al menu anterior"<<endl;
		cout<<"==========================="<<endl;
		cout<<"0) SALIR"<<endl;
		opc = validarCinInt();
		system("cls");
		switch(opc){
		case 1:
			agregarJuego();
			system("pause");
			break;
		case 2:
			modificarJuego();
			system("pause");
			break;
		case 3:
			listarJuego();
			system("pause");
			break;
		case 4:
			menuBuscarJuegos();
			system("pause");
			break;
		case 5:
			eliminarJuego();
			system("pause");
			break;
		case 6:
			menu();
			return;
		default:
			cout << "Opci�n inv�lida. Intente nuevamente..." << endl;
			break;
		}
	}
}
void ArticulosManager::menuBuscarJuegos(){
	int opcion;
	while(true){
		system("cls");
		cout<<"        BUSCAR POR         "<<endl;
		cout<<"==========================="<<endl;
		cout<<"1) Nuemro de Articulo"<<endl;
		cout<<"2) Titulo"<<endl;
		cout<<"3) Genero"<<endl;
		cout<<"4) Volver al menu anterior"<<endl;
		cout<<"==========================="<<endl;
		cout<<"0) SALIR"<<endl;
		opcion = validarCinInt();
		system("cls");
		switch(opcion){
		case 1:
			ArchivoJuego arch;
			int pos, nArt;
			cout<<"Ingresar numero de articulo: ";
			nArt = validarCinInt();
			pos = arch.buscarXnumero(nArt);
			ArticulosManager::mostrarJuego(arch.leerRegistro(pos));
			system("pause");
			break;
		case 2:
			pos = arch.buscarXtitulo();
			ArticulosManager::mostrarJuego(arch.leerRegistro(pos));
			system("pause");
			break;
		case 3:
			pos = arch.buscarXgenero();
			ArticulosManager::mostrarJuego(arch.leerRegistro(pos));
			system("pause");
			break;
	    case 4:
			menuJuegos();
			system("pause");
			break;
		}
	}
	int opc;
	while(true){
		system("cls");
		cout<<"        BUSCAR POR         "<<endl;
		cout<<"==========================="<<endl;
		cout<<"1) Nuemro de Articulo"<<endl;
		cout<<"2) Titulo"<<endl;
		cout<<"3) Genero"<<endl;
		cout<<"4) Volver al menu anterior"<<endl;
		cout<<"==========================="<<endl;
		cout<<"0) SALIR"<<endl;
		opc = validarCinInt();
		system("cls");
		switch(opc){
		case 1:
			ArchivoJuego arch;
			int pos, nArt;
			cout<<"Ingresar numero de articulo: ";
			nArt = validarCinInt();
			pos = arch.buscarXnumero(nArt);
			ArticulosManager::mostrarJuego(arch.leerRegistro(pos));
			system("pause");
			break;
			//case 2:

			system("pause");
			break;
			//case 3:

			system("pause");
			break;
			//case 4:
			return;
			system("pause");
			break;
		}
	}
}
