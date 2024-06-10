#include "AppFacturacionManagger.h"

void AppFacturacionManagger::menu()
{
    int option;
    system("cls");
    do
    {
        system("cls");
        std::cout << "------ MENU FACTURACION ------- " << std::endl;
        std::cout << "1- Menu Ventas" << std::endl;
        std::cout << "2- Menu Alquiler" << std::endl;
        std::cout << "-------------------------------" << std::endl;
        std::cout << "0- SALIR" << std::endl;
        std::cout << "Opcion: "<< std::endl;
        option = validarCinInt();

        switch(option)
        {
        case 1:
            _vm.menu();
            break;
        case 2:            
            _am.menu();
            break;
        }
    }
    while(option != 0);
}