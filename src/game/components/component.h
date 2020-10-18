#pragma once

#include <vector>
#include <game/gameobjects/gameobject.h>

class Component
{
public:
    Component();
    virtual ~Component();

    virtual void init(GameObject* _gameobject);

    static std::vector<Component*> getAllComponents() { return all_components; }

protected:
    GameObject* gameobject = nullptr;
    static std::vector<Component*> all_components;

};


