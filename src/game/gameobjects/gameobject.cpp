#include <game/components/transform.h>
#include <algorithm>
#include <vector>
#include <Engine/Logger.hpp>
#include "gameobject.h"

std::vector<GameObject*> GameObject::all_objects;

GameObject::GameObject()
{
    addComponent(new Transform);
    all_objects.push_back(this);
}

GameObject::~GameObject()
{
    static int i = 0;
    Logging::log("GameObject #"+ std::to_string(++i)+ "\n");

    for (auto component : components)
    {
        delete component;
    }

    ///I think the vector is resizing or reallocating memory and somehow causing a sig fault
    //auto id = std::find(all_objects.begin(), all_objects.end(), this);
    //all_objects.erase(id);
}

void GameObject::addComponent(Component *_component)
{
    _component->init(this);
    components.push_back(_component);
}

void GameObject::destroyAllObjects()
{
    for (auto o : all_objects)
    {
        delete o;
    }
    all_objects.clear();
}

void GameObject::destroyNonPersistentObjects()
{
    for (auto object : all_objects)
    {
        delete object;
    }
}