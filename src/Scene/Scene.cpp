#include "Scene.hpp"
#include <raymath.h>


Transform GetTransformData(pugi::xml_node node);

void Scene::LoadFromXML(std::string filePath) {
    // --- Loading Level XML --- //
    pugi::xml_document doc;
    result = doc.load_file(filePath.c_str());


    // --- Get the entity data --- //
    pugi::xml_node sceneRoot = doc.child("Scene");

    for(pugi::xml_node entity : sceneRoot) {
        Entity id = GenerateID(entity.attribute("name").as_string());

        std::cout << "Retrieving data from Entity #" << id << "\n";

        /// -- Checking if Transform exists -- ///
        if(entity.child("Transform")) {
            Transform data = GetTransformData(entity.child("Transform"));
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
        {x,y,0},
        QuaternionFromAxisAngle(
            (Vector3){0,0,1}, 
            rotation*DEG2RAD
        ),
        {width,height,0.0f}
    };

}