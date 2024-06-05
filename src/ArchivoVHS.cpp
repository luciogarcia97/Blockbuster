#include "ArchivoVHS.h"
#include "VHS.h"
#include "Articulo.h"
#include <iostream>
using namespace std;

ArchivoVHS::ArchivoVHS() {

}
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
	FILE *p;
	VHS obj;
	int pos=0;
	p = fopen("VHS.dat", "rb");
	if(p==nullptr) return -1;
	while(fread(&obj, sizeof obj, 1, p)==1){
		if(obj.getNumero() == numeroArt){
			fclose(p);
			return pos;
		}
		pos++;
	}
	fclose(p);
	return -2;
}
VHS ArchivoVHS::leerRegistro(int pos){
	VHS reg;
	FILE *pFile;
	pFile = fopen("VHS.dat", "rb");
	if(pFile == nullptr){
		return reg;
	}
	fseek(pFile, pos * sizeof (VHS), SEEK_SET);
	fread(&reg, sizeof(VHS), 1, pFile);
	fclose(pFile);
	return reg;
}
bool ArchivoVHS::listarRegistros(){
	FILE *p;
	VHS obj;
	p = fopen("VHS.dat", "rb");
	if(p==nullptr) return false;
	while(fread(&obj, sizeof obj, 1, p)==1){
		obj.mostrar();
		cout<<endl;
	}
	fclose(p);
	return true;
}
