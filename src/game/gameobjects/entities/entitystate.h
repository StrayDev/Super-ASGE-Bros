#pragma once
#include "entity.h"

class EntityState
{
public:
    explicit EntityState(Entity* entity) { _entity = entity; }
    ~EntityState() { delete _entity; }

    // virtual void init(ASGE::Renderer* renderer) = 0;
    virtual void update(float delta_time) = 0;

protected:
    Entity* _entity = nullptr;
};


