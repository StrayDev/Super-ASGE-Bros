#pragma once
#include <string>
#include "game/gameobjects/gameobject.h"
#include "game/levels/grid.h"
#include "game/core/game.h"

class GameState
{
public:
    explicit GameState(ASGEGame* game) { _game = game; }
    virtual ~GameState() = default;

    virtual void init(ASGE::Renderer* renderer) = 0;
    virtual void update(float delta_time) = 0;

    static void render(ASGE::Renderer* renderer);

protected:
    ASGEGame* _game = nullptr;
    Grid* _grid = nullptr; //??? this is being bypassed


};


