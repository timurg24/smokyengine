#pragma once
#include "Components/ComponentPool.h"

#include "Components/Script.h"
#include "Components/Sprite.h"
#include "Components/Transform.h"

#include <pugixml.hpp>

class Scene {
private:
    pugi::xml_parse_result result;
public:

    ComponentPool<Script> scriptPool;
    ComponentPool<Sprite> spritePool;
    ComponentPool<TransformComponent> transformPool;

    std::string scenePath;

    void LoadFromXML(std::string filePath);

    void RenderSpritePool();
};