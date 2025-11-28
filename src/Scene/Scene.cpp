#include "Scene.hpp"
#include <raymath.h>
#include <raylib.h>
#include <iostream>

// ================================
//          Loading XML
// ================================

Transform GetTransformData(pugi::xml_node node);
Sprite GetSpriteData(pugi::xml_node node);

void Scene::LoadFromXML(std::string filePath) {
    // --- Loading Level XML --- //
    pugi::xml_document doc;
    result = doc.load_file(filePath.c_str());

    if (!result) {
        std::cout << "XML load FAILED: " << result.description() << "\n";
        return;
    }

    // --- Get the entity data --- //
    pugi::xml_node sceneRoot = doc.child("Scene");

    if (!sceneRoot) {
        std::cout << "No <Scene> root found\n";
        return;
    }

    for(pugi::xml_node entity : sceneRoot.children("Entity")) {
        Entity id = GenerateID(entity.attribute("name").as_string());

        std::cout << "Retrieving data from Entity #" << id << "\n";

        /// -- Getting Transform data -- ///
        if(entity.child("Transform")) {
            Transform data = GetTransformData(entity.child("Transform"));
            transformPool.Set(id, data);
        }

        /// -- Getting Sprite data -- ///
        if(entity.child("Sprite")) {
            Sprite data = GetSpriteData(entity.child("Sprite"));
            spritePool.Set(id, data);
        }

        /// -- Getting Script Data -- ///
        if(entity.child("Script")) {

        }
    }
}

// --- Suck the transform data out of the node --- //
Transform GetTransformData(pugi::xml_node node) {
    float x = node.attribute("x").as_float();
    float y = node.attribute("y").as_float();

    float rotation = node.attribute("rotation").as_float();
    
    float width = node.attribute("width").as_float();
    float height = node.attribute("height").as_float();

    return {
        {x,y,1.0f},
        QuaternionFromAxisAngle(
            (Vector3){0,0,1}, 
            rotation*DEG2RAD
        ),
        {width,height,1.0f}
    };

}

// --- Loading textures into the sprite component --- //
Sprite GetSpriteData(pugi::xml_node node) {
    return { LoadTexture(node.attribute("path").as_string()) };
}


// ================================
//           Rendering
// ================================

void Scene::RenderSpritePool() {
    for(Entity ent = 0; ent < spritePool.pool.size(); ent++) {

        // ! FIX THIS, SEGFAULT IF COMPONENT MISSES TRANSFORM
        if(!transformPool.has[ent] && spritePool.has[ent]) {
            // Entity does not have transform
            std::cout << "Entity #" << ent << " does not have a transform! Skipping!\n";
            continue;
        }

        Transform position = transformPool.pool[ent];
        Sprite sprite =      spritePool.pool[ent];
        DrawTexture(sprite.tex, position.translation.x, position.translation.y, WHITE);
    }
}