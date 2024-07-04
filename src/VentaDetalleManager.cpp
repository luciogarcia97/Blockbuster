#include "VentaDetalleManager.h"

void VentaDetalleManager::cargarDetalleVenta(int numeroVenta){
    int numero_articulo;
    int cantidad;
    float precio = 0;
    int opcion;
    int tipo_articulo;
    ArchivoVHS dataVHS;
    ArchivoJuego dataJuego;
    ArticulosManager am;
    do
    {
        system("cls");
        std::cout << "Carga del detalle de la venta #" << numeroVenta << std::endl;
        std::cout << "--------------------------------------" << std::endl << std::endl;

        std::cout << "Ingrese el tipo de articulo (1-VHS, 2-Juego): ";
        tipo_articulo = validarCinInt();
        while (tipo_articulo != 1 && tipo_articulo != 2)
        {
            std::cout << "Tipo de articulo incorrecto, intente nuevamente (1-VHS, 2-Juego): ";
            tipo_articulo = validarCinInt();
        }
        
        std::cout << "1) Ingrese el numero de articulo: ";
        numero_articulo = validarCinInt();

        while (!am.validarExistenciaId(numero_articulo,tipo_articulo)){ 
            std::cout << "El articulo no existe, ingrese nuevamente: ";numero_articulo = validarCinInt();
        }

        std::cout << "2) Ingrese la cantidad de productos: ";
        cantidad = validarCinInt();

        if (tipo_articulo == 1)
        {
            int posicionVHS = dataVHS.buscarXnumero(numero_articulo);
            precio = dataVHS.leerRegistro(posicionVHS).getPrecio() * cantidad;
        }else if (tipo_articulo == 2)
        {
            int posicionJuego = dataJuego.buscarXnumero(numero_articulo);
            precio = dataJuego.leerRegistro(posicionJuego).getPrecio() * cantidad;
        }

        agregarVentaDetalle(Detalleventa(numeroVenta,numero_articulo, tipo_articulo,cantidad,precio));
        std::cout << "Desea cargar otro producto? (1-Si o 2-No): ";
        opcion = validarCinInt();
    } while (opcion == 1);
    
}
void VentaDetalleManager::agregarVentaDetalle(Detalleventa obj){
    if (_archivoVentaDetalle.agregarRegistroVentaDetalle(obj))
    {
        std::cout << "El detalle de la venta #" << obj.getnumventa() << " se registro con exito" << std::endl;
    }else{
        std::cout << "No se pudo guardar el detalle!" << std::endl;
    }
}
void VentaDetalleManager::listarVentaDetalle(){
    int cantidad = _archivoVentaDetalle.contarRegistros();
    if (cantidad == -1)
    {
        cout << "No existe el archivo VentaDetalle.dat" << endl;
        return;
    }

    Detalleventa *obj;
    
    obj = new Detalleventa[cantidad];
    if (obj == nullptr)
    {
        std::cout << "No se pudo pedir memoria..." << std::endl;
        delete []obj;
        return;
    }
    
    headerVentaDetalle();
    for (int i = 0; i < cantidad; i++) mostrarVentaDetalle(_archivoVentaDetalle.leerRegistro(i));
    
    delete []obj;
}

void VentaDetalleManager::listarVentaDetalleById(){
    int id;
    std::cout << "Ingrese el numero de venta a buscar: ";
    id = validarCinInt();

    int cantidad = _archivoVentaDetalle.contarRegistrosRepetidos(id);

    Detalleventa *obj;
    obj = new Detalleventa[cantidad];
    if (obj == nullptr)
    {
        std::cout << "No se pudo pedir memoria..." << std::endl;
        delete []obj;
        return;
    }

    obj = buscarVentaDetalle(id);
    for (int i = 0; i < cantidad; i++)
    {
        if (obj[i].getnumventa() == -1)
        {
            std::cout << "Algo fallo en la busqueda de alquileres" << std::endl;
            delete []obj;
            return;
        }else if (obj[i].getnumventa() == -2)
        {
            std::cout << "La cantidad de busqueda no coincide con la registrada" << std::endl;
            delete []obj;
            return;
        }
        if (i == 0) headerVentaDetalle();
        mostrarVentaDetalle(obj[i]);
    }
    delete []obj;
}

void VentaDetalleManager::mostrarVentaDetalle(Detalleventa reg){
    std::cout << reg.getnumventa() << "\t\t" << reg.getnumarticulo() << "\t\t" << reg.getTipoArticulo() << "\t\t" << reg.getcantidad() << "\t\t" << reg.getprecio() << std::endl;
}

Detalleventa* VentaDetalleManager::buscarVentaDetalle(int id){
    int cantidad = _archivoVentaDetalle.contarRegistrosRepetidos(id);
    Detalleventa *obj;
    obj = new Detalleventa[cantidad];
    if (obj == nullptr)
    {
        std::cout << "No se pudo pedir memoria..." << std::endl;
        for (int i = 0; i < cantidad; i++)
        {
            obj[i] = Detalleventa();
            obj[i].setnumarticulo(-1);
        }
        return obj;
        delete []obj;
    }
    
    if (!validarExistenciaId(id))
    {
        std::cout << "No existe el detalle de la venta ingresada" << std::endl;
        return obj;
        delete []obj;
    }
    int indiceIgualdad = 0;
    int ciclos = _archivoVentaDetalle.contarRegistros();
    for (int i = 0; i < ciclos; i++)
    {
        if (_archivoVentaDetalle.leerRegistro(i).getnumventa() == id){
            obj[indiceIgualdad] = _archivoVentaDetalle.leerRegistro(i);
            indiceIgualdad++;
        }
    }

    if (indiceIgualdad != cantidad)
    {
        std::cout << "Algo fallo en la busqueda..." << std::endl;
        for (int i = 0; i < cantidad; i++)
        {
            obj[i] = Detalleventa();
            obj[i].setnumventa(-2);
        }
        return obj;
        delete []obj;
    }
    
    return obj;
    delete []obj;
}
void VentaDetalleManager::menu(){
int option;
	do{
		system("cls");
		std::cout<<"   Menu de Venta Detalle " << std::endl;
		std::cout<<"==============================" << std::endl;
		std::cout<<"1) Ingresar nuevo venta detalle" << std::endl;
		std::cout<<"2) Listar todos los venta detalle" << std::endl;
		std::cout<<"3) Buscar venta detalle por numero de venta" << std::endl;
		std::cout<<"==============================" << std::endl;
		std::cout<<"0) SALIR"<< std::endl;
		option = validarCinInt();
		system("cls");

		switch(option){
		case 1:
            system("cls");
            int numero_venta;
            std::cout << "1) Ingrese el numero de venta: ";
            numero_venta = validarCinInt();
            cargarDetalleVenta(numero_venta);
			break;
		case 2:
            listarVentaDetalle();
			system("pause");
			break;
        case 3:
            listarVentaDetalleById();
			system("pause");
			break;
        case 0:
            break;
        default:
            std::cout << "Opcion incorrecta, presione cualquier tecla para volver a seleccionar opcion" << std::endl;
			break;
		}
	}while (option != 0);
}

bool VentaDetalleManager::validarExistenciaId(int numeroVenta){
    int cantidad = _archivoVentaDetalle.contarRegistros();
    
    for (int i = 0; i < cantidad; i++)
    {
        if (_archivoVentaDetalle.leerRegistro(i).getnumventa() == numeroVenta)
        {
            return true;
        }
    }
    return false;
}