#include "ScriptAPI.h"
#include <lua.hpp>


// ALL OF THE DEFINITIONS WERE WRITTEN BY HUMANS!
namespace WRAPPER
{
    // --- ENGINE --- //
    int Quit(lua_State* L)
    {
        NATIVE::Quit();
        return 0;
    }

    int GetFPS(lua_State* L)
    {
        lua_pushnumber(L, NATIVE::GetFPS());
        return 1;
    }

    int Log(lua_State* L)
    {
        const char* text = lua_tostring(L, -1); // get the first (and only) parameter
        NATIVE::Log(text);
        return 0;
    }

    // --- SCENE --- //
    int Load(lua_State* L)
    {
        const char* path = lua_tostring(L, -1);
        NATIVE::Load(path);
        return 0;
    }

    int Reload(lua_State* L)
    {
        NATIVE::Reload();
        return 0;
    }

    // --- ENTITY --- //
    int Create(lua_State* L)
    {
        return 0;
    }

    int Exist(lua_State* L)
    {
        Entity id = lua_tonumber(L, -1);
        lua_pushboolean(L, NATIVE::Exist(id));
        return 1;
    }

    int Destroy(lua_State* L)
    {   
        Entity id = lua_tonumber(L, -1);
        NATIVE::Destroy(id);
        return 0;
    }

    // --- TRANSFORM --- //
    int SetPosition(lua_State* L)
    {
        // id, x, y
        Entity id = lua_tonumber(L, -3);
        lua_Number x = lua_tonumber(L, -2);
        lua_Number y = lua_tonumber(L, -1);
        NATIVE::SetPosition(id, x, y);
        return 0;
    }

    int SetRotation(lua_State* L)
    {
        Entity id = lua_tonumber(L, -2);
        float rotation = (float)lua_tonumber(L, -1);
        NATIVE::SetRotation(id, rotation);
        return 0;
    }

    int SetWidth(lua_State* L)
    {
        Entity id = lua_tonumber(L, -2);
        lua_Number width = lua_tonumber(L, -1);
        NATIVE::SetWidth(id, width);
        return 0;
    }

    int SetHeight(lua_State* L)
    {
        Entity id = lua_tonumber(L, -2);
        lua_Number height = lua_tonumber(L, -1);
        NATIVE::SetHeight(id, height);
        return 0;
    }

    int GetPositionX(lua_State* L)
    {
        Entity id = lua_tonumber(L, -1);
        lua_pushnumber(L, (int)NATIVE::GetPositionX(id));
        return 1;
    }

    int GetPositionY(lua_State* L)
    {
        Entity id = lua_tonumber(L, -1);
        lua_pushnumber(L, (int)NATIVE::GetPositionY(id));
        return 1;
    }

    int GetRotation(lua_State* L)
    {
        Entity id = lua_tonumber(L, -1);
        lua_pushnumber(L, (int)NATIVE::GetRotation(id));
        return 1;
    }

    int GetWidth(lua_State* L)
    {
        Entity id = lua_tonumber(L, -1);
        lua_pushnumber(L, (int)NATIVE::GetWidth(id));
        return 1;
    }

    int GetHeight(lua_State* L)
    {
        Entity id = lua_tonumber(L, -1);
        lua_pushnumber(L, (int)NATIVE::GetHeight(id)); // ignore?
        return 1;
    }

    int TranslateX(lua_State* L)
    {
        Entity id = lua_tonumber(L, -2);
        lua_Number mX = lua_tonumber(L, -1);
        NATIVE::TranslateX(id, mX);
        return 0;
    }

    int TranslateY(lua_State* L)
    {
        Entity id = lua_tonumber(L, -2);
        lua_Number mY = lua_tonumber(L, -1);
        NATIVE::TranslateY(id, mY);
        return 0;
    }

    // --- SPRITE --- //
    int NewTexture(lua_State* L)
    {
        Entity id = lua_tonumber(L, -2);
        const char* path = lua_tostring(L, -1);
        NATIVE::NewTexture(id, path);
        return 0;
    }

    // --- CAMERA --- //
    int CamSetPosition(lua_State* L)
    {
        return 0;
    }

    int CamSetZoom(lua_State* L)
    {
        return 0;
    }

    int CamRotation(lua_State* L)
    {
        return 0;
    }

    // --- INPUT --- //
    int IsKeyDown(lua_State* L)
    {
        lua_Number key = lua_tonumber(L, -1);
        lua_pushboolean(L, NATIVE::IsKeyDown(key));
        return 1;
    }

    int IsKeyPressed(lua_State* L)
    {
        lua_Number key = lua_tonumber(L, -1);
        lua_pushboolean(L, NATIVE::IsKeyPressed(key));
        return 1;
    }

    int IsKeyReleased(lua_State* L)
    {
        lua_Number key = lua_tonumber(L, -1);
        lua_pushboolean(L, NATIVE::IsKeyReleased(key));
        return 1;
    }

    int IsMouseDown(lua_State* L)
    {
        lua_Number key = lua_tonumber(L, -1);
        lua_pushboolean(L, NATIVE::IsMouseDown(key));
        return 1;
    }

    int IsMousePressed(lua_State* L)
    {
        lua_Number key = lua_tonumber(L, -1);
        lua_pushboolean(L, NATIVE::IsMousePressed(key));
        return 1;
    }

    int IsMouseReleased(lua_State* L)
    {
        lua_Number key = lua_tonumber(L, -1);
        lua_pushboolean(L, NATIVE::IsMouseReleased(key));
        return 1;
    }

    int IsMouseUp(lua_State* L)
    {
        lua_Number key = lua_tonumber(L, -1);
        lua_pushboolean(L, NATIVE::IsMouseUp(key));
        return 1;
    }

    int GetMouseX(lua_State* L)
    {
        lua_pushnumber(L, NATIVE::GetMouseX());
        return 1;
    }

    int GetMouseY(lua_State* L)
    {
        lua_pushnumber(L, NATIVE::GetMouseY());
        return 1;
    }

    // --- AUDIO --- //
    int PlaySound(lua_State* L)
    {
        return 0;
    }

    int PlayMusic(lua_State* L)
    {
        return 0;
    }

    int StopMusic(lua_State* L)
    {
        return 0;
    }

    int SetVolume(lua_State* L)
    {
        return 0;
    }
}
