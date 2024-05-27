#include "ArchivoAlquiler.h"

ArchivoAlquiler::ArchivoAlquiler(const char* nombre)
{
    strcpy(_nombre, nombre);
}

Alquiler ArchivoAlquiler::leerRegistro(int posicion){
    Alquiler reg;
    reg.setNumeroAlquiler(-1);
    FILE* p;
    p = fopen(_nombre,"rb");
    if(p == nullptr) return reg;
    fseek(p, sizeof (Alquiler) * posicion, 0);
    fread(&reg, sizeof (Alquiler), 1, p);
    fclose(p);
    return reg;
}
int ArchivoAlquiler::contarRegistros(){
    FILE* p;
    p = fopen(_nombre,"rb");
    if (p==nullptr) return -1;
    fseek(p, 0, 2);
    int tamanio = ftell(p);
    fclose(p);
    int valor = (tamanio/sizeof(Alquiler));
    return valor;
}
int ArchivoAlquiler::agregarRegistroAlquiler(){
    Alquiler reg;
    FILE* p;
    p = fopen(_nombre,"ab");
    if(p==NULL) return -1;
    reg.cargarAlquiler();
    int valor = fwrite(&reg, sizeof(reg), 1, p);
    fclose(p);
    return valor;
}
int ArchivoAlquiler::agregarRegistroAqluier(Alquiler obj){
    Alquiler reg = obj;
    FILE* p;
    p = fopen(_nombre,"ab");
    if(p==NULL) return -1;
    int valor = fwrite(&reg, sizeof(reg), 1, p);
    fclose(p);
    return valor;
}

bool ArchivoAlquiler::listarArchivo(){
    Alquiler reg;
    FILE *p;
    p = fopen(_nombre,"rb");
    if(p == NULL) return false;
    if (!(fread(&reg, sizeof(reg), 1, p))) return false;
    headerAlquiler();
    while(fread(&reg, sizeof(reg), 1, p) == 1)
    {
        reg.mostrarAlquiler();
        cout << endl;
    }
    fclose(p);
    return true;
}
