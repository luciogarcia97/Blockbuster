#pragma once
#include "AppPersonaManager.h"
#include "AppFacturacionManagger.h"
#include "ArticulosManager.h"

class AppManager{
public:
    void menu();
    Personal Logueo();
private:
    AppPersonaManager _pm;
    AppFacturacionManagger _fm;
    ArticulosManager _am;
};

