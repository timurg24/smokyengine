#include <iostream>
#include <raylib.h>

#include "Entity/Entity.h"
#include "Scene/Scene.hpp"

int main() {
    std::cout << GenerateID("TestObject");
    InitWindow(800,600,"Hello World!");

    Scene sc;
    sc.LoadFromXML("level.xml");

    while(!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(RAYWHITE);
        EndDrawing();
    }
}
