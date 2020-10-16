#include <algorithm>
#include <Engine/Logger.hpp>
#include "rendercomponent.h"

std::vector<RenderComponent*> RenderComponent::render_components;

void RenderComponent::init(GameObject *_gameobject)
{
    Component::init(_gameobject);
    render_components.push_back(this);
}

RenderComponent::~RenderComponent()
{
    auto id = std::find(render_components.begin(), render_components.end(), this);
    render_components.erase(id);
}
