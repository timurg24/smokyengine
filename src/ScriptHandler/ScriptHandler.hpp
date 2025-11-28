#pragma once
#include <lua.hpp>
#include <string>
#include "ScriptAPI/Wrapper/ScriptAPI.h"

#include "Components/ComponentPool.h"
#include "Components/Script.h"
#include "Entity/Entity.h"

// ScriptHandler is responsable for the registration of the wrapper functions and executing the scripts (RegisterAPI)
// ScriptAPI/Wrapper is holds the wrapper functions

class ScriptHandler {
private:
    lua_State* L = nullptr;
    void RegisterAPI();
public:
    ScriptHandler();

    void LoadScriptsFromPool(ComponentPool<Script>& pool);
    void ExecUpdate(ComponentPool<Script>& pool, float dt);

    void LoadScriptForEntity(Entity id, Script& script);
};