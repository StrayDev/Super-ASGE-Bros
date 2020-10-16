#include <Engine/Logger.hpp>
#include "blockfactory.h"

GameObject *BlockFactory::createBlock(int i)
{
    auto obj = new GameObject();
    auto sprite = new SpriteRenderer();
    sprite->createSprite(renderer, "data/sprites/atlas11.png");
    obj->addComponent(sprite);

    auto block_size = 64;

    switch (i)
    {
        case 1: // ground
        {
            sprite->setAtlasCoordinates(0, 0, block_size, block_size);
            return obj;
        }
        case 2: //brick-top
        {
            sprite->setAtlasCoordinates(block_size, 0, block_size, block_size);
            return obj;
        }
        case 9:
        {
            sprite->setAtlasCoordinates(0, block_size, block_size, block_size);
            return obj;
        }
        case 10:
        {
            sprite->setAtlasCoordinates(block_size, block_size, block_size, block_size);
            return obj;
        }
        case 11: // mario
        {
            sprite->setAtlasCoordinates(block_size*8, 0, block_size, block_size);
            return obj;
        }
        case 18:
        {
            sprite->setAtlasCoordinates( 0, block_size*2, block_size, block_size);
            return obj;
        }
        case 19:
        {
            sprite->setAtlasCoordinates( block_size, block_size*2, block_size, block_size);
            return obj;
        }
        case 20:
        {
            sprite->setAtlasCoordinates( block_size*2, block_size*2, block_size, block_size);
            return obj;
        }
        case 26:
        {
            sprite->setAtlasCoordinates( 0, block_size*3, block_size, block_size);
            return obj;
        }
        case 27:
        {
            sprite->setAtlasCoordinates( block_size, block_size*3, block_size, block_size);
            return obj;
        }
        case 28:
        {
            sprite->setAtlasCoordinates( block_size*2, block_size*3, block_size, block_size);
            return obj;
        }
        default:
        {
            Logging::log("Unable to build Block of id: " + std::to_string(i));
            return nullptr;
        }
    }
}

void BlockFactory::createTitleCard()
{
    auto obj = new GameObject();
    auto sprite = new SpriteRenderer();
    obj->addComponent(sprite);
    sprite->createSprite(renderer, "data/sprites/asgebros.png");
    sprite->setSpriteSize(Vector2(640*1.5, 352*1.5));
    sprite->setSpritePosition(Vector2(540, 85));
}
