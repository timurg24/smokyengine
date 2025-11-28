#pragma once
#include <stdint.h>
#include <string>

using Entity = uint32_t;

Entity GenerateID(std::string name);
