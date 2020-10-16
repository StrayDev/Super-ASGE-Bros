#pragma once
#include <vector>
#include <Engine/Sprite.h>
#include "gamestate.h"
#include "game/gameobjects/gameobject.h"
#include "game/factories/factory.h"
#include "game/components/textrenderer.h"


class StartUp : public GameState
{
public:
    explicit StartUp(ASGEGame* game) : GameState(game) {}

    void init(ASGE::Renderer* renderer) override;
    void update(float delta_time) override {};

private:
    void initCamera();

};




