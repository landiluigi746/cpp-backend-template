#include "Config.hpp"
#include <crow.h>

int main()
{
    crow::SimpleApp app;

    CROW_ROUTE(app, "/")
    ([] {
        return "Hello world!";
    });

    app.port(Config::PORT).multithreaded().run();

    return 0;
}
