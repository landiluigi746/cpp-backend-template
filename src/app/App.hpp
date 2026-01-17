#pragma once

#include "utils/Utils.hpp"

#include <crow/app.h>

class App
{
public:
    Utils::Result<> Init();
    void Run();

private:
    void SetupRoutes();

private:
    crow::SimpleApp m_App;
};
