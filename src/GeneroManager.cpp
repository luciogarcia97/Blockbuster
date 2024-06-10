#include "GeneroManager.h"

void GeneroManager::menu(){
    int opcion;
    system("cls");
    do {
        system("cls");
        cout << "-------MENU GENERO-------" << endl;
        cout << "1- AGREGAR GENERO" << endl;
        cout << "2- LISTAR GENERO" << endl;
        cout << "3- MODIFICAR GENERO" << endl;
        cout << "4- ELIMINAR GENERO" << endl;
        cout << "----------------------------" << endl;
        cout << "0- SALIR" << endl;
        cout << "INGRESE OPCION :" << endl;
        cin >> opcion;
        system("cls");
        switch (opcion){
        case 1:
        agregarGenero();
        break;
        case 2:
        listarGenero();
        break;
        case 3:
        modificarGenero();
        break;
        case 4:
        eliminarGenero();
        break;

        }
    system("pause");

    }while(opcion!= 0);

}

void GeneroManager::buscarGeneroPorNumero(){
    int id, posicion;

    std::cout << "Ingrese el id de genero a buscar: ";
    id = validarCinInt();

    posicion = _generoArchivo.buscarRegistro(id);
    //headerGenero();
    mostrarGenero(_generoArchivo.leerRegistro(posicion));
}

Genero GeneroManager::crearGenero(){
int id;
string nombre_genero;
bool estado;

    id = _generoArchivo.getNuevoId();
    cout << "El ID del genero es : " << id << endl;
    cin.ignore();
    cout << "Ingrese el nombre del Genero: " << endl;
    std::getline (std::cin,nombre_genero);
    cout << "Ingrese el estado del Genero: 1-ACTIVO 0-INACTIVO" << endl;
    cin >> estado;

    return Genero(id, nombre_genero, estado);
}

void GeneroManager::agregarGenero(){
 if(_generoArchivo.agregarRegistro(crearGenero())){
      cout << "El Genero fue creado con exito!" << endl;
   }
   else{
      cout << "No se pudo crear el Genero!" << endl;
   }
}

void GeneroManager::listarGenero(){
int cantidad = _generoArchivo.contarRegistros();
    for (int i =0; i<cantidad; i++){
        Genero reg = _generoArchivo.leerRegistro(i);

        if(reg.getEstado()==1)
        {
        cout << "ID : " << reg.getNumero() << endl;
        cout << "Nombre : " << reg.getNombre() << endl;
        cout << "Estado Genero: " << (reg.getEstado() ? "Disponible": "Eliminado") << endl;
        cout << "----------------------------" << endl;
        }

    }
}

void GeneroManager::mostrarGenero(Genero reg){
        cout << "ID : " << reg.getNumero() << endl;
        cout << "Nombre : " << reg.getNombre() << endl;
        cout << "Estado Genero: " << (reg.getEstado() ? "Disponible": "Eliminado") << endl;
        cout << "----------------------------" << endl;
}

void GeneroManager::modificarGenero(){
 int num_genero, index;
   Genero genero;

    cout << "Ingrese el Numero de ID que desea modificar :" << endl;
    cin >> num_genero;

    index = _generoArchivo.buscarRegistro(num_genero);

    if(index != -1){
        genero = _generoArchivo.leerRegistro(index);
        mostrarGenero(genero);
        volverCargarGenero(genero);
        if(_generoArchivo.agregarRegistro(genero,index)){
            cout << "Se modifico el Genero con exito" << endl;
        }
        else{
            cout << "No se pudo modificar el Genero" << endl;
        }

    }
    else{
        cout << "No se encuentro el Genero" << endl;
    }
}

void GeneroManager::eliminarGenero(){
int num_genero, index;
    Genero genero;
    bool eliminar;

    cout << "Ingrese el Numero de legajo del genero que desea eliminar :" << endl;
    cin >> num_genero;

    index = _generoArchivo.buscarRegistro(num_genero);

    if(index != -1)
    {
        genero = _generoArchivo.leerRegistro(index);
        mostrarGenero(genero);

        cout << "Esta seguro/a de eliminar el Genero? 1-SI 0-NO" << endl;
        cin >> eliminar;
        if (eliminar){
            genero.setEstado(false);

            if(_generoArchivo.agregarRegistro(genero,index))
            {
                cout << "Se elimino el genero con exito" << endl;
            }
            else
            {
                cout << "No se pudo eliminar el genero" << endl;
            }
        }
        else{
            cout << "El genero no fue eliminado" << endl;
        }

    }
    else
    {
        cout << "No se encuentro el genero" << endl;
    }
}

void GeneroManager::volverCargarGenero(Genero &registro){
    string nombre_genero;
    bool estado;
    
    cin.ignore();
    cout << "Ingrese el nombre del Genero: " << endl;
    std::getline (std::cin,nombre_genero);

    cout << "Ingrese el estado del Genero: 1-ACTIVO 0-INACTIVO" << endl;
    cin >> estado;

    registro.setNombre(nombre_genero);
    registro.setEstado(estado);
}

