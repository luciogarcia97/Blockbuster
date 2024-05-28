#include <iostream>
#include "PersonalManager.h"
#include "PersonalArchivo.h"
#include "Personal.h"


using namespace std;

Personal PersonalManager::crearPersonal()
{
    Personal obj;
    obj.cargarPersonal();




    return obj;
}


void PersonalManager::agregarPersonal()
{

   if(_personalArchivo.guardar(crearPersonal())){
      cout << "El cliente fue guardado con exito!" << endl;
   }
   else{
      cout << "No se pudo guardar el cliente!" << endl;
   }
}
void PersonalManager::listarPersonal(){
  int cantidad = _personalArchivo.getCantidadRegistrosPersonal();

    for (int i =0; i<cantidad; i++){
        Personal reg = _personalArchivo.leer(i);

        cout << "Legajo del Personal : " << reg.getLegajoPersonal() << endl;
        cout << "Contrasena del Personal : " << reg.getContrasena() << endl;
        cout << "Cargo : " << reg.getCargo() << endl;
        cout << "Sueldo : " << reg.getSueldo() << endl;
        cout << "Comision : " << reg.getComision() << endl;
        cout << "------------------------------" << endl;
        cout << "Nombre Personal: " << reg.getNombre() << endl;
        cout << "Apellido Personal: " << reg.getApellido() << endl;
        cout << "Mail del Personal :" << reg.getMail() << endl;
        cout << "Celular del Personal :" << reg.getCel() << endl;
        cout << "Dni del Personal :" << reg.getDni() << endl;
    }
    int _legajo_personal;
    char _contrasena [30];
    char _cargo [30];
    float _sueldo;
    float _comision;
}

void PersonalManager::menu(){
    int opcion;
    system("cls");
    do {
        system("cls");
        cout << "-------MENU PERSONAL-------" << endl;
        cout << "1- AGREGAR PERSONAL" << endl;
        cout << "2- LISTAR PERSONAL" << endl;
        cout << "----------------------------" << endl;
        cout << "0- SALIR" << endl;
        cout << "INGRESE OPCION :" << endl;
        cin >> opcion;

        switch (opcion){
        case 1:
        agregarPersonal();
        break;
        case 2:
        listarPersonal();
        break;
        }
    system("pause");

    }while(opcion!= 0);

}

