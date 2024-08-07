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
	pFile = fopen("Juegos.dat", "rb");
	if(pFile==nullptr){ return -1;}
	while(fread(&obj, sizeof obj, 1, pFile)==1){
		if(obj.getNumeroArtJ() == numeroArt){
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
	p = fopen("Juegos.dat", "rb");
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
	pFile = fopen("Juegos.dat", "rb");
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
int ArchivoJuego::buscarXgenero(int genero){
	FILE *pFile;
	Juego reg;
	int pos = 0;

   pFile = fopen("Juegos.dat","rb");

    if (pFile == nullptr){
        return -2;
    }
    while (fread(&reg, sizeof(genero),1,pFile))
    {
        if (reg.getGeneroJ()== genero){
            fclose(pFile);
            return pos;
        }
        pos++;
    }

    fclose(pFile);
    return -1;
}

int ArchivoJuego::getNumeroArticuloJ(){
	int cantidad_juego = contarRegistro();
	
	if (cantidad_juego > 0)
	{
		return leerRegistro(cantidad_juego-1).getNumeroArtJ()+1;
	}

	return 1;
}
