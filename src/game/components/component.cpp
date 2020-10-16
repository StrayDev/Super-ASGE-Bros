#include <vector>
#include <algorithm>
#include "game/core/gamedata.h"
#include "component.h"
#include "Engine/Logger.hpp"

std::vector<Component*> Component::all_components;

Component::~Component()
{
    auto id = std::find(all_components.begin(), all_components.end(), this);
    all_components.erase(id);
}

void Component::init(GameObject* _gameobject)
{
    gameobject = _gameobject;
    all_components.push_back(this);
}


