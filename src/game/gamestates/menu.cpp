#include <game/components/spriterenderer.h>
#include "menu.h"
#include "playing.h"
#include "game/components/Renderer.h"

Menu::~Menu()
{

}

void Menu::init(ASGE::Renderer* renderer)
{
    auto gameobject = new GameObject();
    auto sprite = new SpriteRenderer(gameobject);
    sprite->createSprite(renderer, "data/tileset/bricks.png");
    sprite->debug_SetSPriteScale(10);
    gameobject->addComponent(sprite);
}

void Menu::update(float delta_time)
{
    if (_game->input()->enter() == 0) return;
    _game->setState(new Playing(_game));
}





