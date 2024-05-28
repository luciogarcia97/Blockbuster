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
    PersonalArchivo _personalArchivo;

};

