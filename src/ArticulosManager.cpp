#include "ArticulosManager.h"


void ArticulosManager::agregarVHS(){
	if(_archivoVHS.guardar(crearArticuloVHS()) == 1){
		cout<<"Agregado correctamente..."<<endl;
		system("pause");
	}else
	{
		cout<<"Hubo un error en guardar el VHS"<<endl;
		system("pause");
	}
}
VHS ArticulosManager::crearArticuloVHS(){
	string titulo, director;
	int genero;
	int duracion, numeroArt;
    Articulo a;

	cin.ignore();
	numeroArt = _archivoVHS.getNumeroArticuloV();
	cout<<"Carga del articulo VHS #" << numeroArt << endl;
	cout << "Titulo: ";
	getline(cin, titulo);
	cout << "Genero: 1-Terror 2-Accion 3-Suspenso 4-Drama 5-Infantil : ";
	genero = validarCinInt();
	cin.ignore();
	cout << "Director: ";
	getline(cin, director);
	cout << "Duracion: ";
	duracion = validarCinInt();
	
	a = cargarArticulo();

	return VHS (a,numeroArt,titulo, genero, director, duracion);
}

void ArticulosManager::listarVHS(){
	ArchivoVHS archiVHS;
	int cantidad = archiVHS.contarRegistro();


	for(int i=0;i<cantidad;i++){
		VHS reg = archiVHS.leerRegistro(i);
		mostrarVHS(reg);
	}
}
void ArticulosManager::mostrarVHS(VHS reg) {
	cout << "Numero de Articulo: " << reg.getNumeroArtV() << endl;
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
		case 0:
			break;
		case 1:
			menuVHS();
			break;
		case 2:
			menuJuegos();
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
		cout<<"6) Volver al menu de stock"<<endl;
		opc = validarCinInt();
		system("cls");
		switch(opc){
		case 1:
			agregarVHS();
			break;
		case 2:
			modificarVHS();
			break;
		case 3:
			listarVHS();
			system("pause");
			break;
		case 4:
			menuBuscarVHS();
			break;
		case 5:
			eliminarVHS();
			break;
		case 6:
			break;
		default:
			cout << "Opcion invalida. Intente nuevamente..." << endl;
			break;
		}
		}while(opc != 6);
	}
void ArticulosManager::menuBuscarVHS(){
	int opc;
	do{
		system("cls");
		cout<<"==========================="<<endl;
		cout<<"1) Nuemro de Articulo"<<endl;
		cout<<"2) Titulo"<<endl;
		cout<<"3) Genero"<<endl;
		cout<<"4) Volver al menu anterior"<<endl;
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
			int genero,posicion;
			cout << "Ingrese el Genero: 1-Suspenso 2-Animada 3-Terror 4-Comedia 5-Ciencia ficcion";
			genero = validarCinInt();

			posicion = _archivoVHS.buscarXgenero(genero);

			mostrarVHS(_archivoVHS.leerRegistro(posicion));
			system("pause");
			break;
		case 4:
			break;
		default:
			cout << "Opcion invalida. Intente nuevamente..." << endl;
			system("pause");
			break;
        }
     }while(opc !=4);
}

Articulo ArticulosManager::cargarArticulo(){
	int stock;
	float precio;
	bool estado;
	
	cin.ignore();
	cout<<"Stock: ";
	stock = validarCinInt();
	cin.ignore();
	cout<<"Precio: ";
	precio = validarCinFloat();
	cin.ignore();
	cout<<"Estado: ";
	estado = validarCinBool();
	
	return Articulo(stock, precio, estado);
}

void ArticulosManager::mostrarArticulo(){
	Articulo articulo;
	cout<<"Stock: "<<articulo.getStock()<<endl;
	cout<<"Precio: "<<articulo.getPrecio()<<endl;
	cout<<"Estado: "<<articulo.getEstado()<<endl;
}

void ArticulosManager::agregarJuego(){
	if(_archivoJuego.guardar(crearArticuloJuego()) == 1){
		cout<<"Agregado correctamente..."<<endl;
		system("pause");
	}else
	{
		cout<<"Hubo un error en guardar el VHS"<<endl;
		system("pause");
	}
}
Juego ArticulosManager::crearArticuloJuego(){
	string titulo;
	int plataforma, genero, numeroArt;
	
	numeroArt = _archivoJuego.getNumeroArticuloJ();
	cout<<"Carga del articulo Juego #" << numeroArt << endl;
	cin.ignore();
	cout<<"Titulo: ";
	getline(cin, titulo); 
	
	cout<<"Genero: 1-Aventura 2-Accion 3-RPG 4-Deportes";
	genero = validarCinInt();

	while (genero != 1 && genero != 2 && genero != 3 && genero != 4)
    {
		cout << "Dato invalido, ingrese nuevamente :" << endl;
		genero = validarCinInt();
	}
	
	cout<<"Plataforma: 1-PC 2-PSN 3-XBOX" << endl;
    plataforma = validarCinInt();

	while (plataforma != 1 && plataforma != 2 && plataforma !=3)
    {
    cout << "Dato invalido, ingrese nuevamente :" << endl;
    plataforma = validarCinInt();
	}

	Articulo a;
	a = cargarArticulo();

	return Juego (a,numeroArt,titulo, genero, plataforma);
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
	cout << "Numero de Articulo: " << reg.getNumeroArtJ() << endl;
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
	do{
		system("cls");
		cout<<"           JUEGOS          "<<endl;
		cout<<"==========================="<<endl;
		cout<<"1) Agregar "<<endl;
		cout<<"2) Modificar "<<endl;
		cout<<"3) Listar "<<endl;
		cout<<"4) Buscar "<<endl;
		cout<<"5) Eliminar registro"<<endl;
		cout<<"6) Volver al menu anterior"<<endl;
		opc = validarCinInt();
		system("cls");
		switch(opc){
		case 1:
			agregarJuego();
			break;
		case 2:
			modificarJuego();
			break;
		case 3:
			listarJuego();
			system("pause");
			break;
		case 4:
			menuBuscarJuegos();
			break;
		case 5:
			eliminarJuego();
			break;
		case 6:
			break;
		default:
			cout << "Opcion invalida. Intente nuevamente..." << endl;
			break;
		}
	} while(opc !=6 );
}
void ArticulosManager::menuBuscarJuegos(){
	int opcion;
	do{
		system("cls");
		cout<<"        BUSCAR POR         "<<endl;
		cout<<"==========================="<<endl;
		cout<<"1) Nuemro de Articulo"<<endl;
		cout<<"2) Titulo"<<endl;
		cout<<"3) Genero"<<endl;
		cout<<"4) Volver al menu anterior"<<endl;
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
			int genero,posicion;
			cout << "Ingrese el Genero: 1-Aventura 2-Accion 3-RPG 4-Deportes";
			genero = validarCinInt();

			posicion = arch.buscarXgenero(genero);
			ArticulosManager::mostrarJuego(arch.leerRegistro(posicion));
			system("pause");
			break;
		case 4:
			break;
	    default:
			cout << "dato invalido, reingrese nuevamente";
			system("pause");
			break;
		}
	}while(opcion !=4);
}
