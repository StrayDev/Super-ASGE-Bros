#pragma once

#include <game/components/component.h>

class GameData
{
public:
    static std::vector<Component*> all_components;
    static std::vector<Component*> renderable_components;
    static std::vector<Component*> updatable_components;

};


