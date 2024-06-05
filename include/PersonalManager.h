#pragma once
#include "PersonalArchivo.h"
#include "Personal.h"
#include "Persona.h"

class PersonalManager{

public:
        void menu();
    private:

    Personal crearPersonal();
    void agregarPersonal();
    void listarPersonal();
    void mostrarPersonal(Personal reg);
    void volverCargarPersonal(Personal &registro);
    void modificarPersonal();
    void eliminarPersonal();
    PersonalArchivo _personalArchivo;
};

