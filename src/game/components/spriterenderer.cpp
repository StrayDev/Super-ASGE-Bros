#include "spriterenderer.h"
#include <Engine/Logger.hpp>

void SpriteRenderer::init(GameObject *_gameobject)
{
    Renderer::init(_gameobject);
    ///working but code is a mess - git before you dp anything else
}

void SpriteRenderer::render(ASGE::Renderer *renderer)
{
    Logging::log("rendered");
}

void SpriteRenderer::createSprite(ASGE::Renderer* renderer, std::string file_path)
{
    delete sprite;
    sprite = renderer->createRawSprite();
    if (sprite->loadTexture(file_path)) Logging::log(file_path + " loaded\n");


    ///set size from transform

}

SpriteRenderer::SpriteRenderer(GameObject* _gameobject) : Renderer(_gameobject)
{
    init(_gameobject);
}


