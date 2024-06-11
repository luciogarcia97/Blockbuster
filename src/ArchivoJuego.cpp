#include "ArchivoJuego.h"
#include "Juego.h"
#include "Articulo.h"
#include "funciones.h"
#include <cstring>
#include <iostream>
using namespace std;

bool ArchivoJuego::guardar(Juego art){
	bool result;
	FILE *pFile;
	pFile = fopen("Juegos.dat", "ab");
	if(pFile == nullptr){
		return false;
	}
	result = fwrite(&art, sizeof (Juego), 1, pFile);
	fclose(pFile);
	return result;
}
int ArchivoJuego::buscarXnumero(int numeroArt){
	FILE *pFile;
	Juego obj;
	int pos=0;
	fopen("Juegos.dat", "rb");
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
Juego ArchivoJuego::leerRegistro(int index){
	Juego reg;
	FILE *pFile;
	pFile = fopen("Juegos.dat", "rb");
	if(pFile == nullptr){
		return reg;
	}
	fseek(pFile, index * sizeof(Juego), SEEK_SET);
	fread(&reg, sizeof(Juego), 1, pFile);
	fclose(pFile);
	return reg;
}
bool ArchivoJuego::listarRegistros(){
	FILE *p;
	Juego obj;
	fopen("Juegos.dat", "rb");
	if(p==NULL) return false;
	while(fread(&obj, sizeof obj, 1, p)==1){
		obj.mostrar();
		cout<<endl;
	}
	fclose(p);
	return true;
}
int ArchivoJuego::contarRegistro(){
	FILE *pFile;
	int tam;
	
	pFile = fopen("Juegos.dat", "rb");
	if(pFile==nullptr){
		return 0;
	}
	fseek(pFile, 0, SEEK_END);
	tam = ftell(pFile) / sizeof (Juego);
	
	fclose(pFile);
	return tam;
}
bool ArchivoJuego::grabar(int index, Juego art){
	bool result;
	FILE *pFile;
	pFile = fopen("Juegos.dat", "rb+");
	if(pFile == nullptr){
		return false;
	}
	fseek(pFile, sizeof (Juego) * index, SEEK_SET);
	result = fwrite(&art, sizeof (Juego), 1, pFile);
	fclose(pFile);
	return result;
}
int ArchivoJuego::buscarXtitulo(){
	FILE *pFile;
	Juego obj;
	int pos=0;
	string titulo;
	char set[30];
	cout<<"Ingrese el titulo a buscar: "<<endl;
	getline(cin, titulo);
	if(titulo.size() <= 30){
		strcpy(set, titulo.c_str());
	}
	setCaracteres(set);
	fopen("Juegos.dat", "rb");
	if(pFile==nullptr){ return -1;}
	while(fread(&obj, sizeof obj, 1, pFile)==1){
		if(strcmp(stringToConstChar(obj.getTituloJ(), 30), set) == 0){
			fclose(pFile);
			return pos;
		}
		pos++;
	}
	fclose(pFile);
	return -2;
}
int ArchivoJuego::buscarXgenero(){
	FILE *pFile;
	Juego obj;
	int pos=0;
	string genero;
	char set[30];
	cout<<"Ingrese el titulo a buscar: "<<endl;
	getline(cin, genero);
	if(genero.size() <= 30){
		strcpy(set, genero.c_str());
	}
	setCaracteres(set);
	fopen("Juegos.dat", "rb");
	if(pFile==nullptr){ return -1;}
	while(fread(&obj, sizeof obj, 1, pFile)==1){
		if(strcmp(stringToConstChar(obj.getGeneroJ(), 30), set) == 0){
			fclose(pFile);
			return pos;
		}
		pos++;
	}
	fclose(pFile);
	return -2;
}
