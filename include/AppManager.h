#pragma once
#include "AppPersonaManager.h"
#include "AppFacturacionManagger.h"

class AppManager{
public:
    void menu();
    Personal Logueo();
private:
    AppPersonaManager _pm;
    AppFacturacionManagger _fm;
};

