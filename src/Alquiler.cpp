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

