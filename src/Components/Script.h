#pragma once
#include <string>
#include <lua.hpp>

struct Script {
    std::string src;
    int startRef = LUA_NOREF;
    int updateRef = LUA_NOREF;
};