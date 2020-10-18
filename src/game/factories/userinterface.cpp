#include <game/gameobjects/gameobject.h>
#include <game/components/textrenderer.h>
#include <game/components/transform.h>
#include "userinterface.h"

GameObject* UserInterface::score;
GameObject* UserInterface::coins;
GameObject* UserInterface::level;
GameObject* UserInterface::time;

GameData UserInterface::data;

UserInterface::~UserInterface()
{
    score = nullptr;
    coins = nullptr;
    level = nullptr;
    time  = nullptr;
}

void UserInterface::createUserInterface(ASGE::Renderer *renderer)
{
    createScoreDisplay(renderer);
    createCoinDisplay(renderer);

    /// world 1-1

    /// Time - empty when not used
}

void UserInterface::createCoinDisplay(ASGE::Renderer *renderer)
{/// create coins x amount 00
    coins = new GameObject();
    auto text = new TextRenderer();
    coins->addComponent(text);

    std::string zeros;
    if (data.score < 10) zeros = "0";

    text->createText(renderer, "x" + zeros + std::to_string(data.score), 1 );
    coins->getComponent<Transform*>()->setPosition( ASGE::SETTINGS.window_width/2,ASGE::SETTINGS.window_height/13 );
}

void UserInterface::createScoreDisplay(ASGE::Renderer* renderer)
{
    score = new GameObject();
    auto text = new TextRenderer();
    score->addComponent(text);

    std::string zeros = "";
    if (data.score < 10)
    {
        zeros = "00000";
    }
    else if (data.score < 100)
    {
        zeros = "0000";
    }
    else if (data.score < 1000)
    {
        zeros = "000";
    }
    else if (data.score < 10000)
    {
        zeros = "00";
    }
    else if (data.score < 100000)
    {
        zeros = "0";
    }

    text->createText(renderer, "MARIO\n" + zeros + std::to_string(data.score), .91f );
    score->getComponent<Transform*>()->setPosition( ASGE::SETTINGS.window_width/128,ASGE::SETTINGS.window_height/26 );
}


