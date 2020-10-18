#pragma once

#include <Engine/Renderer.h>
#include <game/core/gamedata.h>

class UserInterface
{
public:
    UserInterface() = default;
    ~UserInterface();

    static void createUserInterface(ASGE::Renderer* renderer);

private:
    static GameObject* score;
    static GameObject* coins;
    static GameObject* level;
    static GameObject* time;

    static GameData data;

    static void createScoreDisplay(ASGE::Renderer *renderer);
    static void createCoinDisplay(ASGE::Renderer *renderer);
    static void createCoinSprite(ASGE::Renderer *renderer);
};


