#pragma once
#include <lua.hpp>
#include <string>

class ScriptHandler {
private:
    lua_State* L = nullptr;
    ScriptHandler();

    void ExecLuaScript(std::string fileString);
};