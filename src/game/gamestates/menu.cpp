#include <game/components/spriterenderer.h>
#include <game/core/filesystem.h>
#include <Engine/Logger.hpp>
#include "menu.h"
#include "playing.h"
#include "game/components/RenderComponent.h"

Menu::~Menu()
{

}

void Menu::init(ASGE::Renderer* renderer)
{
    FileSystem::loadLevel("menu", renderer);
    BlockFactory::createTitleCard();
    //add static mario

    auto width = ASGE::SETTINGS.window_width;
    Logging::log("\n" + std::to_string(width));
}

void Menu::update(float delta_time)
{
    if (_game->input()->enter() == 0) return;
    _game->setState(new Playing(_game));
}





