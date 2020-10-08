#include "playeridle.h"
#include <Engine/Logger.hpp>

void PlayerIdle::update(float delta_time)
{
    _entity->setPosition(_entity->getPosition().x() + (200 * delta_time), 0);
}
