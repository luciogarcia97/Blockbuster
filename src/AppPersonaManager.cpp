#include "AppPersonaManager.h"

void AppPersonaManager::menu()
{
    /*
        Si o si vamos a necesitar el id de cargo para mostrar los menus.
            PersonalManager 
        
        
        Posible mejora, pasar tambien por parametro el legajo, asi evitar cargarlo    
    */
    int option;
    system("cls");
    do
    {
        system("cls");
        std::cout << "------ MENU PERSONA ------- " << std::endl;
        std::cout << "1- Menu Personal" << std::endl;
        std::cout << "2- Menu Cliente" << std::endl;
        std::cout << "-----------------------------" << std::endl;
        std::cout << "0- SALIR" << std::endl;
        std::cout << "Opcion: "<< std::endl;
        std::cin >> option;

        switch(option)
        {
        case 1:
            _pm.menu();
            break;
        case 2:
            _cm.menu();
            break;
        }
    }
    while(option != 0);
}