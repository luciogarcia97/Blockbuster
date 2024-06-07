#include <iostream>
#include "ClientesManager.h"
#include "ClienteArchivo.h"
#include "Cliente.h"
#include "Persona.h"
#include "PersonaManager.h"

using namespace std;

Cliente ClienteManager::crearCliente()
{
    int id_cliente;
    bool estado_cliente;
    bool estado_alquiler;
    PersonaManager obj;
    Persona p;

    id_cliente= _clienteArchivo.getNuevoID();
    cout << "El ID del cliente es : " << id_cliente << endl;
    p = obj.cargarPersona();

    cout << "Ingrese el estado del cliente 1-activo 0-inactivo" << endl;
    cin >> estado_cliente;
    cout << "Ingrese el estado del alquiler del cliente 1-falta devolver 0-ya devolvio el producto: " << endl;
    cin >> estado_alquiler;


    return Cliente(p,id_cliente,estado_cliente,estado_alquiler);
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

        if(reg.getEstadoCliente()==1)
        {


        cout << "Nombre : " << reg.getNombre() << endl;
        cout << "Apellido : " << reg.getApellido() << endl;
        cout << "Mail : " << reg.getMail() << endl;
        cout << "Numero celular : " << reg.getCel() << endl;
        cout << "Documento : " << reg.getDni() << endl;
        cout << "Numero Cliente: " << reg.getIdCliente() << endl;
        cout << "Estado Cliente: " << (reg.getEstadoCliente() ? "Disponible": "Eliminado") << endl;
        cout << "Estado Alquiler: " << (reg.getEstadoAlquiler() ? "Debe juegos o peliculas": "No debe nada") << endl;
        cout << "----------------------------" << endl;
        }

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
        cout << "3- MODIFICAR CLIENTE" << endl;
        cout << "4- ELIMINAR CLIENTE" << endl;
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
        case 3:
        modificarCliente();
        break;
        case 4:
        eliminarCliente();
        break;
        }
    }while(opcion!= 0);

}

void ClienteManager::mostrarCliente(Cliente reg)
{
    cout << "Nombre : " << reg.getNombre() << endl;
    cout << "Apellido :" << reg.getApellido() << endl;
    cout << "Mail : " << reg.getMail() << endl;
    cout << "Numero celular : " << reg.getCel() << endl;
    cout << "Documento : " << reg.getDni() << endl;
    cout << "Numero Cliente: " << reg.getIdCliente() << endl;
    cout << "Estado Cliente: " << (reg.getEstadoCliente() ? "Eliminado": "Disponible") << endl;
    cout << "Estado Alquiler: " << (reg.getEstadoAlquiler() ? "Debe juegos o peliculas": "No debe nada") << endl;
}


void ClienteManager::modificarCliente()
{
    int num_cliente, index;
    Cliente cliente;

    cout << "Ingrese el Numero de cliente que desea modificar :" << endl;
    cin >> num_cliente;

    index = _clienteArchivo.buscarCliente(num_cliente);

    if(index != -1){
        cliente = _clienteArchivo.leer(index);
        mostrarCliente(cliente);
        volverCargarCliente(cliente);
        if(_clienteArchivo.guardar(index,cliente)){
            cout << "Se modifico el Cliente con exito" << endl;
        }
        else{
            cout << "No se pudo modificar el Cliente" << endl;
        }

    }
    else{
        cout << "No se encuentro el cliente" << endl;
    }
}
void ClienteManager::eliminarCliente()
{
    int num_cliente, index;
    Cliente cliente;
    bool eliminar;

    cout << "Ingrese el Numero de cliente que desea eliminar :" << endl;
    cin >> num_cliente;

    index = _clienteArchivo.buscarCliente(num_cliente);

    if(index != -1)
    {
        cliente = _clienteArchivo.leer(index);
        mostrarCliente(cliente);

        cout << "�Esta seguro/a de eliminar el cliente? 1-SI 0-NO" << endl;
        cin >> eliminar;
        if (eliminar){
            cliente.setEstadoCliente(false);

            if(_clienteArchivo.guardar(index,cliente))
            {
                cout << "Se elimino el Cliente con exito" << endl;
            }
            else
            {
                cout << "No se pudo eliminar el Cliente" << endl;
            }
        }
        else{
            cout << "El Cliente no fue eliminado" << endl;
        }

    }
    else
    {
        cout << "No se encuentro el cliente" << endl;
    }
}

void ClienteManager::volverCargarCliente(Cliente &registro)
{
    string nombre,apellido,mail;
    int cel,dni;
    bool estado_cliente;
    bool estado_alquiler;

    cin.ignore();
    cout << "Ingrese el Nombre: " << endl;
    getline(cin, nombre);
    cout << "Ingrese el Apellido: " << endl;
    getline(cin, apellido);
    cout << "Ingrese el Email: " << endl;
    getline(cin,mail);
    cout << "Ingrese el numero de celular: " << endl;
    cin >> cel;
    cout << "Ingrese el numero de dni: " << endl;
    cin >> dni;
    cout << "Ingrese el estado del cliente 1-activo 0-inactivo" << endl;
    cin >> estado_cliente;
    cout << "Ingrese el estado del alquiler del cliente 1-falta devolver 0-ya devolvio el producto: " << endl;
    cin >> estado_alquiler;

    registro.setNombre(nombre);
    registro.setApellido(apellido);
    registro.setMail(mail);
    registro.setCel(cel);
    registro.setDni(dni);
    registro.setEstadoCliente(estado_cliente);
    registro.setEstadoAlquiler(estado_alquiler);
}
