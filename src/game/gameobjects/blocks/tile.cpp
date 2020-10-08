#include "tile.h"

Tile::Tile(ASGE::Renderer* renderer)
{
    _width = (float)renderer->windowHeight() / 16;
    //_height = _width;

    _sprite = renderer->createRawSprite();
    _sprite->loadTexture(filePath);
    _sprite->width(_width);
    _sprite->height(_width);

}
