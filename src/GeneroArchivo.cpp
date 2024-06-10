#include "GeneroArchivo.h"
using namespace std;


Genero GeneroArchivo::leerRegistro(int posicion){
    Genero reg;
    FILE *pFile;

    pFile = fopen ("genero.dat","rb");

    if (pFile == nullptr){
        return reg;
    }

    fseek(pFile,posicion * sizeof(Genero),SEEK_SET);

    fread (&reg, sizeof(Genero),1,pFile);

    fclose(pFile);

    return reg;

}
int GeneroArchivo::contarRegistros(){
FILE *pFile;
    int tam;

    pFile = fopen("genero.dat","rb");

    if(pFile == nullptr){
        return -1;
    }
    fseek(pFile, 0, SEEK_END);

    tam = ftell(pFile) / sizeof (Genero);
    fclose(pFile);

    return tam;
}

int GeneroArchivo::agregarRegistro(Genero obj){
    int result;
    FILE *pFile;
    pFile = fopen("genero.dat","ab");
    if(pFile == nullptr){
        return -1;
    }
    result = fwrite(&obj,sizeof (Genero),1,pFile);
    fclose(pFile);
    return result;
}
int GeneroArchivo::agregarRegistro(Genero obj, int posicion){
 int result;

    FILE *pFile;
    pFile = fopen("genero.dat","rb+");

    if(pFile == nullptr){
        return -1;
    }
    fseek(pFile, sizeof(Genero)*posicion, SEEK_SET);

    result = fwrite(&obj,sizeof (Genero),1,pFile);

    fclose(pFile);

    return result;

}
int GeneroArchivo::buscarRegistro(int id){
    Genero reg;
    FILE *pFile;
    int pos = 0;

    pFile = fopen("genero.dat","rb");

    if (pFile == nullptr){
        return -2;
    }
    while (fread(&reg, sizeof(Genero),1,pFile))
    {
        if (reg.getNumero()== id){
            fclose(pFile);
            return pos;
        }
        pos++;
    }

    fclose(pFile);
    return -1;
}
int GeneroArchivo::getNuevoId(){
 int cantidad =contarRegistros();

    if (cantidad >0){
        return leerRegistro(cantidad-1).getNumero()+1;

    }
    return 1;
}


