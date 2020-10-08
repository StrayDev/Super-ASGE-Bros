#pragma once
#include <vector>
#include <Engine/Sprite.h>
#include "gamestate.h"
#include "game/gameobjects/blocks/gameobject.h"

class StartUp : public GameState
{
public:
    explicit StartUp(ASGEGame* game) : GameState(game) {}

    void init(ASGE::Renderer* renderer) override;
    void update(float delta_time) override {};
    //void render(ASGE::Renderer* renderer) override {};

private:
    void initCamera();

};




