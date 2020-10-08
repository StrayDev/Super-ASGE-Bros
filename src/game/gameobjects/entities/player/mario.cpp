#include "mario.h"
#include "game/gameobjects/entities/entitystate.h"
#include "playeridle.h"

Mario::Mario(ASGE::Renderer *renderer)
{
    setState(new PlayerIdle(this));

    _sprite = renderer->createRawSprite();
    _sprite->loadTexture("/data/tileset/mario_sprites.png");

    _sprite->width(64);
    _sprite->height(64);

    _sprite->srcRect()[0] = 0;  //x
    _sprite->srcRect()[1] = 32; //y
    _sprite->srcRect()[2] = 16; //width
    _sprite->srcRect()[3] = 16; //height
}

void Mario::update(float delta_time)
{
    Entity::update(delta_time);
}
