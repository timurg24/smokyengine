#include "ScriptHandler.hpp"

#include <iostream>

void ScriptHandler::RegisterAPI() {
    // --- ENGINE ---
    lua_pushcfunction(L, WRAPPER::Quit);
    lua_setglobal(L, "Quit");

    lua_pushcfunction(L, WRAPPER::GetFPS);
    lua_setglobal(L, "GetFPS");

    lua_pushcfunction(L, WRAPPER::Log);
    lua_setglobal(L, "Log");

    // --- SCENE ---
    lua_pushcfunction(L, WRAPPER::Load);
    lua_setglobal(L, "Load");

    lua_pushcfunction(L, WRAPPER::Reload);
    lua_setglobal(L, "Reload");

    // --- ENTITY ---
    lua_pushcfunction(L, WRAPPER::Create);
    lua_setglobal(L, "Create");

    lua_pushcfunction(L, WRAPPER::Exist);
    lua_setglobal(L, "Exist");

    lua_pushcfunction(L, WRAPPER::Destroy);
    lua_setglobal(L, "Destroy");

    // --- TRANSFORM ---
    lua_pushcfunction(L, WRAPPER::SetPosition);
    lua_setglobal(L, "SetPosition");

    lua_pushcfunction(L, WRAPPER::SetRotation);
    lua_setglobal(L, "SetRotation");

    lua_pushcfunction(L, WRAPPER::SetWidth);
    lua_setglobal(L, "SetWidth");

    lua_pushcfunction(L, WRAPPER::SetHeight);
    lua_setglobal(L, "SetHeight");

    lua_pushcfunction(L, WRAPPER::GetPositionX);
    lua_setglobal(L, "GetPositionX");

    lua_pushcfunction(L, WRAPPER::GetPositionY);
    lua_setglobal(L, "GetPositionY");

    lua_pushcfunction(L, WRAPPER::GetRotation);
    lua_setglobal(L, "GetRotation");

    lua_pushcfunction(L, WRAPPER::GetWidth);
    lua_setglobal(L, "GetWidth");

    lua_pushcfunction(L, WRAPPER::GetHeight);
    lua_setglobal(L, "GetHeight");

    lua_pushcfunction(L, WRAPPER::TranslateX);
    lua_setglobal(L, "TranslateX");

    lua_pushcfunction(L, WRAPPER::TranslateY);
    lua_setglobal(L, "TranslateY");

    // --- SPRITE ---
    lua_pushcfunction(L, WRAPPER::NewTexture);
    lua_setglobal(L, "NewTexture");

    // --- CAMERA ---
    lua_pushcfunction(L, WRAPPER::CamSetPosition);
    lua_setglobal(L, "CamSetPosition");

    lua_pushcfunction(L, WRAPPER::CamSetZoom);
    lua_setglobal(L, "CamSetZoom");

    lua_pushcfunction(L, WRAPPER::CamRotation);
    lua_setglobal(L, "CamRotation");

    // --- INPUT ---
    lua_pushcfunction(L, WRAPPER::IsKeyDown);
    lua_setglobal(L, "IsKeyDown");

    lua_pushcfunction(L, WRAPPER::IsKeyPressed);
    lua_setglobal(L, "IsKeyPressed");

    lua_pushcfunction(L, WRAPPER::IsKeyReleased);
    lua_setglobal(L, "IsKeyReleased");

    lua_pushcfunction(L, WRAPPER::IsMouseDown);
    lua_setglobal(L, "IsMouseDown");

    lua_pushcfunction(L, WRAPPER::IsMousePressed);
    lua_setglobal(L, "IsMousePressed");

    lua_pushcfunction(L, WRAPPER::IsMouseReleased);
    lua_setglobal(L, "IsMouseReleased");

    lua_pushcfunction(L, WRAPPER::IsMouseUp);
    lua_setglobal(L, "IsMouseUp");

    lua_pushcfunction(L, WRAPPER::GetMouseX);
    lua_setglobal(L, "GetMouseX");

    lua_pushcfunction(L, WRAPPER::GetMouseY);
    lua_setglobal(L, "GetMouseY");

    // --- AUDIO ---
    lua_pushcfunction(L, WRAPPER::PlaySound);
    lua_setglobal(L, "PlaySound");

    lua_pushcfunction(L, WRAPPER::PlayMusic);
    lua_setglobal(L, "PlayMusic");

    lua_pushcfunction(L, WRAPPER::StopMusic);
    lua_setglobal(L, "StopMusic");

    lua_pushcfunction(L, WRAPPER::SetVolume);
    lua_setglobal(L, "SetVolume");

}

ScriptHandler::ScriptHandler() {
    L = luaL_newstate();
    luaL_openlibs(L);
    RegisterAPI();
}

// gpt helped with the rawgeti, i hope thats not vibecoding
void ScriptHandler::LoadScriptForEntity(Entity id, Script& script) {
    lua_pushinteger(L, id);
    lua_setglobal(L, "this");

    // loading and exeucting the script
    if(luaL_dostring(L, script.src.c_str()) != LUA_OK) {
        std::cout << "Error: " << lua_tostring(L, -1) << "\n";
        lua_pop(L, 1);
        return;
    }

    // register start
    lua_getglobal(L, "Start");
    if (lua_isfunction(L, -1)) {
        script.startRef = luaL_ref(L, LUA_REGISTRYINDEX); // set reference if it is function
    } else {
        lua_pop(L, 1);
        script.startRef = LUA_NOREF;
    }

    // register upate
    lua_getglobal(L, "Update");
    if (lua_isfunction(L, -1)) {
        script.updateRef = luaL_ref(L, LUA_REGISTRYINDEX);
    } else {
        lua_pop(L, 1);
        script.updateRef = LUA_NOREF;
    }

    if(script.startRef != LUA_NOREF) {
        lua_rawgeti(L, LUA_REGISTRYINDEX, script.startRef); // push this start function to the stack
        if(lua_pcall(L,0,0,0) != LUA_OK) {
            std::cout << "Start Error: " << lua_tostring(L, -1) << "\n";
        }
    }
}

void ScriptHandler::LoadScriptsFromPool(ComponentPool<Script>& pool) {
    for(Entity ent = 0; ent < pool.pool.size(); ent++) {
        if(pool.has[ent]) {
            LoadScriptForEntity(ent, pool.pool[ent]);
        }
    }
}

void ScriptHandler::ExecUpdate(ComponentPool<Script>& pool, float dt) {
    for(Entity ent = 0; ent < (Entity)pool.pool.size(); ent++) {
        if(pool.has[ent]) {
            if( pool.pool[ent].updateRef == LUA_NOREF) continue;

            lua_pushinteger(L, ent);
            lua_setglobal(L, "this");

            lua_rawgeti(L, LUA_REGISTRYINDEX, pool.pool[ent].updateRef);
            lua_pushnumber(L, dt);
            if (lua_pcall(L, 1, 0, 0) != LUA_OK) {
                std::cout << "Update Error: " << lua_tostring(L, -1) << "\n";
                lua_pop(L, 1); // pop error
            }
        }
    }
}