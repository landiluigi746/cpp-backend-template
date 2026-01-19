#include "app/App.hpp"

#include "Config.hpp"
#include "middlewares/JsonRequest.hpp"
#include "utils/Utils.hpp"

#include <crow/app.h>
#include <crow/http_request.h>
#include <crow/http_response.h>
#include <crow/json.h>

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

    CROW_ROUTE(m_App, "/json")
        .CROW_MIDDLEWARES(m_App, JsonRequest)
        .methods("POST"_method)([](const crow::request& req) {
            auto reqJson = crow::json::load(req.body);

            if (!reqJson)
                return crow::response(crow::status::BAD_REQUEST, "Invalid JSON data");

            return crow::response(crow::status::OK, crow::json::wvalue(reqJson));
        });
}
