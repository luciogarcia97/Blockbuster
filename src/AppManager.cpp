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
    system("cls");

    ArchivoVHS dataVhs;
    ArchivoDetalleVenta dataVentaDetalle("VentaDetalle.dat");


    int cantidad_registros_vhs = dataVhs.contarRegistro();
    if (cantidad_registros_vhs == -1)
    {
        cout << "No existe el .dat de vhs" << endl;
        return;
    }

    int contador_vhs_por_genero = 0;

    for (int i = 0; i < cantidad_registros_vhs; i++)
    {
        if (dataVhs.leerRegistro(i).getGeneroP() == genero)
        {
            contador_vhs_por_genero++;
        }
    }

    if (contador_vhs_por_genero == 0)
    {
        cout << "No hay ventas registradas de ese genero de pelicula" << endl;
        return;
    }

    int *posicion_vhs;

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

    int *acumuladorCantidad;
    acumuladorCantidad = new int[contador_vhs_por_genero];
    if (acumuladorCantidad == nullptr)
    {
        cout << "No se pudo pedir memoria para el objeto acumulador cantidad";
        return;
    }

    for (int i = 0; i < contador_vhs_por_genero; i++)
    {
        acumuladorCantidad[i] = 0;
    }

    int cantidad_venta_detalle = dataVentaDetalle.contarRegistros();

    if (cantidad_venta_detalle == -1)
    {
        cout << "No existe el .dat de venta detalle" << endl;
        return;
    }


    for (int i = 0; i < cantidad_venta_detalle; i++)
    {
        if (dataVentaDetalle.leerRegistro(i).getnumventa() == -1)
        {
            cout << "No se pudo leer el .dat de venta detalle" << endl;
            return;
        }

        if (dataVentaDetalle.leerRegistro(i).getTipoArticulo() == 1)
        {
            int numero_articulo = dataVentaDetalle.leerRegistro(i).getnumarticulo();
            int posicion_numero_articulo = dataVhs.buscarXnumero(numero_articulo);

            if (dataVhs.leerRegistro(posicion_numero_articulo).getGeneroP() == genero)
            {
                for (int j = 0; j < contador_vhs_por_genero; j++)
                {
                    if (posicion_vhs[j] == numero_articulo)
                    {
                        acumuladorCantidad[j] += dataVentaDetalle.leerRegistro(i).getcantidad();
                    }
                }
            }
        }
    }
    int auxAcu, auxPos;

    for (int i = 0; i < contador_vhs_por_genero; i++)
    {
        for (int j = 0; j < contador_vhs_por_genero; j++)
        {
            if (acumuladorCantidad[j] > acumuladorCantidad[j+1])
            {
                auxAcu = acumuladorCantidad[j];
                acumuladorCantidad[j] = acumuladorCantidad[j+1];
                acumuladorCantidad[j+1] = auxAcu;

                auxPos = posicion_vhs[j];
                posicion_vhs[j] = posicion_vhs[j+1];
                posicion_vhs[j+1] = auxPos;
            }
        }
    }


    int contadoraux = contador_vhs_por_genero - 1;

    system("cls");
    cout << "id_vhs \t\t Titulo \t\t\t Cantidad de ventas" << endl;
    for (int i = contadoraux; i >= 0; i--)
    {
        if(acumuladorCantidad[i] == 0) continue;
        int posicion = dataVhs.buscarXnumero(posicion_vhs[i]);
        if (posicion != -1 && posicion !=-2)
        {
            cout << dataVhs.leerRegistro(posicion).getNumeroArtV() << "\t\t" << dataVhs.leerRegistro(posicion).getTituloP() << "\t\t\t" << acumuladorCantidad[i] << endl;
        }
    }

    delete posicion_vhs;
    delete acumuladorCantidad;
}

