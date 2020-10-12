#include <Engine/Logger.hpp>
#include "blockfactory.h"

GameObject *BlockFactory::createBlock(int i)
{
    auto obj = new GameObject();
    auto sprite = new SpriteRenderer();
    sprite->createSprite(renderer, "data/sprites/ground.png"); ///needs to be block atlas
    obj->addComponent(sprite);

    switch (i)
    {
        case 1: /// ground block
        {

            return obj;
        }
        default:
        {
            Logging::log("Unable to build Block of id: " + std::to_string(i));
            return nullptr;
        }
    }
}
