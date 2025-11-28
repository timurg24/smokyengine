#pragma once
#include <raylib.h>
#include <pugixml.hpp>
#include <string>

#include "global.h"

using namespace std;


namespace API {
    // --- ENGINE --- //
    void Quit();
    int GetFPS();
    void Log(string text);

    // --- SCENE --- //
    void Load(string path);
    void Reload();

    // --- ENTITY --- //
    void Create(string name);
    // TODO: Add `AddComponent(nameOfComponent, {data})`
    bool Exist(string name);
    void Destroy(string name);
    // void SetName(string oldName, string newName);

    // --- TRANSFORM --- //
    void SetPosition(string name, float x, float y);
    void SetRotation(string name, float rotation);
    void SetWidth(string name, float width);
    void SetHeight(string name, float height);

    float GetPositionX(string name);
    float GetPositionY(string name);
    float GetRotation(string name);
    float GetWidth(string name);
    float GetHeight(string name);

    void TranslateX(string name, float mX);
    void TranslateY(string name, float mY);

    // --- SPRITE --- //
    void NewTexture(string name, string path);

    // --- CAMERA --- //
    void CamSetPosition(int x, int y);
    void CamSetZoom(float zoom);
    void CamRotation(float rotation);
    // TODO: void CamHelperFollow(string name);

    // --- INPUT --- //
    bool IsKeyDown(int key);
    bool IsKeyPressed(int key);
    bool IsKeyReleased(int key);

    bool IsMouseDown(int button);
    bool IsMousePressed(int button);
    bool IsMouseReleased(int button);
    bool IsMouseUp(int button);
    
    float GetMouseX();
    float GetMouseY();

    // --- AUDIO --- //
    void PlaySound(string path);
    void PlayMusic(string path);
    void StopMusic();
    void SetVolume();
}