void ventasPorPlataforma(int plataforma){
    ArchivoJuego dataJuego;
    ArchivoDetalleVenta dataVentaDetalle("VentaDetalle.dat");

    int cantidad_registros_juego = dataJuego.contarRegistro();
    if (cantidad_registros_juego == -1)
    {
        cout << "No existe el .dat de juegos" << endl;
        return;
    }

    int contador_juego_por_plataforma = 0;

    for (int i = 0; i < cantidad_registros_juego; i++)
    {
        if (dataJuego.leerRegistro(i).getPlataforma() == plataforma)
        {
            contador_juego_por_plataforma++;
        }
    }

    if (contador_juego_por_plataforma == 0)
    {
        cout << "No hay ventas registradas de esa plataforma" << endl;
    }

    int *numero_juego;

    numero_juego = new int[contador_juego_por_plataforma];
    if (numero_juego == nullptr)
    {
        cout << "No se pudo pedir memoria para el vector numero_juego";
        return;
    }

    int j = 0;
    for (int i = 0; i < cantidad_registros_juego; i++)
    {
        if (dataJuego.leerRegistro(i).getPlataforma() == plataforma)
        {
            numero_juego[j] = dataJuego.leerRegistro(i).getNumeroArtJ();
            j++;
        }
    }

    int *acumulador_cantidad;
    acumulador_cantidad = new int[contador_juego_por_plataforma];
    if (acumulador_cantidad == nullptr)
    {
        cout << "No se pudo pedir memoria para el objeto acumulador cantidad";
        delete numero_juego;
        return;
    }

    for (int i = 0; i < contador_juego_por_plataforma; i++)
    {
        acumulador_cantidad[i] = 0;
    }

    int cantidad_venta_detalle = dataVentaDetalle.contarRegistros();

    if (cantidad_venta_detalle == -1)
    {
        cout << "No existe el .dat de venta detalle" << endl;
        delete numero_juego;
        delete acumulador_cantidad;
        return;
    }

    for (int i = 0; i < cantidad_venta_detalle; i++)
    {
        if (dataVentaDetalle.leerRegistro(i).getnumventa() == -1)
        {
            cout << "No se pudo leer el .dat de venta detalle" << endl;
            return;
        }

        if (dataVentaDetalle.leerRegistro(i).getTipoArticulo() == 2)
        {
            int numero_articulo = dataVentaDetalle.leerRegistro(i).getnumarticulo();
            int posicion_numero_articulo = dataJuego.buscarXnumero(numero_articulo);

            if (dataJuego.leerRegistro(posicion_numero_articulo).getPlataforma() == plataforma)
            {
                for (int j = 0; j < contador_juego_por_plataforma; j++)
                {
                    if (numero_juego[j] == numero_articulo)
                    {
                        acumulador_cantidad[j] += dataVentaDetalle.leerRegistro(i).getcantidad();
                    }
                }
            }
        }
    }

int auxAcu, auxPos;

    for (int i = 0; i < contador_juego_por_plataforma; i++)
    {
        for (int j = 0; j < contador_juego_por_plataforma; j++)
        {
            if (acumulador_cantidad[j] > acumulador_cantidad[j+1])
            {
                auxAcu = acumulador_cantidad[j];
                acumulador_cantidad[j] = acumulador_cantidad[j+1];
                acumulador_cantidad[j+1] = auxAcu;

                auxPos = numero_juego[j];
                numero_juego[j] = numero_juego[j+1];
                numero_juego[j+1] = auxPos;
            }
        }
    }

    int contadoraux = contador_juego_por_plataforma - 1;

    system("cls");
    cout << "id_juego \t Titulo \t\t Cantidad de ventas" << endl;
    for (int i = contadoraux; i >= 0; i--)
    {
        if(acumulador_cantidad[i] == 0) continue;
        int posicion = dataJuego.buscarXnumero(numero_juego[i]);
        if (posicion != -1 && posicion !=-2)
        {
            cout << dataJuego.leerRegistro(posicion).getNumeroArtJ() << "\t\t" << dataJuego.leerRegistro(posicion).getTituloJ() << "\t\t" << acumulador_cantidad[i] << endl;
        }
    }

    delete numero_juego;
    delete acumulador_cantidad;
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
                system("pause");
                break;
            case 2:
                int plataforma;
                cout<<"Ingrese la plataforma: 1)PC 2)PSN 3)XBOX" << endl;
                plataforma = validarCinInt();
                	while (plataforma != 1 && plataforma != 2 && plataforma !=3)
                    {
                        cout << "Dato invalido, ingrese nuevamente :" << endl;
                        plataforma = validarCinInt();
                    }
                ventasPorPlataforma(plataforma);
                system("pause");
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


