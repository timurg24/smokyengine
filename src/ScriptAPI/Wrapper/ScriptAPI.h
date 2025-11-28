#pragma once
#include <lua.hpp>
#include <raylib.h>
#include <string>

#include "global.h"

#include "ScriptAPI/Native/ScriptAPI.h" // native functions

namespace WRAPPER
{
    // --- ENGINE --- //
    int Quit(lua_State* L);        // Quit()
    int GetFPS(lua_State* L);      // GetFPS() -> number
    int Log(lua_State* L);         // Log(text)

    // --- SCENE --- //
    int Load(lua_State* L);        // Load(path)
    int Reload(lua_State* L);      // Reload()

    // --- ENTITY --- //
    int Create(lua_State* L);      // Create(name)
    int Exist(lua_State* L);       // Exist(name) -> bool
    int Destroy(lua_State* L);     // Destroy(name)
    // int SetName(lua_State* L);   // optional

    // --- TRANSFORM --- //
    int SetPosition(lua_State* L); // SetPosition(name, x, y)
    int SetRotation(lua_State* L); // SetRotation(name, rotation)
    int SetWidth(lua_State* L);    // SetWidth(name, width)
    int SetHeight(lua_State* L);   // SetHeight(name, height)

    int GetPositionX(lua_State* L); // GetPositionX(name) -> number
    int GetPositionY(lua_State* L); // GetPositionY(name) -> number
    int GetRotation(lua_State* L);  // GetRotation(name)  -> number
    int GetWidth(lua_State* L);     // GetWidth(name)     -> number
    int GetHeight(lua_State* L);    // GetHeight(name)    -> number

    int TranslateX(lua_State* L);   // TranslateX(name, dx)
    int TranslateY(lua_State* L);   // TranslateY(name, dy)

    // --- SPRITE --- //
    int NewTexture(lua_State* L);   // NewTexture(name, path)

    // --- CAMERA --- //
    int CamSetPosition(lua_State* L); // CamSetPosition(x, y)
    int CamSetZoom(lua_State* L);     // CamSetZoom(zoom)
    int CamRotation(lua_State* L);    // CamRotation(rotation)

    // --- INPUT --- //
    int IsKeyDown(lua_State* L);      // IsKeyDown(key)      -> bool
    int IsKeyPressed(lua_State* L);   // IsKeyPressed(key)   -> bool
    int IsKeyReleased(lua_State* L);  // IsKeyReleased(key)  -> bool

    int IsMouseDown(lua_State* L);     // IsMouseDown(button)    -> bool
    int IsMousePressed(lua_State* L);  // IsMousePressed(button) -> bool
    int IsMouseReleased(lua_State* L); // IsMouseReleased(button)-> bool
    int IsMouseUp(lua_State* L);       // IsMouseUp(button)      -> bool

    int GetMouseX(lua_State* L);       // GetMouseX() -> number
    int GetMouseY(lua_State* L);       // GetMouseY() -> number

    // --- AUDIO --- //
    int PlaySound(lua_State* L);       // PlaySound(path)
    int PlayMusic(lua_State* L);       // PlayMusic(path)
    int StopMusic(lua_State* L);       // StopMusic()
    int SetVolume(lua_State* L);       // SetVolume(value)
}
