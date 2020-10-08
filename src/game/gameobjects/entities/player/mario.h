#pragma once
#include "game/gameobjects/entities/entity.h"

class Mario : public Entity
{
public:
    explicit Mario(ASGE::Renderer* renderer);
    ~Mario() = default;

    void update(float delta_time) override;


private:

};


