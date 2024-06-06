#pragma once
#include "AlquilerManager.h"
#include "VentaManager.h"
#include <iostream>

class AppFacturacionManagger
{
    public:
        void menu();
    private:
        AlquilerManager _am;
        VentaManager _vm;
};

