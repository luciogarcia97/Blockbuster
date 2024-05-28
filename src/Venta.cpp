#include "Venta.h"

Venta::Venta(int venta, Fecha fecha, int cliente, int legajo, int pago){
    _numero_venta = venta;
    _fecha_venta = fecha;
    _numero_cliente = cliente;
    _legajo_personal = legajo;
    _forma_pago = pago;
}

void Venta::cargarVenta(){
    int numero_cliente;
    int legajo_personal;
    int forma_pago;
    int numero_venta;
    Fecha timestamp;

    cout << "Carga de datos para Ventas" << endl;
    cout << "--------------------------" << endl << endl;
    //Carga numero de venta con validacion
    cout << "1) Ingrese el numero de venta: ";
    numero_venta = validarCinInt();
    setNumeroCliente(numero_venta);
    //TO DO: Se podria contar +1 al ultimo registro para evitar ingresar el numero de la venta (En alquiler tambien)

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

    timestamp = Fecha();
    setFechaCompra(timestamp);

    system("cls");
    cout << "Se registro la venta correctamente!" << endl;
}
void Venta::mostrarVenta(){
    std::cout << _numero_venta << "\t\t" << _numero_cliente << "\t\t";
    _fecha_venta.MostrarFecha();
    std::cout << "\t" << _legajo_personal << "\t\t" << _forma_pago << std::endl;
}
