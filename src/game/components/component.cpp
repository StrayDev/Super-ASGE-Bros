#include <vector>
#include "game/core/gamedata.h"
#include "component.h"
#include "Engine/Logger.hpp"

std::vector<Component*> Component::all_components;

void Component::init(GameObject* _gameobject)
{
    gameobject = _gameobject;
    all_components.push_back(this);
}
