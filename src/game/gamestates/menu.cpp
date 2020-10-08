#include <game/gameobjects/blocks/titlecard.h>
#include <game/gameobjects/blocks/tile.h>
#include "menu.h"
#include "playing.h"

Menu::~Menu()
{
    GameObjects.clear();
    TextObjects.clear();
    delete selection_icon;
}

void Menu::init(ASGE::Renderer* renderer)
{
    ///load level
    GameObjects.push_back(new TitleCard(renderer));

    for ( int i = 0; i < 25; i++)
    {
        for ( int j = 0; j < 2; j++)
        {
            auto tile = new Tile(renderer);
            auto x = i * tile->getWidth();
            auto y = renderer->windowHeight() - tile->getWidth() - j * tile->getWidth();

            tile->setPosition(x, y);
            GameObjects.push_back(tile);
        }
    }
    ///menu text
    TextObjects.push_back(new ASGE::Text(renderer->getDefaultFont(), " 1985 NINTENDO", 1030, 500));
    TextObjects.push_back(new ASGE::Text(renderer->getDefaultFont(), "o", 1000, 495));

    TextObjects.push_back(new ASGE::Text(renderer->getDefaultFont(), "MARIO", 200, 50 ));
    TextObjects.push_back(new ASGE::Text(renderer->getDefaultFont(), "WORLD", 1000, 50 ));
    TextObjects.push_back(new ASGE::Text(renderer->getDefaultFont(), "TIME", 1400, 50 ));

    TextObjects.push_back(new ASGE::Text(renderer->getDefaultFont(), "1 PLAYER GAME", 875, 700 ));
    TextObjects.push_back(new ASGE::Text(renderer->getDefaultFont(), "2 PLAYER GAME", 875, 750 ));

    for(auto t: TextObjects)
    {
        t->setScale(1.5);
    }
    TextObjects.push_back(new ASGE::Text(renderer->getDefaultFont(), "c", 1007, 490));

    ///menu shroom
    selection_icon = new GameObject();
    selection_icon->setSprite(renderer, "data/tileset/menushroom.png");
    selection_icon->getSprite()->width(30);
    selection_icon->getSprite()->height(30);
    selection_icon->setPosition(825, 675);
    GameObjects.push_back(selection_icon);
}

void Menu::update(float delta_time)
{
    if (_game->input()->enter() == 0) return;
    _game->setState(new Playing(_game));
}





