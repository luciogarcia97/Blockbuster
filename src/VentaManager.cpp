#include "VentaManager.h"

void VentaManager::menu(){
	int option;
	while(true){
		system("cls");
		std::cout<<"   Menu de Ventas  "<<endl;
		std::cout<<"===================="<<endl;
		std::cout<<"1) Ingresar nueva venta"<<endl;
		std::cout<<"2) Listar todas las ventas"<<endl;
		std::cout<<"===================="<<endl;
		std::cout<<"0) SALIR"<<endl;
		cin>>option;
		system("cls");
		switch(option){
		case 1:
            agregarVenta();
			system("pause");
			break;
		case 2:
            listarVenta();
			system("pause");
			break;
		}
	}
}

Venta VentaManager::crearVenta(){
    int numero_cliente;
    int legajo_personal;
    int forma_pago;
    int numero_venta;
    Fecha timestamp;

    numero_venta = _archivoVenta.getNuevoId();
    cout << "Ingrese Venta # " << numero_venta << endl;

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
    std::cout << "4) La fecha de la operacion fue: " << timestamp.fechaTexto() << endl;

    return Venta(numero_venta,timestamp,numero_cliente,legajo_personal,forma_pago);
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
    std::cout << "4) La fecha de la operacion fue: " << timestamp.fechaTexto() << endl;
}

void VentaManager::mostrarVenta(Venta reg){
    std::cout << reg.getNumeroVenta() << "\t\t" << reg.getNumeroCliente() << "\t\t";
    reg.getFechaVenta().MostrarFecha();
    std::cout << "\t" << reg.getLegajo() << "\t\t" << reg.getFormaPago() << std::endl;
    std::cout << endl;
}

void VentaManager::agregarVenta(){
    if (_archivoVenta.agregarRegistro(crearVenta()))
    {
        cout << "El producto fue guardado con exito!" << endl;
    }else{
        cout << "No se pudo guardar el producto!" << endl;
    }
}

void VentaManager::listarVenta(){
    int cantidad = _archivoVenta.contarRegistros();
    Venta *obj;

    obj = new Venta[cantidad];
    if(obj == nullptr){
        cout << "No se pudo pedir memoria... " << endl;
        return;
    }

    _archivoVenta.leerTodos(obj,cantidad);
    headerVentas();
    for(int i=0; i<cantidad; i++)
    {
        mostrarVenta(obj[i]);
    }
}

void VentaManager::modificarVenta(){
    int idVentaModificar, posicion;
    Venta obj;

    cout << "Ingrese id del producto a modificar: ";
    idVentaModificar = validarCinInt();

    posicion = _archivoVenta.buscarRegistro(idVentaModificar);

    if(posicion != -1)
    {
        obj = _archivoVenta.leerRegistro(posicion);

        mostrarVenta(obj);

        volverCargarVenta(obj);

        if(_archivoVenta.agregarRegistro(obj, posicion)) cout << "Se modifico con exito!" << endl;
        else cout << "No se pudo modificar el producto!" << endl;
    }
    else cout << "No se encuentra ese producto!" << endl;
}