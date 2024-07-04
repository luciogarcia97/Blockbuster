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

void ventasPorGenero(int genero){
    ArchivoVHS dataVhs;
    ArchivoDetalleVenta dataVentaDetalle("VentaDetalle.dat");

    int cantidad_registros_vhs = dataVhs.contarRegistro();
    int contador_vhs_por_genero = 0;

    for (int i = 0; i < cantidad_registros_vhs; i++)
    {
        if (dataVhs.leerRegistro(i).getGeneroP() == genero)
        {
            contador_vhs_por_genero++;
        }
    }

    int *AcumuladorCantidad;
    int *posicion_vhs;

    cout << "Acumulador vhs x gen = " << contador_vhs_por_genero << endl;
    
    posicion_vhs = new int[contador_vhs_por_genero];
    if (posicion_vhs == nullptr)
    {
        cout << "No se pudo pedir memoria para el objeto posicion";
        return;
    }

    int j = 0;
    for (int i = 0; i < cantidad_registros_vhs; i++)
    {
        if (dataVhs.leerRegistro(i).getGeneroP() == genero)
        {
            posicion_vhs[j] = dataVhs.leerRegistro(i).getNumeroArtV();
            j++;
        }
    }


    AcumuladorCantidad = new int[contador_vhs_por_genero];
    if (AcumuladorCantidad == nullptr)
    {
        cout << "No se pudo pedir memoria para el objeto acumulador cantidad";
        return;
    }
     AcumuladorCantidad={};

    int cantidad_venta_detalle = dataVentaDetalle.contarRegistros();

    for (int i = 0; i < cantidad_venta_detalle; i++)
    {
        if (dataVentaDetalle.leerRegistro(i).getTipoArticulo() == 1)
        {
            for (int j = 0; j < cantidad_registros_vhs; j++)
            {
                if (posicion_vhs[i] = dataVentaDetalle.leerRegistro(i).getnumarticulo())
                {
                    AcumuladorCantidad[i]++;
                }
            }
        }
    }
    
    

    delete []AcumuladorCantidad;
    delete []posicion_vhs;
    system("pause");
}

void menuReportes(){
    int option;
    system("cls");
    do
    {
        system("cls");
        cout << "------ MENU PRINCIPAL ------- " << endl;
        cout << "1- Ventas de vhs por genero" << endl;
        cout << "2- Ventas de juego por plataforma" << endl;
        cout << "-----------------------------" << endl;
        cout << "0- SALIR" << endl;
        cout << "Opcion: "<< endl;
        option = validarCinInt();
        system("cls");
        switch(option){
            case 1:
                int genero;
                GeneroManager gm;

                cout << "Ingrese el genero: ";
                gm.listarGenero();
                genero = validarCinInt();
                while (!gm.validarExistenciaId(genero))
                {
                    cout << "El genero ingresado no existe, ingrese nuevamente" << endl;
                    genero = validarCinInt();
                }
                ventasPorGenero(genero);
                break;
            case 2:

                break;
        }
    }while(option != 0);
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
        cout << "4- Reportes" << endl;
        cout << "-----------------------------" << endl;
        cout << "0- SALIR" << endl;
        cout << "Opcion: "<< endl;
        option = validarCinInt();

        switch(option)
        {
        case 1:
            _fm.menu();
            break;
        case 2:
            _pm.menu();
            break;
        case 3:
            _am.menu();
            break;
        case 4:
            menuReportes();
            break;
        }
    }while(option != 0);
}


