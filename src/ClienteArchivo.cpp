#include "ClienteArchivo.h"
#include "Cliente.h"


/**
   ab -- agregar
   wb -- borra todo y te permite agregar
   rb -- lee

   rb+ -- lee y modifica (no agrega)
   ab+ -- agrega y lee
*/

bool ClienteArchivo::guardar (Cliente reg){
    bool result;

    FILE *pFile;
    pFile = fopen("Cliente.dat","ab");

    if(pFile == nullptr){
        return false;
    }
    result = fwrite(&reg,sizeof (Cliente),1,pFile);

    fclose(pFile);

    return result;

}
Cliente ClienteArchivo::leer(int index){
    bool result;
    Cliente reg;
    FILE *pFile;

    pFile = fopen ("Cliente.dat","rb");

    if (pFile == nullptr){
        return reg;
    }

    fseek(pFile,index * sizeof(Cliente),SEEK_SET);

    fread (&reg, sizeof(Cliente),1,pFile);

    fclose(pFile);

    return reg;
}
int ClienteArchivo::getCantidadRegistrosClientes (){
    FILE *pFile;
    int tam;

    pFile = fopen("Cliente.dat","rb");

    if(pFile == nullptr){
        return 0;
    }
    fseek(pFile, 0, SEEK_END);

    tam = ftell(pFile) / sizeof (Cliente);
    fclose(pFile);

    return tam;
}
