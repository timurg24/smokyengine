#include "ScriptAPI.h"
#include "Entity/Entity.h"
#include <iostream>

#include "Scene/Scene.hpp" 
using namespace std;

namespace NATIVE {

    // --- ENGINE --- //
    void Quit() {
       running = false;
    }

    int GetFPS() {
        return ::GetFPS(); // this rivals rust in terms of code readability
    }

    void Log(string text) {
        cout << text << "\n";
    }

    // --- SCENE --- //
    void Load(string path) {
        currentScene->LoadFromXML(path);
    }

    void Reload() {
        currentScene->LoadFromXML(currentScene->scenePath);
    }

    // --- ENTITY --- //
    void Create(Entity id) {
        // Honestly, since you can't create a new entity without having any data attached to it in ECS, this funcion is meaningless.
        // I am only keeping it here for better code readability for the game developers.
        // Do not tell anyone.
    }

    bool Exist(Entity id) {
        // Do I check the transform pool? I will for now.
        return currentScene->transformPool.has[id];
    }

    void Destroy(Entity id) {
        
        // TODO: Properly delete entries, this is just me being lazy at 11 pm
        currentScene->transformPool.pool[id] = {};

        if(currentScene->spritePool.has[id]) {
            currentScene->spritePool.pool[id] = {};
        }

        if(currentScene->scriptPool.has[id]) {
            currentScene->scriptPool.pool[id] = {};
        }
    }

    // void SetName(string oldName, string newName) {
    //     // ! FIX THIS -> ECS states that IDs should not change, do I need have to a display id and engine id for entities?
    //     Entity oldID = GenerateID(oldName);
    //     Entity newID = GenerateID(newName);

    //     Transform& oldTransform = currentScene->transformPool.pool[oldID];
    //     currentScene->transformPool.pool[newID] = oldTransform;
    //     currentScene->transformPool.pool[oldID] = {};
        

    //     if(currentScene->spritePool.has[oldID]) {
    //         Sprite& oldSprite = currentScene->spritePool.pool[oldID];
    //         currentScene-> spritePool.pool[newID] = oldSprite;
    //         currentScene->spritePool.pool[oldID] = {};
    //     }

    //     if(currentScene->scriptPool.has[oldID]) {
    //         Script& oldScript = currentScene->scriptPool.pool[oldID];
    //         currentScene-> scriptPool.pool[newID] = oldScript;
    //         currentScene->scriptPool.pool[oldID] = {};
    //     }

    //     Destroy(oldName);
    // }

    // // --- TRANSFORM --- //
    void SetPosition(Entity id, float x, float y) {
        currentScene->transformPool.pool[id].x = x;
        currentScene->transformPool.pool[id].y = y;
    }

    void SetRotation(Entity id, float rotation) {
        
        currentScene->transformPool.pool[id].rotation = rotation;
    }

    void SetWidth(Entity id, float width) {
        
        currentScene->transformPool.pool[id].width = width;
    }

    void SetHeight(Entity id, float height) {
        
        currentScene->transformPool.pool[id].height = height;
    }

    float GetPositionX(Entity id) {
        
        return currentScene->transformPool.pool[id].x;
    }

    float GetPositionY(Entity id) {
        
        return currentScene->transformPool.pool[id].y;
    }

    float GetRotation(Entity id) {
        
        return currentScene->transformPool.pool[id].rotation;
    }

    float GetWidth(Entity id) {
        
        return currentScene->transformPool.pool[id].width;
    }

    float GetHeight(Entity id) {
        
        return currentScene->transformPool.pool[id].height;
    }

    void TranslateX(Entity id, float mX) {
        
        currentScene->transformPool.pool[id].x += mX;
    }

    void TranslateY(Entity id, float mY) {
        
        currentScene->transformPool.pool[id].y += mY;
    }

    // --- SPRITE --- //
    void NewTexture(Entity id, string path) {
        
        currentScene->spritePool.pool[id].tex = LoadTexture(path.c_str());
    }

    // // --- CAMERA --- //
    // void CamSetPosition(int x, int y) {
    // }

    // void CamSetZoom(float zoom) {
    // }

    // void CamRotation(float rotation) {
    // }

    // --- INPUT --- //
    bool IsKeyDown(int key) {
        return ::IsKeyDown(key);
    }

    bool IsKeyPressed(int key) {
        return ::IsKeyPressed(key);
    }

    bool IsKeyReleased(int key) {
        return ::IsKeyReleased(key);
    }

    bool IsMouseDown(int button) {
        return ::IsMouseButtonDown(button);
    }

    bool IsMousePressed(int button) {
        return ::IsMouseButtonPressed(button);
    }

    bool IsMouseReleased(int button) {
        return ::IsMouseButtonReleased(button);
    }

    bool IsMouseUp(int button) {
        return ::IsMouseButtonUp(button);
    }

    float GetMouseX() {
        return (float)::GetMouseX();
    }

    float GetMouseY() {
        return (float)::GetMouseY();
    }

    // // --- AUDIO --- //
    // void PlaySound(string path) {
    // }

    // void PlayMusic(string path) {
    // }

    // void StopMusic() {
    // }

    // void SetVolume() {
    // }
}
