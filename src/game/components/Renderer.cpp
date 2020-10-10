#include "Renderer.h"
#include "Engine/Logger.hpp"

std::vector<Renderer*> Renderer::render_components;

void Renderer::init(GameObject *_gameobject)
{
    Logging::log("Renderer init");
    render_components.push_back(this);
    Component::init(_gameobject);
}
