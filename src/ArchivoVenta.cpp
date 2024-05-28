#include "ArchivoVenta.h"

ArchivoVenta::ArchivoVenta(std::string nombre){
    setNombre(nombre);
}

Venta ArchivoVenta::leerRegistro(int posicion){
    Venta reg;
    reg.setNumeroVenta(-1);
    FILE* p;
    p = fopen(_nombre,"rb");
    if (p==nullptr) return reg;
    fseek(p, sizeof(Venta) * posicion,0);
    fread(&reg, sizeof (reg), 1, p);
    fclose(p);
    return reg;
}
int ArchivoVenta::contarRegistros(){
    FILE* p;
    p = fopen(_nombre,"rb");
    if (p==nullptr) return -1;
    fseek(p, 0, 2);
    int tamanio = ftell(p);
    fclose(p);
    int valor = (tamanio/sizeof(Venta));
    return valor;
}
int ArchivoVenta::agregarRegistroVenta(){
    Venta reg;
    FILE* p;
    p = fopen(_nombre,"ab");
    if(p==NULL) return -1;
    reg.cargarVenta();
    int valor = fwrite(&reg, sizeof(reg), 1, p);
    fclose(p);
    return valor;
}

int ArchivoVenta::agregarRegistroVenta(Venta obj){
    Venta reg = obj;
    FILE* p;
    p = fopen(_nombre,"ab");
    if(p==NULL) return -1;
    int valor = fwrite(&reg, sizeof(reg), 1, p);
    fclose(p);
    return valor;
}

bool ArchivoVenta::listarArchivo(){
    Venta reg;
    FILE *p;
    p = fopen(_nombre,"rb");
    if(p == NULL) return false;
    if (!(fread(&reg, sizeof(reg), 1, p))) return false;
    headerVentas();
    while(fread(&reg, sizeof(reg), 1, p) == 1)
    {
        reg.mostrarVenta();
        cout << endl;
    }
    fclose(p);
    return true;
}

void ArchivoVenta::setNombre(std::string nombre){
    strcpy(_nombre,stringToConstChar(nombre,30));
}