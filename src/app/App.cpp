#include "app/App.hpp"

#include "Config.hpp"
#include "utils/Utils.hpp"

#include <crow/app.h>

Utils::Result<> App::Init()
{
    SetupRoutes();
    m_App.port(Config::PORT).multithreaded();
    return Utils::Result<>();
}

void App::Run()
{
    m_App.run();
}

void App::SetupRoutes()
{
    CROW_LOG_INFO << "Setting up routes...";

    CROW_ROUTE(m_App, "/")([] {
        return "Hello world!";
    });
}
