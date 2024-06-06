#pragma once
#include <iostream>
#include "PersonalManager.h"
#include "ClientesManager.h"

class AppPersonaManager
{
    public:
        void menu();
    private:
        PersonalManager _pm;
        ClienteManager _cm;
};

