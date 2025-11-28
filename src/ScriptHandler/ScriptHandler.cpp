#include "ScriptHandler.hpp"

#include <iostream>
ScriptHandler::ScriptHandler() {
    std::cout << "Before" << "\n";
    L = luaL_newstate();
    std::cout << "After" << "\n";
}

void ScriptHandler::ExecLuaScript(std::string fileString) {

}