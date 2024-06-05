#pragma once
#include "AlquilerManager.h"
#include "VentaManager.h"
#include "PersonalManager.h"
#include "ClientesManager.h"

class AppManager{
public:
    void menu();
private:
    AlquilerManager _am;
    VentaManager _vm;
    PersonalManager _pm;
    ClienteManager _cm;
};

