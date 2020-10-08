#include "titlecard.h"

TitleCard::TitleCard(ASGE::Renderer* renderer)
{
    auto width = renderer->windowWidth();
    auto scale = 4;

    _sprite = renderer->createRawSprite();
    _sprite->loadTexture(filePath);
    _sprite->width(_sprite->width() * scale);
    _sprite->height(_sprite->height() * scale);
    _sprite->xPos(width / 2 - _sprite->width() / 2);
    _sprite->yPos(100);
}
