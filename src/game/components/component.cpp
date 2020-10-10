#include <vector>
#include "game/core/gamedata.h"
#include "component.h"
#include "Engine/Logger.hpp"

std::vector<Component*> all;

Component::Component(GameObject* _gameobject)
{
    init(_gameobject);
}

void Component::init(GameObject* _gameobject)
{
    Logging::log("Component init\n");
    gameobject = _gameobject;
    all.push_back(this);
}
