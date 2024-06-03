#pragma once
#include "Fecha.h"
#include "funciones.h"

class Alquiler
{
    public:
        Alquiler(int legajo = 0, int cliente = 0, int forma_pago = 0, int numero_alquiler = 0, Fecha fecha_alquiler = Fecha(), Fecha fecha_obligada_devolucion = Fecha(), Fecha fecha_entrega = Fecha(), bool estado = false);

        int getNumeroAlquiler();
        Fecha getFechaAlquiler();
        Fecha getFechaObligadaDevolucion();
        Fecha getFechaEntrega();
        int getNumeroCliente();
        int getLegajo();
        int getFormaPago();
        bool getEstadoAlquiler();

        void setNumeroAlquiler(int numero);
        void setFechaAlquiler(Fecha fecha);
        void setFechaObligadaDevolucion(Fecha fecha);
        void setFechaEntrega(Fecha fecha);
        void setNumeroCliente(int cliente);
        void setLegajo(int legajo);
        void setFormaPago(int forma);
        void setEstadoAlquiler(bool estado);

        // TO DO: deberiamos hacer un metodo que finalice el alquiler.

    protected:

    private:
        int _numero_alquiler;
        Fecha _fecha_alquiler;
        Fecha _fecha_obligada_devolucion;
        Fecha _fecha_entrega;
        int _numero_cliente;
        int _legajo_personal;
        int _forma_pago;
        bool _estado_alquiler;
};

