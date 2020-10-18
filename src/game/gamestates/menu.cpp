#include <game/components/spriterenderer.h>
#include <game/core/filesystem.h>
#include <Engine/Logger.hpp>

#include "game/factories/menuobjectfactory.h"
#include "playing.h"
#include "menu.h"

Menu::~Menu()
{
    GameObject::destroyNonPersistentObjects();
    Logging::log("GameState : MENU DESTROYED\n");
}

void Menu::init(ASGE::Renderer* renderer)
{
    //MenuObjectFactory::createMenuObjects(renderer);
    FileSystem::loadLevel("menu", renderer);
    BlockFactory::createTitleCard(); /// put in block factory
    //createMenuText(renderer);

    Logging::log("GameState : MENU INIT\n");
}

void Menu::update(float delta_time)
{
    if (_game->input()->enter() == 0) return;
    _game->setState(new Playing(_game));
}








