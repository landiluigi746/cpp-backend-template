#pragma once

#include "middlewares/JsonRequest.hpp"
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
    crow::App<JsonRequest> m_App;
};
