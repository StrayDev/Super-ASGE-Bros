#pragma once
#include <vector>
#include <Engine/Sprite.h>
#include "gamestate.h"
#include "game/gameobjects/gameobject.h"

class Menu : public GameState
{
public:
    explicit Menu(ASGEGame* game) : GameState(game) {}
    ~Menu() override;

    void init(ASGE::Renderer* renderer) override;
    void update(float delta_time) override;

private:
    void createMenuText(ASGE::Renderer* renderer);

    GameObject* selection_icon = nullptr;

    void createSelectionIcon();
};


