#pragma once

#include <vector>
#include <game/gameobjects/gameobject.h>

class Component
{
public:
    explicit Component(GameObject* _gameobject);
    virtual ~Component() = default;

    virtual void init(GameObject* _gameobject);

    ///get all components

protected:
    GameObject* gameobject = nullptr;
    static std::vector<Component*> all_components;

};


