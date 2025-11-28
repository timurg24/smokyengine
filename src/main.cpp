#include <iostream>
#include <raylib.h>

#include "Entity/Entity.h"
#include "Scene/Scene.hpp"

int main() {
    std::cout << GenerateID("TestObject");
    InitWindow(800,600,"SmokyEngine deV1.0.0");

    Scene sc;
    sc.LoadFromXML("level.xml");

    while(!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            sc.RenderSpritePool();
        EndDrawing();
    }
}
