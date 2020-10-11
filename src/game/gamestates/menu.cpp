#include <game/components/spriterenderer.h>
#include <game/core/savesystem.h>
#include "menu.h"
#include "playing.h"
#include "game/components/Renderer.h"

Menu::~Menu()
{

}

void Menu::init(ASGE::Renderer* renderer)
{
    FileSystem::loadLevel("menu", renderer);
}

void Menu::update(float delta_time)
{
    if (_game->input()->enter() == 0) return;
    _game->setState(new Playing(_game));
}





