#include "entity.h"
#include "entitystate.h"

void Entity::update(float delta_time)
{
    entity_state->update(delta_time);
}

void Entity::setState(EntityState* state)
{
    delete entity_state;
    entity_state = state;
}
