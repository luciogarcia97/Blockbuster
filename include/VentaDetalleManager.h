#pragma once
#include "VentaDetalle.h"
#include "VentaDetalleArchivo.h"
#include "ArchivoVHS.h"
#include "ArchivoJuego.h"
#include "VHS.h"
#include "Juego.h"

class VentaDetalleManager
{
    public:
        void menu();
        void cargarDetalleVenta(int numeroVenta);
    private:
        void agregarVentaDetalle(Detalleventa obj);
        void listarVentaDetalle();
        void listarVentaDetalleById();
        void mostrarVentaDetalle(Detalleventa reg);
        Detalleventa* buscarVentaDetalle(int id);
        ArchivoDetalleVenta _archivoVentaDetalle = ArchivoDetalleVenta("ventaDetalle.dat");
};

