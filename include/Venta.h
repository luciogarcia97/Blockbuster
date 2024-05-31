#pragma once
#include "Fecha.h"

class Venta
{
    public:
        Venta(int venta = 0, Fecha fecha = Fecha(), int cliente = 0, int legajo = 0, int pago = 0);

        int getNumeroVenta(){return _numero_venta;}
        Fecha getFechaVenta(){return _fecha_venta;}
        int getNumeroCliente(){return _numero_cliente;}
        int getLegajo(){return _legajo_personal;}
        int getFormaPago(){return _forma_pago;}

        void setNumeroVenta(int numero){_numero_venta = numero;}
        void setFechaCompra(Fecha fecha){_fecha_venta = fecha;}
        void setNumeroCliente(int cliente){_numero_cliente = cliente;}
        void setLegajo(int legajo){_legajo_personal = legajo;}
        void setFormaPago(int forma){_forma_pago = forma;}

    private:
        int _numero_venta;
        Fecha _fecha_venta;
        int _numero_cliente;
        int _legajo_personal;
        int _forma_pago;
};

