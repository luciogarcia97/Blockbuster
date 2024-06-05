#include <iostream>
#include "AppManager.h"

using namespace std;


void AppManager::menu()
{
    int option;
    system("cls");
    do
    {
        system("cls");

        cout << "------ MENU PRINCIPAL ------- " << endl;
        cout << "1- Menu Alquiler" << endl;
        cout << "2- Menu Venta" << endl;
        cout << "3- Menu Personal" << endl;
        cout << "4- Menu Cliente" << endl;
        cout << "-----------------------------" << endl;
        cout << "0- SALIR" << endl;
        cout << "Opcion: "<< endl;
        cin >> option;

        switch(option)
        {
        case 1:
            _am.menu();
            system("pause");
            break;
        case 2:
            _vm.menu();
            system("pause");
            break;
        case 3:
            _pm.menu();
            system("pause");
            break;
        case 4:
            _cm.menu();
            system("pause");
            break;
        }
    }
    while(option != 0);
}
