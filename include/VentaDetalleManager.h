#pragma once
#include "VentaDetalle.h"
#include "VentaDetalleArchivo.h"
#include "VentaManager.h"
#include "ArticulosManager.h"

class VentaDetalleManager
{
    public:
        void menu();
        void cargarDetalleVenta(int numeroVenta);
        bool validarExistenciaId(int numeroVenta);
    private:
        void agregarVentaDetalle(Detalleventa obj);
        void listarVentaDetalle();
        void listarVentaDetalleById();
        void mostrarVentaDetalle(Detalleventa reg);
        Detalleventa* buscarVentaDetalle(int id);
        ArchivoDetalleVenta _archivoVentaDetalle = ArchivoDetalleVenta("ventaDetalle.dat");
};

