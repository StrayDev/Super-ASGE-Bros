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
    if (!sprite->loadTexture(file_path)) Logging::log(file_path + " not loaded\n");
}

void SpriteRenderer::setAtlasCoordinates(int x, int y, int width, int height)
{
    sprite->srcRect()[0] = x;
    sprite->srcRect()[1] = y;
    sprite->srcRect()[2] = width;
    sprite->srcRect()[3] = height;
}




