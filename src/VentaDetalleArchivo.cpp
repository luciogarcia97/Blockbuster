#include "VentaDetalleArchivo.h"

ArchivoDetalleVenta::ArchivoDetalleVenta(std::string nombre)
{
    setNombre(nombre);
}

Detalleventa ArchivoDetalleVenta::leerRegistro(int posicion){
    Detalleventa reg;
    reg.setnumventa(-1);
    FILE* p;
    p = fopen(_nombre,"rb");
    if(p == nullptr) return reg;
    fseek(p, sizeof (Detalleventa) * posicion, 0);
    fread(&reg, sizeof (Detalleventa), 1, p);
    fclose(p);
    return reg;
}

int ArchivoDetalleVenta::contarRegistros(){
    FILE* p;
    p = fopen(_nombre,"rb");
    if (p==nullptr) return -1;
    fseek(p, 0, 2);
    int tamanio = ftell(p);
    fclose(p);
    int valor = (tamanio/sizeof(Detalleventa));
    return valor;
}

int ArchivoDetalleVenta::agregarRegistroVentaDetalle(Detalleventa obj){
    Detalleventa reg = obj;
    FILE* p;
    p = fopen(_nombre,"ab");
    if(p==NULL) return -1;
    int valor = fwrite(&reg, sizeof(reg), 1, p);
    fclose(p);
    return valor;
}

int ArchivoDetalleVenta::getNuevoId(){
    int cantidad = contarRegistros();
    if (cantidad > 0)
    {
        return leerRegistro(cantidad - 1).getnumventa()+1;
    }
    return 1;
    
}

int ArchivoDetalleVenta::buscarRegistro(int id){
    FILE* p;
    Detalleventa reg;
    int posicion = 0;
    p = fopen(_nombre,"rb");
    if(p == nullptr) return -1;

    while (fread(&reg, sizeof(Detalleventa), 1, p) == 1)
    {
        if (reg.getnumventa() == id)
        {
            fclose(p);
            return posicion;
        }
        posicion ++;
    }
    fclose(p);
    return 0;
}

int ArchivoDetalleVenta::contarRegistrosRepetidos(int id){
    int cantidad = contarRegistros();
    Detalleventa obj;
    int contador = 0;
 
    for (int i = 0; i < cantidad; i++)
    {
        obj = leerRegistro(i);
        if (id == obj.getnumventa())
        {
            contador ++;
        }
    }
    return contador;
}

void ArchivoDetalleVenta::setNombre(std::string nombre){
    strcpy(_nombre,stringToConstChar(nombre,30));
}
