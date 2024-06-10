#include "VentaManager.h"

Venta VentaManager::crearVenta(){
    int numero_cliente;
    int legajo_personal;
    int forma_pago;
    int numero_venta;
    Fecha timestamp;

    std::cout << "Carga de datos para Venta" << std::endl;
    std::cout << "-------------------------" << std::endl << std::endl;
    numero_venta = _archivoVenta.getNuevoId();
    std::cout << "Ingrese Venta #" << numero_venta << std::endl;

    //Carga numero de cliente con validacion
    std::cout << "1) Ingrese el numero de cliente: ";
    numero_cliente = validarCinInt();

    //Carga numero de legajo con validacion
    std::cout << "2) Ingrese el legajo del vendedor: ";
    legajo_personal = validarCinInt();

    //Carga forma de pago de cliente con validacion
    std::cout << "3) Ingrese el metodo de pago: ";
    forma_pago = validarCinInt();

    //Carga de la venta detalle
    VentaDetalleManager vdm;
    vdm.cargarDetalleVenta(numero_venta);
    
    //Carga la fecha de compra del momento en el cual se ejecuto la carga.
    timestamp = Fecha();
    std::cout << "4) La fecha de la operacion fue: " << timestamp.fechaTexto() << std::endl;
    
    system("cls");
    std::cout << "Se registro la venta correctamente!" << std::endl;
    return Venta(numero_venta, timestamp, numero_cliente,legajo_personal, forma_pago);
}

void VentaManager::volverCargarVenta(Venta &reg){
    int numero_cliente;
    int legajo_personal;
    int forma_pago;
    Fecha timestamp;

    //Carga numero de cliente con validacion
    std::cout << "1) Ingrese el numero de cliente: ";
    numero_cliente = validarCinInt();

    //Carga numero de legajo con validacion
    std::cout << "2) Ingrese el legajo del vendedor: ";
    legajo_personal = validarCinInt();

    //Carga forma de pago de cliente con validacion
    std::cout << "3) Ingrese el metodo de pago: ";
    forma_pago = validarCinInt();

    //Carga la fecha de compra del momento en el cual se ejecuto la carga.
    timestamp = Fecha();
    std::cout << "4) La fecha de la operacion fue: " << timestamp.fechaTexto() << std::endl;

    reg.setNumeroCliente(numero_cliente);
    reg.setLegajo(legajo_personal);
    reg.setFormaPago(forma_pago);
    reg.setFechaCompra(timestamp);
}

void VentaManager::mostrarVenta(Venta reg){
    std::cout << reg.getNumeroVenta() << "\t\t" << reg.getNumeroCliente() << "\t\t";
    reg.getFechaVenta().MostrarFecha();
    std::cout << "\t" << reg.getLegajo() << "\t\t" << reg.getFormaPago() << std::endl;
    std::cout << std::endl;
}

void VentaManager::agregarVenta(){
    Venta obj = crearVenta();
    if (_archivoVenta.agregarRegistro(obj))
    {
        std::cout << "La venta fue guardada con exito!" << std::endl;
    }else{
        std::cout << "No se pudo guardar la venta!" << std::endl;
    }
}

void VentaManager::listarVenta(){
    int cantidad = _archivoVenta.contarRegistros();
    Venta *obj;

    obj = new Venta[cantidad];
    if(obj == nullptr){
        cout << "No se pudo pedir memoria... " << std::endl;
        delete []obj;
        return;
    }

    headerVentas();
    for(int i=0; i<cantidad; i++)
    {
        mostrarVenta(_archivoVenta.leerRegistro(i));
    }
    
    delete []obj;
}

void VentaManager::modificarVenta(){
    int idVentaModificar, posicion;
    Venta obj;

    cout << "Ingrese id de la venta a modificar: ";
    idVentaModificar = validarCinInt();

    posicion = _archivoVenta.buscarRegistro(idVentaModificar);

    if(posicion != -1)
    {
        obj = _archivoVenta.leerRegistro(posicion);

        mostrarVenta(obj);

        volverCargarVenta(obj);

        if(_archivoVenta.agregarRegistro(obj, posicion)) cout << "Se modifico con exito!" << std::endl;
        else cout << "No se pudo modificar la venta!" << std::endl;
    }
    else cout << "No se encuentra esa venta!" << std::endl;
}

void VentaManager::buscarVenta(){
    int id, posicion;
    
    std::cout << "Ingrese el id de venta a buscar: ";
    id = validarCinInt();

    posicion = _archivoVenta.buscarRegistro(id);
    headerVentas();
    mostrarVenta(_archivoVenta.leerRegistro(posicion));
}

void VentaManager::menu(){
	int option;
    VentaDetalleManager vdm;
	do{
		system("cls");
		std::cout<<"   Menu de Ventas  " << std::endl;
		std::cout<<"====================" << std::endl;
		std::cout<<"1) Ingresar nueva venta" << std::endl;
		std::cout<<"2) Listar todas las ventas" << std::endl;
		std::cout<<"3) Buscar venta" << std::endl;
		std::cout<<"4) Detalle de venta" << std::endl;
		std::cout<<"====================" << std::endl;
		std::cout<<"0) SALIR"<< std::endl;
		option = validarCinInt();
		system("cls");

		switch(option){
		case 1:
            agregarVenta();
			break;
		case 2:
            listarVenta();
			break;
        case 3:
            buscarVenta();
			break;
        case 4:
            vdm.menu();
			break;
        case 0:
            break;
        default:
            std::cout << "Opcion incorrecta, presione cualquier tecla para volver a seleccionar opcion" << std::endl;
			break;
		}
        system("pause");
	}while (option != 0);
    
}