#include <iostream>
#include "PersonalManager.h"
#include "PersonalArchivo.h"
#include "Personal.h"
#include "Persona.h"
#include "PersonaManager.h"


using namespace std;

Personal PersonalManager::crearPersonal()
{
    int legajo_personal;
    char contrasena [30];
    int cargo;
    float sueldo;
    float porcentaje_comision;
    float comi_acu = 0.0f;
    bool estado_personal;
    Persona p;
    PersonaManager obj;

    legajo_personal = _personalArchivo.getNuevoLegajo();
    cout << "El Legajo del personal es : " << legajo_personal << endl;
    p = obj.cargarPersona();

    cout << "Ingrese la contrasena del Personal: " << endl;
    cin >> contrasena;
    cout << "Ingrese el Cargo del Personal :" << endl;
    cin >> cargo;
    cout << "Ingrese el Sueldo del Personal: " << endl;
    cin >> sueldo;
    cout << "Ingrese el porcentaje de comision del Personal: " << endl;
    cin >> porcentaje_comision;
    cout << "Ingrese el estado del Personal: 1-ACTIVO 0-INACTIVO" << endl;
    cin >> estado_personal;

    return Personal (p,legajo_personal,contrasena,cargo,sueldo,porcentaje_comision,comi_acu,estado_personal);
}
void PersonalManager::agregarPersonal()
{

   if(_personalArchivo.guardar(crearPersonal())){
      cout << "El Personal fue guardado con exito!" << endl;
   }
   else{
      cout << "No se pudo guardar el Personal!" << endl;
   }
}
void PersonalManager::listarPersonal(){
  int cantidad = _personalArchivo.getCantidadRegistrosPersonal();

    for (int i =0; i<cantidad; i++){
        Personal reg = _personalArchivo.leer(i);

        if(reg.getEstadoPersonal()==1)
        {


        cout << "Nombre : " << reg.getNombre() << endl;
        cout << "Apellido : " << reg.getApellido() << endl;
        cout << "Mail : " << reg.getMail() << endl;
        cout << "Numero celular : " << reg.getCel() << endl;
        cout << "Documento : " << reg.getDni() << endl;
        cout << "Numero Legajo: " << reg.getLegajoPersonal() << endl;
        cout << "Contrasena: " << reg.getContrasena() << endl;
        cout << "Cargo: " << reg.getCargo() << endl;
        cout << "Sueldo: " << reg.getSueldo() << endl;
        cout << "Porcentaje de comision: " << reg.getPorcentajeComision() << "%" << endl;
        cout << "Comision acumulada: $" << reg.getComisionAcumulada() << endl;
        cout << "Estado Personal: " << (reg.getEstadoPersonal() ? "Disponible": "Eliminado") << endl;
        cout << "----------------------------" << endl;
        }

    }
}

void PersonalManager::menu(){
    int opcion;
    system("cls");
    do {
        system("cls");
        cout << "-------MENU PERSONAL-------" << endl;
        cout << "1- AGREGAR PERSONAL" << endl;
        cout << "2- LISTAR PERSONAL" << endl;
        cout << "3- MODIFICAR PERSONAL" << endl;
        cout << "4- ELIMINAR PERSONAL" << endl;
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
        case 3:
        modificarPersonal();
        break;
        case 4:
        eliminarPersonal();
        break;

        }
    system("pause");

    }while(opcion!= 0);

}
void PersonalManager::modificarPersonal()
{
    int num_personal, index;
    Personal personal;

    cout << "Ingrese el Numero de legajo que desea modificar :" << endl;
    cin >> num_personal;

    index = _personalArchivo.buscarPersonal(num_personal);

    if(index != -1){
        personal = _personalArchivo.leer(index);
        mostrarPersonal(personal);
        volverCargarPersonal(personal);
        if(_personalArchivo.guardar(index,personal)){
            cout << "Se modifico el Personal con exito" << endl;
        }
        else{
            cout << "No se pudo modificar el Personal" << endl;
        }

    }
    else{
        cout << "No se encuentro el Personal" << endl;
    }
}
void PersonalManager::eliminarPersonal()
{
    int num_personal, index;
    Personal personal;
    bool eliminar;

    cout << "Ingrese el Numero de legajo del personal que desea eliminar :" << endl;
    cin >> num_personal;

    index = _personalArchivo.buscarPersonal(num_personal);

    if(index != -1)
    {
        personal = _personalArchivo.leer(index);
        mostrarPersonal(personal);

        cout << "�Esta seguro/a de eliminar el Personal? 1-SI 0-NO" << endl;
        cin >> eliminar;
        if (eliminar){
            personal.setEstadoPersonal(false);

            if(_personalArchivo.guardar(index,personal))
            {
                cout << "Se elimino el Personal con exito" << endl;
            }
            else
            {
                cout << "No se pudo eliminar el Personal" << endl;
            }
        }
        else{
            cout << "El Personal no fue eliminado" << endl;
        }

    }
    else
    {
        cout << "No se encuentro el Personal" << endl;
    }
}

void PersonalManager::volverCargarPersonal(Personal &registro)
{
    string nombre,apellido,mail,contrasena;
    int cargo,cel,dni;
    bool estado_personal;
    float sueldo, porcentaje_comision;



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
    cout << "Ingrese la contrasena del Personal: " << endl;
    cin >> contrasena;
    cout << "Ingrese el Cargo del Personal :" << endl;
    cin >> cargo;
    cout << "Ingrese el Sueldo del Personal: " << endl;
    cin >> sueldo;
    cout << "Ingrese la comision del Personal: " << endl;
    cin >> porcentaje_comision;
    cout << "Ingrese el estado del Personal: 1-ACTIVO 0-INACTIVO" << endl;
    cin >> estado_personal;

    registro.setNombre(nombre);
    registro.setApellido(apellido);
    registro.setMail(mail);
    registro.setCel(cel);
    registro.setDni(dni);
    registro.setContrasena(contrasena);
    registro.setCargo(cargo);
    registro.setSueldo(sueldo);
    registro.setPorcentajeComision(porcentaje_comision);
    registro.setEstadoPersonal(estado_personal);
}
void PersonalManager::mostrarPersonal(Personal reg)
{

    cout << "Nombre: " << reg.getNombre() << endl;
    cout << "Apellido: " << reg.getApellido() << endl;
    cout << "Mail: " << reg.getMail() << endl;
    cout << "Cel: " << reg.getCel() << endl;
    cout << "Dni: " << reg.getDni() << endl;
    cout << "Num Legajo: " << reg.getLegajoPersonal();
    cout << "Contrasena del Personal: " << reg.getContrasena();
    cout << "Cargo del Personal: " << reg.getCargo();
    cout << "Sueldo del Personal: " << reg.getSueldo();
    cout << "Estado del Personal: " << (reg.getEstadoPersonal() ? "Disponible": "Eliminado") << endl;
}

Personal PersonalManager::buscarPersonalPorLegajo(int legajo){
    Personal obj;
    int posicion;
    posicion = _personalArchivo.buscarPersonal(legajo);
    if (posicion >= 0)
    {
        obj = _personalArchivo.leer(posicion); //Devuelve un Personal
        return obj;
    }
    return obj;
}
