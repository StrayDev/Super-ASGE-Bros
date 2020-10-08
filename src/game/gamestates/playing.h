#pragma once
#include "gamestate.h"

class Playing : public GameState
{
public:
    explicit Playing(ASGEGame* game) : GameState(game) {}
    ~Playing() override;

    void init(ASGE::Renderer *renderer) override;
    void update(float delta_time) override;

private:

};
