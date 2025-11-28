#pragma once
#include "Components/ComponentPool.h"

#include "Components/Script.h"
#include "Components/Sprite.h"
#include "Components/Transform.h" // Not needed, just kept here to remind you of the transform component

#include <pugixml.hpp>

class Scene {
private:
    pugi::xml_parse_result result;
public:

    ComponentPool<Script> scriptPool;
    ComponentPool<Sprite> spritePool;
    ComponentPool<Transform> transformPool;

    void LoadFromXML(std::string filePath);

    void RenderSpritePool();
};