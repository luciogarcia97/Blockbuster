#include "ArchivoDetalleAlquiler.h"

ArchivoDetalleAlquiler::ArchivoDetalleAlquiler(std::string nombre)
{
    setNombre(nombre);
}

DetalleAlquiler ArchivoDetalleAlquiler::leerRegistro(int posicion){
    DetalleAlquiler reg;
    reg.setNumeroAlquilerDetalle(-1);
    FILE* p;
    p = fopen(_nombre,"rb");
    if(p == nullptr) return reg;
    fseek(p, sizeof (DetalleAlquiler) * posicion, 0);
    fread(&reg, sizeof (DetalleAlquiler), 1, p);
    fclose(p);
    return reg;
}

int ArchivoDetalleAlquiler::contarRegistros(){
    FILE* p;
    p = fopen(_nombre,"rb");
    if (p==nullptr) return -1;
    fseek(p, 0, 2);
    int tamanio = ftell(p);
    fclose(p);
    int valor = (tamanio/sizeof(DetalleAlquiler));
    return valor;
}

int ArchivoDetalleAlquiler::agregarRegistroAlquilerDetalle(DetalleAlquiler obj){
    DetalleAlquiler reg = obj;
    FILE* p;
    p = fopen(_nombre,"ab");
    if(p==NULL) return -1;
    int valor = fwrite(&reg, sizeof(reg), 1, p);
    fclose(p);
    return valor;
}

int ArchivoDetalleAlquiler::getNuevoId(){
    int cantidad = contarRegistros();
    if (cantidad > 0)
    {
        return leerRegistro(cantidad - 1).getNumeroAlquilerDetalle()+1;
    }
    return 1;
    
}

int ArchivoDetalleAlquiler::buscarRegistro(int id){
    FILE* p;
    DetalleAlquiler reg;
    int posicion = 0;
    p = fopen(_nombre,"rb");
    if(p == nullptr) return -1;

    while (fread(&reg, sizeof(DetalleAlquiler), 1, p) == 1)
    {
        if (reg.getNumeroAlquilerDetalle() == id)
        {
            fclose(p);
            return posicion;
        }
        posicion ++;
    }
    fclose(p);
    return 0;
}

int ArchivoDetalleAlquiler::contarRegistrosRepetidos(int id){
    int cantidad = contarRegistros();
    DetalleAlquiler obj;
    int contador = 0;
 
    for (int i = 0; i < cantidad; i++)
    {
        obj = leerRegistro(i);
        if (id == obj.getNumeroAlquilerDetalle())
        {
            contador ++;
        }
    }
    return contador;
}

void ArchivoDetalleAlquiler::setNombre(std::string nombre){
    strcpy(_nombre,stringToConstChar(nombre,30));
    setCaracteres(_nombre);
}
