#include "spriterenderer.h"
#include <Engine/Logger.hpp>

void SpriteRenderer::init(GameObject *_gameobject)
{
    RenderComponent::init(_gameobject);
}

void SpriteRenderer::render(ASGE::Renderer *renderer)
{
    renderer->renderSprite(*sprite);
}

void SpriteRenderer::createSprite(ASGE::Renderer* renderer, std::string file_path)
{
    delete sprite;
    sprite = renderer->createRawSprite();
    if (sprite->loadTexture(file_path)) Logging::log(file_path + " loaded\n");


    ///set size from transform

}




