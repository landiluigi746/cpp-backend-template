#include "app/App.hpp"

#include <cstdlib>
#include <print>

int main()
{
    App app;

    if (auto res = app.Init(); !res)
    {
        std::println("Fatal error during initialization: {}", res.error().message);
        return EXIT_FAILURE;
    }

    app.Run();

    return EXIT_SUCCESS;
}
