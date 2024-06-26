#include "PersonaManager.h"


Persona PersonaManager::cargarPersona()
{
    string nombre,apellido,mail;
    int cel,dni;

    cin.ignore();
    cout << "Ingrese el Nombre: " << endl;
    getline(cin, nombre);
    cout << "Ingrese el Apellido: " << endl;
    getline(cin, apellido);
    cout << "Ingrese el Email: " << endl;
    getline(cin,mail);
    cout << "Ingrese el numero de celular: " << endl;
    cel = validarCinInt();
    cout << "Ingrese el numero de dni: " << endl;
    dni = validarCinInt();


    return Persona(nombre,apellido,mail,cel,dni);
}

void PersonaManager::mostrarPersona()
{
    Persona persona;
    cout << "Nombre: " << persona.getNombre() << endl;
    cout << "Apellido: " << persona.getApellido() << endl;
    cout << "Mail: " << persona.getMail() << endl;
    cout << "Cel: " << persona.getCel() << endl;
    cout << "Dni: " << persona.getDni() << endl;
}
