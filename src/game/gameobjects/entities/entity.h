#pragma once
#include <game/gameobjects/blocks/gameobject.h>

class EntityState;

class Entity : public GameObject
{
public:
    Entity() = default;
    ~Entity() = default;

    virtual void update(float delta_time);

    void setState(EntityState* state);

protected:
    EntityState* entity_state = nullptr;

};


