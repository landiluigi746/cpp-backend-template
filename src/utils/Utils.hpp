#pragma once

#include <crow/common.h>
#include <expected>
#include <string>
#include <string_view>

namespace Utils
{
    struct ErrorData
    {
        crow::status statusCode;
        std::string message;
    };

    template<typename T = void>
    using Result = std::expected<T, ErrorData>;
    using Error = std::unexpected<ErrorData>;

    std::string GetEnv(std::string_view varName, std::string_view defaultValue);
} // namespace Utils
