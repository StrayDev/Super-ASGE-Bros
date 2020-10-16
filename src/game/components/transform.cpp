#include "transform.h"
#include "SpriteRenderer.h"
#include "Engine/Logger.hpp"
#include "textrenderer.h"

void Transform::init(GameObject *_gameobject)
{
    Component::init(_gameobject);
}

void Transform::setPosition(Vector2 pos)
{
    position = pos;
    RenderComponent* component = gameobject->getComponent<RenderComponent*>();
    if (dynamic_cast<SpriteRenderer*>(component))
    {
        reinterpret_cast<SpriteRenderer*>(component)->setSpritePosition(position);
        return;
    }
    else if (dynamic_cast<TextRenderer*>(component))
    {
        reinterpret_cast<TextRenderer*>(component)->setTextPosition(position);
        return;
    }

    Logging::log("Unable to move position of render object\n");
}
