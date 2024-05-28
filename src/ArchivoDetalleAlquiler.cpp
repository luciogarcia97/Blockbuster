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
int ArchivoDetalleAlquiler::agregarRegistroAlquilerDetalle(){
    DetalleAlquiler reg;
    FILE* p;
    p = fopen(_nombre,"ab");
    if(p==NULL) return -1;
    reg.cargarAlquilerDetalle();
    int valor = fwrite(&reg, sizeof(reg), 1, p);
    fclose(p);
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
bool ArchivoDetalleAlquiler::listarArchivo(){
    DetalleAlquiler reg;
    FILE *p;
    p = fopen(_nombre,"rb");
    if(p == NULL) return false;
    if (!(fread(&reg, sizeof(reg), 1, p))) return false;
    headerAlquilerDetalle();
    while(fread(&reg, sizeof(reg), 1, p) == 1)
    {
        reg.mostrarAlquilerDetalle();
        cout << endl;
    }
    fclose(p);
    return true;
}
void ArchivoDetalleAlquiler::setNombre(std::string nombre){
    strcpy(_nombre,stringToConstChar(nombre,30));
}