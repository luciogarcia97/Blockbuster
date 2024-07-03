#include "ArchivoVHS.h"

bool ArchivoVHS::guardar(VHS art){
	bool result;
	FILE *pFile;
	pFile = fopen("VHS.dat", "ab");
	if(pFile == nullptr){
		return false;
	}
	result = fwrite(&art, sizeof (VHS), 1, pFile);
	fclose(pFile);
	return result;
}

int ArchivoVHS::buscarXnumero(int numeroArt){
	FILE* pFile;
	VHS obj;
	int pos=0;
	pFile = fopen("VHS.dat", "rb");
	if(pFile==nullptr){ return -1;}
	while(fread(&obj, sizeof(VHS), 1, pFile)==1){
		if(obj.getNumero() == numeroArt){
			fclose(pFile);
			return pos;
		}
		pos++;
	}
	fclose(pFile);
	return -2;
}

int ArchivoVHS::getNumeroArticuloV(){
	int cantidad_vhs = contarRegistro();
	
	if (cantidad_vhs > 0)
	{
		return leerRegistro(cantidad_vhs-1).getNumeroArtV()+1;
	}

	return 1;
}

int ArchivoVHS::buscarXtitulo(){
	FILE *pFile;
	VHS obj;
	int pos=0;
	string titulo;
	char set[30];
	cout<<"Ingrese el titulo a buscar: "<<endl;
	getline(cin, titulo);
	if(titulo.size() <= 30){
		strcpy(set, titulo.c_str());
	}
	setCaracteres(set);
	pFile = fopen("VHS.dat", "rb");
	if(pFile==nullptr){ return -1;}
	while(fread(&obj, sizeof obj, 1, pFile)==1){
		if(strcmp(stringToConstChar(obj.getTituloP(), 30), set) == 0){
			fclose(pFile);
			return pos;
		}
		pos++;
	}
	fclose(pFile);
	return -2;
}

int ArchivoVHS::buscarXgenero(int genero){
	FILE *pFile;
	VHS reg;
	int pos = 0;

   pFile = fopen("VHS.dat","rb");

    if (pFile == nullptr){
        return -2;
    }
    while (fread(&reg, sizeof(genero),1,pFile))
    {
        if (reg.getGeneroP()== genero){
            fclose(pFile);
            return pos;
        }
        pos++;
    }

    fclose(pFile);
    return -1;
}

VHS ArchivoVHS::leerRegistro(int index){
	VHS reg;
	FILE *pFile;
	pFile = fopen("VHS.dat", "rb");
	if(pFile == nullptr){
		return reg;
	}
	fseek(pFile, index * sizeof(VHS), SEEK_SET);
	fread(&reg, sizeof(VHS), 1, pFile);
	fclose(pFile);
	return reg;
}

bool ArchivoVHS::listarRegistros(){
	FILE *p;
	VHS obj;
	p = fopen("VHS.dat", "rb");
	if(p==NULL) return false;
	while(fread(&obj, sizeof obj, 1, p)==1){
		obj.mostrar();
		cout<<endl;
	}
	fclose(p);
	return true;
}

int ArchivoVHS::contarRegistro(){
	FILE *pFile;
	int tam;
	
	pFile = fopen("VHS.dat", "rb");
	if(pFile==nullptr){
		return 0;
	}
	fseek(pFile, 0, SEEK_END);
	tam = ftell(pFile) / sizeof (VHS);
	
	fclose(pFile);
	return tam;
}

bool ArchivoVHS::grabar(int index, VHS art){
	bool result;
	FILE *pFile;
	pFile = fopen("VHS.dat", "rb+");
	if(pFile == nullptr){
		return false;
	}
	fseek(pFile, sizeof (VHS) * index, SEEK_SET);
	result = fwrite(&art, sizeof (VHS), 1, pFile);
	fclose(pFile);
	return result;
}
