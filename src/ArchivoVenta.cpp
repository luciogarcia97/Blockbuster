#include "ArchivoVenta.h"

ArchivoVenta::ArchivoVenta(std::string nombre){
    setNombre(nombre);
}

Venta ArchivoVenta::leerRegistro(int posicion){
    Venta reg;
    FILE* p;
    p = fopen(_nombre,"rb");
    if (p==nullptr) return reg;
    fseek(p, sizeof(Venta) * posicion,SEEK_SET);
    fread(&reg, sizeof (Venta), 1, p);
    fclose(p);
    return reg;
}
int ArchivoVenta::contarRegistros(){
    FILE* p;
    p = fopen(_nombre,"rb");
    if (p==nullptr) return -1;
    fseek(p, 0, SEEK_END);
    int tamanio = ftell(p);
    int valor = (tamanio/sizeof(Venta));
    fclose(p);
    return valor;
}
int ArchivoVenta::agregarRegistro(Venta obj){
    FILE* p;
    p = fopen(_nombre,"ab");
    if(p==nullptr) return -1;
    int valor = fwrite(&obj, sizeof(Venta), 1, p);
    fclose(p);
    return valor;
}
int ArchivoVenta::agregarRegistro(Venta obj, int posicion){
   FILE *p;
   p = fopen(_nombre, "rb+");
   if(p == nullptr) return -1;
   fseek(p, sizeof(Venta) * posicion, SEEK_SET);
   int valor = fwrite(&obj, sizeof (Venta), 1, p);
   fclose(p);
   return valor;
}

int ArchivoVenta::buscarRegistro(int id){
    FILE* p;
    Venta reg;
    int posicion = 0;
    p = fopen(_nombre,"rb");
    if (p == nullptr) return -2;

    while (fread(&reg,sizeof (Venta), 1, p) == 1)
    {
        if (reg.getNumeroVenta() == id){
            fclose(p);
            return posicion;
        }
        posicion++;
    }
    fclose(p);
    return -1;
}

int ArchivoVenta::getNuevoId(){
    int cantidad = contarRegistros();
    if(cantidad>0){
        return leerRegistro(cantidad-1).getNumeroVenta()+1;
    }
    return 1;
}

void ArchivoVenta::leerTodos(Venta registros[], int cantidad){
    FILE *pFile;

    pFile = fopen("productos.dat", "rb");

    if(pFile == nullptr){
        return;
    }

    fread(registros, sizeof(Venta), cantidad, pFile);

    fclose(pFile);
}

void ArchivoVenta::setNombre(std::string nombre){
    strcpy(_nombre,stringToConstChar(nombre,30));
    setCaracteres(_nombre);
}