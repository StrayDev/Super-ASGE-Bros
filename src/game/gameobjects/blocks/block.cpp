#include "block.h"

Block::Block(ASGE::Renderer *renderer, int block_id)
{
    _id = block_id;
    _sprite = renderer->createRawSprite();
    _sprite->loadTexture(selectTexture(block_id));
}

std::string Block::selectTexture(int id)
{
    switch (id)
    {
        case 1:
            return folder_path + "ground.png";
        case 2:
            return folder_path + "endblock.png";
        default:
            return folder_path + "ground.png";
    }
}

void Block::setSize(float size)
{
    _sprite->width(size);
    _sprite->height(size);
}
