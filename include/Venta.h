#pragma once
#include "Fecha.h"

class Venta
{
    public:
        Venta();
        Venta(int venta, Fecha fecha, int cliente, int legajo, int pago);

        int getNumeroVenta();
        Fecha getFechaVenta();
        int getNumeroCliente();
        int getLegajo();
        int getFormaPago();

        void setNumeroVenta(int numero);
        void setFechaCompra(Fecha fecha);
        void setNumeroCliente(int cliente);
        void setLegajo(int legajo);
        void setFormaPago(int forma);

    private:
        int _numero_venta;
        Fecha _fecha_venta;
        int _numero_cliente;
        int _legajo_personal;
        int _forma_pago;
};

