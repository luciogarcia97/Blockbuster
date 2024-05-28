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
Personal PersonalArchivo::leer(int index){
    bool result;
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
        return 0;
    }
    fseek(pFile, 0, SEEK_END);

    tam = ftell(pFile) / sizeof (Personal);
    fclose(pFile);

    return tam;
}
