#pragma once

#include "utils/Utils.hpp"

namespace Config
{
    inline const auto PORT = std::stoi(Utils::GetEnv("PORT", "8000"));
}
