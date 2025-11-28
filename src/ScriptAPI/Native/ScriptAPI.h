#pragma once
#include <raylib.h>
#include <pugixml.hpp>
#include <string>

#include "global.h"

using namespace std;


namespace NATIVE {
    // --- ENGINE --- //
    void Quit();
    int GetFPS();
    void Log(string text);

    // --- SCENE --- //
    void Load(string path);
    void Reload();

    // --- ENTITY --- //
    void Create(Entity id);
    // TODO: Add `AddComponent(nameOfComponent, {data})`
    bool Exist(Entity id);
    void Destroy(Entity id);
    // void SetName(string oldName, string newName);

    // --- TRANSFORM --- //
    void SetPosition(Entity id, float x, float y);
    void SetRotation(Entity id, float rotation);
    void SetWidth(Entity id, float width);
    void SetHeight(Entity id, float height);

    float GetPositionX(Entity id);
    float GetPositionY(Entity ide);
    float GetRotation(Entity id);
    float GetWidth(Entity id);
    float GetHeight(string name);

    void TranslateX(Entity id, float mX);
    void TranslateY(Entity id, float mY);

    // --- SPRITE --- //
    void NewTexture(Entity id, string path);

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

