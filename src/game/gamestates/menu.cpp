#include <game/components/spriterenderer.h>
#include <game/core/filesystem.h>
#include <Engine/Logger.hpp>
#include <game/components/textrenderer.h>
#include "menu.h"
#include "playing.h"

Menu::~Menu()
{
    Logging::log("Menu Destructor\n");
    //GameObject::destroyAllObjects();
    GameObject::destroyNonPersistentObjects();

    Logging::log("objects destroyed\n");

    std::string a = GameObject::getAllObjects().empty() ? "true\n" : "false\n";
    Logging::log("Object Array Empty : " + a );
    std::string b = RenderComponent::getRenderComponents().empty() ? "true\n" : "false\n";
    Logging::log("Render Array Empty : " + b );
    std::string c = Component::getAllComponents().empty() ? "true\n" : "false\n";
    Logging::log("Component Array Empty : " + c );

    Logging::log("GameState : MENU DESTROYED\n");
}

void Menu::init(ASGE::Renderer* renderer)
{
    FileSystem::loadLevel("menu", renderer);
    BlockFactory::createTitleCard();
    createMenuText(renderer);
    Logging::log("GameState : MENU INIT\n");
}

void Menu::update(float delta_time)
{
    if (_game->input()->enter() == 0) return;
    _game->setState(new Playing(_game));

}

void Menu::createMenuText(ASGE::Renderer* renderer)
{
    std::string string;
    Vector2 position;
    auto screen_width = ASGE::SETTINGS.window_width;
    auto screen_height = ASGE::SETTINGS.window_height;

    for (int i = 0; i < 4; i++)
    {
        switch(i)
        {
            case 0:
            {
                string = "C1985 NINTENDO";
                position = Vector2(screen_width/2 + 290, screen_height - screen_height/2.5);

                break;
            }
            case 1:
            {
                string = "1 PLAYER GAME";
                position = Vector2(screen_width/2, screen_height - screen_height/3.3);
                break;
            }
            case 2:
            {
                string = "2 PLAYER GAME";
                position = Vector2(screen_width/2, screen_height - screen_height/4.4);
                break;
            }
            case 3:
            {
                string = "TOP- 000000"; // will need to get score
                position = Vector2(screen_width/2, screen_height - screen_height/6.5);
                break;
            }
        }

        auto obj = new GameObject();
        auto ren = new TextRenderer();
        obj->addComponent(ren);
        ren->createText(renderer, string, .91f);
        position = Vector2(position.x() - ren->getWidthOffset(), position.y());
        obj->getComponent<Transform*>()->setPosition(position);
    }
}





