#include "ArchivoVHS.h"
#include "VHS.h"
#include "Articulo.h"
#include <iostream>
#include "funciones.h"
using namespace std;

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
	FILE *pFile;
	VHS obj;
	int pos=0;
	fopen("VHS.dat", "rb");
	if(pFile==nullptr){ return -1;}
	while(fread(&obj, sizeof obj, 1, pFile)==1){
		if(obj.getNumero() == numeroArt){
			fclose(pFile);
			return pos;
		}
		pos++;
	}
	fclose(pFile);
	return -2;
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
	fopen("VHS.dat", "rb");
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
int ArchivoVHS::buscarXgenero(){
	FILE *pFile;
	VHS obj;
	int pos=0;
	string genero;
	char set[30];
	cout<<"Ingrese el titulo a buscar: "<<endl;
	getline(cin, genero);
	if(genero.size() <= 30){
		strcpy(set, genero.c_str());
	}
	setCaracteres(set);
	fopen("VHS.dat", "rb");
	if(pFile==nullptr){ return -1;}
	while(fread(&obj, sizeof obj, 1, pFile)==1){
		if(strcmp(stringToConstChar(obj.getGeneroP(), 30), set) == 0){
			fclose(pFile);
			return pos;
		}
		pos++;
	}
	fclose(pFile);
	return -2;
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
	fopen("VHS.dat", "rb");
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
