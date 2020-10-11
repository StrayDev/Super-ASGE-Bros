#include "Renderer.h"
#include "Engine/Logger.hpp"

std::vector<Renderer*> Renderer::render_components;

void Renderer::init(GameObject *_gameobject)
{
    Component::init(_gameobject);
    render_components.push_back(this);
}
