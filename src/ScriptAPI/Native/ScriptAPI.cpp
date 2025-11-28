#include "ScriptAPI.h"
#include "Entity/Entity.h"
#include <iostream>

using namespace std;

namespace API {

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
    void Create(string name) {
        // Honestly, since you can't create a new entity without having any data attached to it in ECS, this funcion is meaningless.
        // I am only keeping it here for better code readability for the game developers.
        // Do not tell anyone.
    }

    bool Exist(string name) {
        // Do I check the transform pool? I will for now.
        return currentScene->transformPool.has[GenerateID(name)];
    }

    void Destroy(string name) {
        Entity id = GenerateID(name);
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
    //     // ! FIX THIS -> ECS states that IDs should not change, do I need have to a display name and engine name for entities?
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
    // void SetPosition(string name, float x, float y) {
    // }

    void SetRotation(string name, float rotation) {
        Entity id = GenerateID(name);
        currentScene->transformPool.pool[id].rotation = rotation;
    }

    void SetWidth(string name, float width) {
        Entity id = GenerateID(name);
        currentScene->transformPool.pool[id].width = width;
    }

    void SetHeight(string name, float height) {
        Entity id = GenerateID(name);
        currentScene->transformPool.pool[id].height = height;
    }

    float GetPositionX(string name) {
        Entity id = GenerateID(name);
        return currentScene->transformPool.pool[id].x;
    }

    float GetPositionY(string name) {
        Entity id = GenerateID(name);
        return currentScene->transformPool.pool[id].y;
    }

    float GetRotation(string name) {
        Entity id = GenerateID(name);
        return currentScene->transformPool.pool[id].rotation;
    }

    float GetWidth(string name) {
        Entity id = GenerateID(name);
        return currentScene->transformPool.pool[id].width;
    }

    float GetHeight(string name) {
        Entity id = GenerateID(name);
        return currentScene->transformPool.pool[id].height;
    }

    void TranslateX(string name, float mX) {
        Entity id = GenerateID(name);
        currentScene->transformPool.pool[id].x += mX;
    }

    void TranslateY(string name, float mY) {
        Entity id = GenerateID(name);
        currentScene->transformPool.pool[id].y += mY;
    }

    // --- SPRITE --- //
    void NewTexture(string name, string path) {
        Entity id = GenerateID(name);
        currentScene->spritePool.pool[id].tex = LoadTexture(path.c_str());
    }

    // --- CAMERA --- //
    void CamSetPosition(int x, int y) {
    }

    void CamSetZoom(float zoom) {
    }

    void CamRotation(float rotation) {
    }

    // --- INPUT --- //
    bool IsKeyDown(int key) {
        return false;
    }

    bool IsKeyPressed(int key) {
        return false;
    }

    bool IsKeyReleased(int key) {
        return false;
    }

    bool IsMouseDown(int button) {
        return false;
    }

    bool IsMousePressed(int button) {
        return false;
    }

    bool IsMouseReleased(int button) {
        return false;
    }

    bool IsMouseUp(int button) {
        return false;
    }

    float GetMouseX() {
        return 0.0f;
    }

    float GetMouseY() {
        return 0.0f;
    }

    // --- AUDIO --- //
    void PlaySound(string path) {
    }

    void PlayMusic(string path) {
    }

    void StopMusic() {
    }

    void SetVolume() {
    }
}
