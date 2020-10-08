#pragma once
#include <game/gameobjects/entities/entitystate.h>

class PlayerIdle : public EntityState
{
public:
    explicit PlayerIdle(Entity* entity) : EntityState(entity) {};
    ~PlayerIdle() = default;

    void update(float delta_time) override;
    //void init(ASGE::Renderer *renderer) override {};

private:


};


