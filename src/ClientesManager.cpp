#include <iostream>
#include "ClientesManager.h"
#include "ClienteArchivo.h"
#include "Cliente.h"

using namespace std;

Cliente ClienteManager::crearCliente()
{
    Cliente obj;
    obj.crearCliente();

    return obj;
}


void ClienteManager::agregarCliente()
{

   if(_clienteArchivo.guardar(crearCliente())){
      cout << "El cliente fue guardado con exito!" << endl;
   }
   else{
      cout << "No se pudo guardar el cliente!" << endl;
   }
}
void ClienteManager::listarClientes(){
  int cantidad = _clienteArchivo.getCantidadRegistrosClientes();

    for (int i =0; i<cantidad; i++){
        Cliente reg = _clienteArchivo.leer(i);

        cout << "Nombre : " << reg.getNombre() << endl;
        cout << "Apellido : " << reg.getApellido() << endl;
        cout << "Mail : " << reg.getMail() << endl;
        cout << "Numero celular : " << reg.getCel() << endl;
        cout << "Documento : " << reg.getDni() << endl;
        cout << "------------------------------" << endl;
        cout << "Numero Cliente: " << reg.getIdCliente() << endl;
        cout << "Estado cliente: " << reg.getEstadoCliente() << endl;
        cout << "Estado Alquiler :" << reg.getEstadoAlquiler() << endl;
    }
}

void ClienteManager::menu(){
    int opcion;
    system("cls");
    do {
        system("cls");
        cout << "-------MENU CLIENTE-------" << endl;
        cout << "1- AGREGAR CLIENTE" << endl;
        cout << "2- LISTAR CLIENTES" << endl;
        cout << "----------------------------" << endl;
        cout << "0- SALIR" << endl;
        cout << "INGRESE OPCION :" << endl;
        cin >> opcion;

        switch (opcion){
        case 1:
        agregarCliente();
        break;
        case 2:
        listarClientes();
        break;
        }
    system("pause");

    }while(opcion!= 0);

}
