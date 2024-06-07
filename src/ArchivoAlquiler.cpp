#include "ArchivoAlquiler.h"

ArchivoAlquiler::ArchivoAlquiler(std::string nombre)
{
    setNombre(nombre);
}

Alquiler ArchivoAlquiler::leerRegistro(int posicion){
    Alquiler reg;
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

int ArchivoAlquiler::agregarRegistroAlquiler(Alquiler obj){
    Alquiler reg = obj;
    FILE* p;
    p = fopen(_nombre,"ab");
    if(p==nullptr) return -1;
    int valor = fwrite(&reg, sizeof(Alquiler), 1, p);
    fclose(p);
    return valor;
}

int ArchivoAlquiler::getNuevoId(){
    int cantidad = contarRegistros();
    if (cantidad > 0)
    {
        return leerRegistro(cantidad-1).getNumeroAlquiler()+1;
    }
    return 1;
}

int ArchivoAlquiler::buscarRegistro(int id){
    FILE* p;
    Alquiler reg;
    int posicion = 0;
    p = fopen(_nombre,"rb");
    if(p == nullptr) return -2;

    while (fread(&reg, sizeof(Alquiler), 1, p) == 1)
    {
        if (reg.getNumeroAlquiler() == id)
        {
            fclose(p);
            return posicion;
        }
        posicion ++;
    }
    fclose(p);
    return -1;
}

bool ArchivoAlquiler::guardarRegistro(int posicion, Alquiler reg){
    bool result;
    FILE *pFile;
    pFile = fopen(_nombre,"rb+");
    if(pFile == nullptr){
        return false;
    }
    fseek(pFile, sizeof(Alquiler)*posicion, SEEK_SET);
    result = fwrite(&reg,sizeof (Alquiler),1,pFile);
    fclose(pFile);
    return result;
}

void ArchivoAlquiler::setNombre(std::string nombre){
    strcpy(_nombre,stringToConstChar(nombre,30));
}