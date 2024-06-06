#include "AlquilerManager.h"

Alquiler AlquilerManager::crearAlquiler(){
    int numero_alquiler;
    Fecha fecha_alquiler;
    int numero_cliente;
    int legajo_personal;
    int forma_pago;
    bool estado_alquiler;

    std::cout << "Carga de datos para Alquiler" << std::endl;
    std::cout << "--------------------------" << std::endl << std::endl;

    numero_alquiler = _archivoAlquiler.getNuevoId();
    std::cout << "Carga de Alquiler #" << numero_alquiler << std::endl;

    std::cout << "1) Ingrese el numero de cliente: ";
    numero_cliente = validarCinInt();

    std::cout << "2) Ingrese el legajo del vendedor: ";
    legajo_personal = validarCinInt();

    std::cout << "3) Ingrese el metodo de pago: ";
    forma_pago = validarCinInt();

    fecha_alquiler = Fecha();
    estado_alquiler = true;

    int dia, mes, anio;
    std::cout << "4)Detalle la fecha de devolucion obligatoria: " << std::endl;
    std::cout << "Dia: ";
    dia = validarCinInt();
    std::cout << "Mes: ";
    mes = validarCinInt();
    std::cout << "Anio: ";
    anio = validarCinInt();

    Fecha fecha_obligada_devolucion(dia,mes,anio);
    Fecha fecha_entrega = Fecha();

    AlquilerDetalleManager ADM;

    ADM.cargarDetalleAlquiler(numero_alquiler);


    system("cls");
    std::cout << "Se registro el alquiler correctamente!" << std::endl;
    return Alquiler(legajo_personal, numero_cliente, forma_pago, numero_alquiler, fecha_alquiler, fecha_obligada_devolucion,fecha_entrega, estado_alquiler);
}

void AlquilerManager::agregarAlquiler(){
    Alquiler obj = crearAlquiler();
    if (_archivoAlquiler.agregarRegistroAlquiler(obj))
    {
        std::cout << "El Alquiler se registro con exito" << std::endl;
    }else{
        std::cout << "No se pudo guardar el alquiler!" << std::endl;
    }

}

void AlquilerManager::listarAlquiler(){
    int cantidad = _archivoAlquiler.contarRegistros();
    Alquiler *obj;

    obj = new Alquiler[cantidad];
    if(obj == nullptr){
        std::cout << "No se pudo pedir memoria..." << std::endl;
        delete []obj;
        return;
    }

    headerAlquiler();
    for (int i = 0; i < cantidad; i++)
    {
        mostrarAlquiler(_archivoAlquiler.leerRegistro(i));
    }

    delete []obj;
}

void AlquilerManager::mostrarAlquiler(Alquiler reg){
    std::cout << reg.getNumeroAlquiler() << "\t\t" << reg.getNumeroCliente() << "\t\t";
    reg.getFechaAlquiler().MostrarFecha();
    std::cout << "\t" << reg.getLegajo() << "\t\t" << reg.getFormaPago() << "\t\t";
    reg.getFechaObligadaDevolucion().MostrarFecha();
    std::cout << "\t\t\t";
    if (validarIgualdadFechas(reg.getFechaAlquiler(),reg.getFechaEntrega()) && reg.getEstadoAlquiler()) std::cout << "null";
    else reg.getFechaEntrega().MostrarFecha();
    std::cout << "\t\t\t";
    std::cout << (reg.getEstadoAlquiler()? "En Curso":" Finalizado") << std::endl;
}

bool AlquilerManager::validarIgualdadFechas(Fecha fecha1, Fecha fecha2){
  if (fecha1.getAnio() == fecha2.getAnio()){
    if(fecha1.getMes() == fecha2.getMes()){
      if (fecha1.getDia() == fecha2.getDia()){
        return true;
      }
    }
  }
  return false;
}

Alquiler AlquilerManager::buscarAlquiler(){
    int id, posicion;

    std::cout << "Ingrese el numero de alquiler a buscar: ";
    id = validarCinInt();

    posicion = _archivoAlquiler.buscarRegistro(id);
    return _archivoAlquiler.leerRegistro(posicion);
}

void AlquilerManager::devolucionAlquiler(){
    int opcion;
    Alquiler reg = buscarAlquiler();
    int posicion = _archivoAlquiler.buscarRegistro(reg.getNumeroAlquiler());
    Fecha timestamp;
    mostrarAlquiler(reg);
    std::cout << std::endl << "Actualizar el alquiler como entregado? (1-Si o 0-No)" << std::endl;
    opcion = validarCinInt();
    if (opcion == 1){
        //Registro la fecha del momento y actualizo el estado del alquiler
        reg.setFechaEntrega(timestamp);
        reg.setEstadoAlquiler(false);
        _archivoAlquiler.guardarRegistro(posicion,reg);
    }
}

void AlquilerManager::menu(){
    int option;
    AlquilerDetalleManager adm;
	do{
		system("cls");
		std::cout<<"   Menu de Alquiler  " << std::endl;
		std::cout<<"====================" << std::endl;
		std::cout<<"1) Ingresar nuevo alquiler" << std::endl;
		std::cout<<"2) Listar todos los alquileres" << std::endl;
		std::cout<<"3) Buscar alquiler" << std::endl;
		std::cout<<"4) Registrar entrega de alquiler" << std::endl;
		std::cout<<"5) Detalle de alquiler" << std::endl;
		std::cout<<"====================" << std::endl;
		std::cout<<"0) SALIR"<< std::endl;
		std::cin>>option;
		system("cls");

		switch(option){
		case 1:
            agregarAlquiler();
			system("pause");
			break;
		case 2:
            listarAlquiler();
			system("pause");
			break;
        case 3:
            buscarAlquiler();
			system("pause");
			break;
        case 4:
            devolucionAlquiler();
			system("pause");
			break;
        case 5:
            adm.menu();
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
