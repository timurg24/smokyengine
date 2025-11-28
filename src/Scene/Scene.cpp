#include "Scene.hpp"
#include <raymath.h>
#include <raylib.h>
#include <iostream>

// ================================
//          Loading XML
// ================================

TransformComponent GetTransformData(pugi::xml_node node);
Sprite GetSpriteData(pugi::xml_node node);

void Scene::LoadFromXML(std::string filePath) {

    scenePath = filePath;

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
            TransformComponent data = GetTransformData(entity.child("Transform"));
            transformPool.Set(id, data);
        } else {
            std::cout << "ERROR: Entity \"" << entity.attribute("name").as_string() << "\" (ID " << id << ") does not have transform component!\n Please shutdown the game.\n";
            continue;
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
TransformComponent GetTransformData(pugi::xml_node node) {
    float x = node.attribute("x").as_float();
    float y = node.attribute("y").as_float();

    float rotation = node.attribute("rotation").as_float();
    
    float width = node.attribute("width").as_float();
    float height = node.attribute("height").as_float();

    // ! FIX THIS ERROR
    return {
        x,y,rotation,width,height
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

        // ? FIX THIS, SEGFAULT IF COMPONENT MISSES TRANSFORM
        // ^^ Is this error fixed now that there is a transform check during reading? Eliminating for the possibility to have a missing transform?
        if(!transformPool.has[ent] && spritePool.has[ent]) {
            // Entity does not have transform
            std::cout << "Entity #" << ent << " does not have a transform! Skipping!\n";
            continue;
        }

        TransformComponent position = transformPool.pool[ent];
        Sprite sprite =      spritePool.pool[ent];
        //DrawTexture(sprite.tex, position.translation.x, position.translation.y, WHITE);
    }
}