#include <iostream>
#include <raylib.h>

#include "Entity/Entity.h"
#include "Scene/Scene.hpp"
#include "ScriptAPI/Native/ScriptAPI.h"
#include "global.h"

#include "Config.h"

int main() {

    // Config
    Config con;
    con.Load();

    std::cout << GenerateID("TestObject");
    InitWindow(800,600,con.gameName.c_str());

    currentScene = new Scene();
    currentScene->LoadFromXML(con.startScene);

    running = true;

    float dt;

    while(!WindowShouldClose() && running) {
        BeginDrawing();
                ClearBackground(GRAY);
                dt = GetFrameTime();
                currentScene->handler.ExecUpdate(currentScene->scriptPool, dt);
                currentScene->RenderSpritePool();
        EndDrawing();
    }

    return 0;
}
