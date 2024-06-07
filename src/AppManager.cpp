#include <iostream>
#include "AppManager.h"

using namespace std;


Personal AppManager::Logueo(){
    int legajo;
    string pass;
    cout << "------ BIENVENIDO A BLOCKBUSTER ------- " << endl;
    cout << "Numero de Usuario: ";
    legajo = validarCinInt();
    cout << "Ingrese su clave: ";
    cin >> pass;
    cout << "--------------------------------------- " << endl;

    PersonalManager pm;
    Personal obj;
    Personal aux = pm.buscarPersonalPorLegajo(legajo);
    if((aux.getContrasena() == pass) && (aux.getLegajoPersonal() > 0)){
        obj = aux;
        return obj;
    }

    system("cls");
    cout << "Su usuario y/o contrasena son invalidos, reintente presionando una tecla"<<endl;
    system("pause");
    system("cls");
    return obj;
}

void AppManager::menu()
{
    Personal obj;
    do
    {
        obj = Logueo();
    } while (obj.getLegajoPersonal() == 0);

    int option;
    system("cls");
    do
    {
        system("cls");
        cout << "------ MENU PRINCIPAL ------- " << endl;
        cout << "1- Menu Facturacion" << endl;
        cout << "2- Menu Persona" << endl;
        cout << "3- Menu Stock" << endl;
        cout << "4- UPDATES...." << endl;
        cout << "-----------------------------" << endl;
        cout << "0- SALIR" << endl;
        cout << "Opcion: "<< endl;
        cin >> option;

        switch(option)
        {
        case 1:
            _fm.menu();
            break;
        case 2:
            _pm.menu();
            break;
        case 3:
            break;
        case 4:
            break;
        }
    }
    while(option != 0);
}


