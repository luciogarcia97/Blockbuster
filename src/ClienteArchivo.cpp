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
bool ClienteArchivo::guardar (int index, Cliente registro){
    bool result;

    FILE *pFile;
    pFile = fopen("Cliente.dat","rb+");

    if(pFile == nullptr){
        return false;
    }
    fseek(pFile, sizeof(Cliente)*index, SEEK_SET);

    result = fwrite(&registro,sizeof (Cliente),1,pFile);

    fclose(pFile);

    return result;

}

Cliente ClienteArchivo::leer(int index){
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

int ClienteArchivo::buscarCliente(int id)
{
    Cliente reg;
    FILE *pFile;
    int pos = 0;

    pFile = fopen("Cliente.dat","rb");

    if (pFile == nullptr){
        return -1;
    }
    while (fread(&reg, sizeof(Cliente),1,pFile))
    {
        if (reg.getIdCliente()== id){
            fclose(pFile);
            return pos;
        }
        pos++;
    }

    fclose(pFile);
    return -1;
}
int ClienteArchivo::getNuevoID()
{
    int cantidad = getCantidadRegistrosClientes();

    if (cantidad >0){
        return leer(cantidad-1).getIdCliente()+1;

    }
    else{
        return 1;
    }
}
