#include "rendercomponent.h"

std::vector<RenderComponent*> RenderComponent::render_components;

void RenderComponent::init(GameObject *_gameobject)
{
    Component::init(_gameobject);
    render_components.push_back(this);
}
