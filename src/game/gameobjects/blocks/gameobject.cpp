#include "gameobject.h"

void GameObject::setPosition(float x, float y)
{
    _x = x;
    _y = y;
    _sprite->xPos(_x);
    _sprite->yPos(_y);
    _position = Vector2(_x, _y);
}

void GameObject::setPosition(Vector2 pos)
{
    setPosition(pos.x(), pos.y());
}

void GameObject::setSprite(ASGE::Renderer* renderer, std::string file_path)
{
    _width = (float)renderer->windowWidth() / 24;

    _sprite = renderer->createRawSprite();
    _sprite->loadTexture(file_path);
    _sprite->width(_width);
    _sprite->height(_width);
}

