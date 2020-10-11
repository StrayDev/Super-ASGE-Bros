#pragma once

#include <vector>
#include <game/gameobjects/gameobject.h>

class Component
{
public:
    Component() = default;
    virtual ~Component() = default;

    virtual void init(GameObject* _gameobject);

    ///get all components

protected:
    GameObject* gameobject = nullptr;
    static std::vector<Component*> all_components;

};


