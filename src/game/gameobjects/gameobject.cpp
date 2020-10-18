#include <game/components/transform.h>
#include <algorithm>
#include <vector>
#include <Engine/Logger.hpp>
#include <game/components/persistence.h>
#include "gameobject.h"

std::vector<GameObject*> GameObject::all_objects;

GameObject::GameObject()
{
    addComponent(new Transform);
    all_objects.push_back(this);

    static int i = 0;
    Logging::log("GameObject #"+ std::to_string(++i)+ " CREATED\n");
}

GameObject::~GameObject()
{
    static int i = 0;
    Logging::log("GameObject #"+ std::to_string(++i)+ " DESTROYED\n");

    for (int i = 0; i < components.size(); i++)
    {
        delete components[i];
    }

    all_objects.erase(std::remove(all_objects.begin(), all_objects.end(), this), all_objects.end());
}

void GameObject::addComponent(Component *_component)
{
    _component->init(this);
    components.push_back(_component);
}

void GameObject::destroyAllObjects()
{
    while(!all_objects.empty())
    {
        delete all_objects.back();
    }
}

void GameObject::destroyNonPersistentObjects()
{
    std::sort(all_objects.begin(), all_objects.end(), sortByPersistence);

    while (!all_objects.back()->getComponent<Persistence*>())
    {
        delete all_objects.back();
    }
}

bool GameObject::sortByPersistence(GameObject *obj1, GameObject *obj2)
{
    auto first = obj1->getComponent<Persistence*>() ? true : false;
    auto second = obj2->getComponent<Persistence*>() ? true : false;

    if (first && !second)
    {
        return true;
    }
    return false;
}

