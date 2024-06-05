#include "PersonalArchivo.h"
#include "Personal.h"

/**
   ab -- agregar
   wb -- borra todo y te permite agregar
   rb -- lee

   rb+ -- lee y modifica (no agrega)
   ab+ -- agrega y lee
*/

bool PersonalArchivo::guardar (Personal reg){
    bool result;

    FILE *pFile;
    pFile = fopen("Personal.dat","ab");

    if(pFile == nullptr){
        return false;
    }
    result = fwrite(&reg,sizeof (Personal),1,pFile);

    fclose(pFile);

    return result;

}
bool PersonalArchivo::guardar (int index, Personal registro){
    bool result;

    FILE *pFile;
    pFile = fopen("Personal.dat","rb+");

    if(pFile == nullptr){
        return false;
    }
    fseek(pFile, sizeof(Personal)*index, SEEK_SET);

    result = fwrite(&registro,sizeof (Personal),1,pFile);

    fclose(pFile);

    return result;

}
Personal PersonalArchivo::leer(int index){
    Personal reg;
    FILE *pFile;

    pFile = fopen ("Personal.dat","rb");

    if (pFile == nullptr){
        return reg;
    }

    fseek(pFile,index * sizeof(Personal),SEEK_SET);

    fread (&reg, sizeof(Personal),1,pFile);

    fclose(pFile);

    return reg;
}
int PersonalArchivo::getCantidadRegistrosPersonal (){
    FILE *pFile;
    int tam;

    pFile = fopen("Personal.dat","rb");

    if(pFile == nullptr){
        return -1;
    }
    fseek(pFile, 0, SEEK_END);

    tam = ftell(pFile) / sizeof (Personal);
    fclose(pFile);

    return tam;
}
int PersonalArchivo::buscarPersonal(int legajo)
{
    Personal reg;
    FILE *pFile;
    int pos = 0;

    pFile = fopen("Personal.dat","rb");

    if (pFile == nullptr){
        return -1;
    }
    while (fread(&reg, sizeof(Personal),1,pFile))
    {
        if (reg.getLegajoPersonal()== legajo){
            fclose(pFile);
            return pos;
        }
        pos++;
    }

    fclose(pFile);
    return -1;
}
int PersonalArchivo::getNuevoLegajo()
{
    int cantidad = getCantidadRegistrosPersonal();

    if (cantidad >0){
        return leer(cantidad-1).getLegajoPersonal()+1;

    }
    return 1;
}
