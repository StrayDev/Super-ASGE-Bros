#pragma once
#include <string>
#include <game/gameobjects/blocks/gameobject.h>
#include <game/levels/grid.h>
#include <game/gameobjects/entities/entity.h>
#include "game/core/game.h"

class GameState
{
public:
    explicit GameState(ASGEGame* game) { _game = game; }
    virtual ~GameState() = default;

    virtual void init(ASGE::Renderer* renderer) = 0;
    virtual void update(float delta_time) = 0;

    void render(ASGE::Renderer* renderer);

protected:
    ASGEGame* _game = nullptr;
    Grid* _grid = nullptr;
    std::vector<GameObject*> GameObjects;
    std::vector<Entity*> Entities;
    std::vector<ASGE::Text*> TextObjects;

};


