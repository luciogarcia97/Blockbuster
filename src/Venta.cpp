#include "Venta.h"

Venta::Venta(int venta, Fecha fecha, int cliente, int legajo, int pago){
    _numero_venta = venta;
    _fecha_venta = fecha;
    _numero_cliente = cliente;
    _legajo_personal = legajo;
    _forma_pago = pago;
}
