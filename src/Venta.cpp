#include "Venta.h"

Venta::Venta(){
    _numero_venta = -1;
    _fecha_venta = Fecha();
    _numero_cliente = 0;
    _legajo_personal = 0;
    _forma_pago = 0;
}
Venta::Venta(int venta, Fecha fecha, int cliente, int legajo, int pago){
    setNumeroVenta(venta);
    setFechaCompra(fecha);
    setNumeroCliente(cliente);
    setLegajo(legajo);
    setFormaPago(pago);
}

int Venta::getNumeroVenta(){return _numero_venta;}
Fecha Venta::getFechaVenta(){return _fecha_venta;}
int Venta::getNumeroCliente(){return _numero_cliente;}
int Venta::getLegajo(){return _legajo_personal;}
int Venta::getFormaPago(){return _forma_pago;}

void Venta::setNumeroVenta(int numero){_numero_venta = numero;}
void Venta::setFechaCompra(Fecha fecha){_fecha_venta = fecha;}
void Venta::setNumeroCliente(int cliente){_numero_cliente = cliente;}
void Venta::setLegajo(int legajo){_legajo_personal = legajo;}
void Venta::setFormaPago(int forma){_forma_pago = forma;}