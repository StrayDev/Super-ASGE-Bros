#include "transform.h"
#include "SpriteRenderer.h"
#include "Engine/Logger.hpp"

void Transform::init(GameObject *_gameobject)
{
    Component::init(_gameobject);
}

void Transform::setPosition(Vector2 pos)
{
    position = pos;
    auto component = gameobject->getComponent<SpriteRenderer*>();
    if (component)
    {
        component->setSpritePosition(pos);
    }
}
