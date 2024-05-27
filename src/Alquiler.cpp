#include "Alquiler.h"


Alquiler::Alquiler(int legajo, int cliente, int forma_pago, int numero_alquiler, Fecha fecha_alquiler, Fecha fecha_obligada_devolucion, Fecha fecha_entrega, bool estado){
    _numero_alquiler = numero_alquiler;
    _fecha_alquiler = fecha_alquiler;
    _fecha_obligada_devolucion = fecha_obligada_devolucion;
    _fecha_entrega = fecha_entrega;
    _numero_cliente = cliente;
    _legajo_personal = legajo;
    _forma_pago = forma_pago;
    _estado_alquiler = estado;
}

int Alquiler::getNumeroAlquiler(){return _numero_alquiler;}
Fecha Alquiler::getFechaAlquiler(){return _fecha_alquiler;}
Fecha Alquiler::getFechaObligadaDevolucion(){return _fecha_obligada_devolucion;}
Fecha Alquiler::getFechaEntrega(){return _fecha_entrega;}
int Alquiler::getNumeroCliente(){return _numero_cliente;}
int Alquiler::getLegajo(){return _legajo_personal;}
int Alquiler::getFormaPago(){return _forma_pago;}
bool Alquiler::getEstadoAlquiler(){return _estado_alquiler;}

void Alquiler::setNumeroAlquiler(int numero){_numero_alquiler = numero;}
void Alquiler::setFechaAlquiler(Fecha fecha){_fecha_alquiler = fecha;}
void Alquiler::setFechaObligadaDevolucion(Fecha fecha){_fecha_obligada_devolucion = fecha;}
void Alquiler::setFechaEntrega(Fecha fecha){_fecha_entrega = fecha;}
void Alquiler::setNumeroCliente(int cliente){_numero_cliente = cliente;}
void Alquiler::setLegajo(int legajo){_legajo_personal = legajo;}
void Alquiler::setFormaPago(int forma){_forma_pago = forma;}
void Alquiler::setEstadoAlquiler(bool estado){_estado_alquiler = estado;}

void Alquiler::cargarAlquiler(){
    int numero_alquiler;
    Fecha fecha_alquiler;
    Fecha fecha_obligada_devolucion;
    int numero_cliente;
    int legajo_personal;
    int forma_pago;
    bool estado_alquiler;

    cout << "Carga de datos para Ventas" << endl;
    cout << "--------------------------" << endl << endl;
    //Carga numero de venta con validacion
    cout << "1) Ingrese el numero del alquiler: ";
    numero_alquiler = validarCinInt();
    setNumeroCliente(numero_alquiler);

    //Carga numero de cliente con validacion
    cout << "2) Ingrese el numero de cliente: ";
    numero_cliente = validarCinInt();
    setNumeroCliente(numero_cliente);

    //Carga numero de legajo con validacion
    cout << "3) Ingrese el legajo del vendedor: ";
    legajo_personal = validarCinInt();
    setNumeroCliente(legajo_personal);
    //TO DO: Esto se podria hacer en segundo plano si hacemos un sistema de logueo

    //Carga forma de pago de cliente con validacion
    cout << "4) Ingrese el metodo de pago: ";
    forma_pago = validarCinInt();
    setNumeroCliente(forma_pago);
    //TO DO: Hacemos un listado de metodos de pago?

    //Carga la fecha de compra del momento en el cual se ejecuto la carga.

    fecha_alquiler = Fecha();
    setFechaAlquiler(fecha_alquiler);

    estado_alquiler = true;
    setEstadoAlquiler(estado_alquiler);

    //Carga de fecha de devolucion, se puede mejorar agregando un metodo en la clase fecha
    int dia, mes, anio;
    cout << "5)Detalle la fecha de devolucion obligatoria: " << endl;
    cout << "Dia: ";
    dia = validarCinInt();
    _fecha_obligada_devolucion.setDia(dia);
    cout << "Mes: ";
    mes = validarCinInt();
    _fecha_obligada_devolucion.setDia(mes);
    cout << "Anio: ";
    anio = validarCinInt();
    _fecha_obligada_devolucion.setDia(anio);


    system("cls");
    cout << "Se registro el alquiler correctamente!" << endl;
}
void Alquiler::mostrarAlquiler(){
    cout << "Alquiler" << "\tCliente" << "\t\tFecha Alquiler" << "\tVendedor" << "\tForma de pago" << "\tFecha de Devolucion" << "\t\tFecha de Entrega" << "\t\tEstado" << endl;

    cout << _numero_alquiler << "\t\t" << _numero_cliente << "\t\t";
    _fecha_alquiler.MostrarFecha();
    cout << "\t" << _legajo_personal << "\t\t" << _forma_pago << "\t\t";
    _fecha_obligada_devolucion.MostrarFecha();
    cout << "\t\t\t";
    _fecha_entrega.MostrarFecha();
    cout << "\t\t\t" << (_estado_alquiler? "En Curso":"Finalizado") << endl;
}

