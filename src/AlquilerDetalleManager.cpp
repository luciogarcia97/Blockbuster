#include "AlquilerDetalleManager.h"

void AlquilerDetalleManager::cargarDetalleAlquiler(int numeroAlquiler){
    int numero_articulo;
    int cantidad;
    float precio = 0;
    int opcion;
    ArchivoVHS dataVHS;
    ArchivoJuego dataJuego;
    ArticulosManager am;

    do
    {
        system("cls");
        std::cout << "Carga del detalle del alquiler #" << numeroAlquiler << std::endl;
        std::cout << "--------------------------" << std::endl << std::endl;


        do
        {
            std::cout << "1) Ingrese el numero de articulo: ";
            numero_articulo = validarCinInt();
        } while (!am.validarExistenciaId(numero_articulo));

        std::cout << "2) Ingrese la cantidad de productos: ";
        cantidad = validarCinInt();

        //TO DO: Carga de precio con Articulo => cantidad * precio_unitario
        int posicionVHS = dataVHS.buscarXnumero(numero_articulo);
        int posicionJuego = dataJuego.buscarXnumero(numero_articulo);
        posicionVHS >= 0? precio = dataVHS.leerRegistro(posicionVHS).getPrecio() * cantidad:precio = dataJuego.leerRegistro(posicionJuego).getPrecio() * cantidad;

        agregarAlquilerDetalle(DetalleAlquiler(numeroAlquiler,numero_articulo,cantidad,precio));
        std::cout << "Desea cargar otro producto? (1-Si o 2-No): ";
        opcion = validarCinInt();
    } while (opcion == 1);
    
}
void AlquilerDetalleManager::agregarAlquilerDetalle(DetalleAlquiler obj){
    if (_archivoAlquilerDetalle.agregarRegistroAlquilerDetalle(obj))
    {
        std::cout << "El detalle del alquiler #" << obj.getNumeroAlquilerDetalle() << " se registro con exito" << std::endl;
    }else{
        std::cout << "No se pudo guardar el detalle!" << std::endl;
    }
}
void AlquilerDetalleManager::listarAlquilerDetalle(){
    int cantidad = _archivoAlquilerDetalle.contarRegistros();
    DetalleAlquiler *obj;
    
    obj = new DetalleAlquiler[cantidad];
    if (obj == nullptr)
    {
        std::cout << "No se pudo pedir memoria..." << std::endl;
        delete []obj;
        return;
    }
    
    headerAlquilerDetalle();
    for (int i = 0; i < cantidad; i++) mostrarAlquilerDetalle(_archivoAlquilerDetalle.leerRegistro(i));
    
    delete []obj;
}

void AlquilerDetalleManager::listarAlquilerDetalleById(){
    int id;
    std::cout << "Ingrese el numero de alquiler a buscar: ";
    id = validarCinInt();

    int cantidad = _archivoAlquilerDetalle.contarRegistrosRepetidos(id);
    DetalleAlquiler *obj;
    obj = new DetalleAlquiler[cantidad];
    if (obj == nullptr)
    {
        std::cout << "No se pudo pedir memoria..." << std::endl;
        delete []obj;
        return;
    }

    obj = buscarAlquilerDetalle(id);
    for (int i = 0; i < cantidad; i++)
    {
        if (obj[i].getNumeroAlquilerDetalle() == -1)
        {
            std::cout << "Algo fallo en la busqueda de alquileres" << std::endl;
            delete []obj;
            return;
        }else if (obj[i].getNumeroAlquilerDetalle() == -2)
        {
            std::cout << "La cantidad de busqueda no coincide con la registrada" << std::endl;
            delete []obj;
            return;
        }
        if (i == 0) headerAlquilerDetalle();
        mostrarAlquilerDetalle(obj[i]);
    }
    delete []obj;
}

void AlquilerDetalleManager::mostrarAlquilerDetalle(DetalleAlquiler reg){
    std::cout << reg.getNumeroAlquilerDetalle() << "\t\t" << reg.getNumeroArticuloAlquilerDetalle() << "\t\t" << reg.getCantidad() << "\t\t" << reg.getPrecio() << std::endl;
}

DetalleAlquiler* AlquilerDetalleManager::buscarAlquilerDetalle(int id){
    int cantidad = _archivoAlquilerDetalle.contarRegistrosRepetidos(id);
    DetalleAlquiler *obj;
    obj = new DetalleAlquiler[cantidad];
    if (obj == nullptr)
    {
        std::cout << "No se pudo pedir memoria..." << std::endl;
        for (int i = 0; i < cantidad; i++)
        {
            obj[i] = DetalleAlquiler();
            obj[i].setNumeroAlquilerDetalle(-1);
        }
        return obj;
        delete []obj;
    }

    int indiceIgualdad = 0;
    int ciclos = _archivoAlquilerDetalle.contarRegistros();
    for (int i = 0; i < ciclos; i++)
    {
        if (_archivoAlquilerDetalle.leerRegistro(i).getNumeroAlquilerDetalle() == id){
            obj[indiceIgualdad] = _archivoAlquilerDetalle.leerRegistro(i);
            indiceIgualdad++;
        }
    }

    if (indiceIgualdad != cantidad)
    {
        std::cout << "Algo fallo en la busqueda..." << std::endl;
        for (int i = 0; i < cantidad; i++)
        {
            obj[i] = DetalleAlquiler();
            obj[i].setNumeroAlquilerDetalle(-2);
        }
        return obj;
        delete []obj;
    }
    
    return obj;
    delete []obj;
}
void AlquilerDetalleManager::menu(){
int option;
	do{
		system("cls");
		std::cout<<"   Menu de Alquiler Detalle " << std::endl;
		std::cout<<"==============================" << std::endl;
		std::cout<<"1) Ingresar nuevo alquiler detalle" << std::endl;
		std::cout<<"2) Listar todos los alquileres detalle" << std::endl;
		std::cout<<"3) Buscar alquiler detalle por numero de alquiler" << std::endl;
		std::cout<<"==============================" << std::endl;
		std::cout<<"0) SALIR"<< std::endl;
		option = validarCinInt();
		system("cls");

		switch(option){
		case 1:
            system("cls");
            int numero_alquiler;
            std::cout << "1) Ingrese el numero de alquiler: ";
            numero_alquiler = validarCinInt();
            cargarDetalleAlquiler(numero_alquiler);
			system("pause");
			break;
		case 2:
            listarAlquilerDetalle();
			system("pause");
			break;
        case 3:
            listarAlquilerDetalleById();
			system("pause");
			break;
        case 0:
            break;
        default:
            std::cout << "Opcion incorrecta, presione cualquier tecla para volver a seleccionar opcion" << std::endl;
			system("pause");
			break;
		}
	}while (option != 0);
}