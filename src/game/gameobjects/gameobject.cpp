#include <game/components/transform.h>
#include "gameobject.h"

GameObject::GameObject()
{
    addComponent(new Transform);
}

void GameObject::addComponent(Component *_component)
{
    _component->init(this);
    components.push_back(_component);
}


