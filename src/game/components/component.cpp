#include <vector>
#include "game/core/gamedata.h"
#include "component.h"
#include "Engine/Logger.hpp"

std::vector<Component*> all;

void Component::init(GameObject* _gameobject)
{
    gameobject = _gameobject;
    all.push_back(this);
}
