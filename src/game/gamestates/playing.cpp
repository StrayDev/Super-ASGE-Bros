#include <Engine/Logger.hpp>
#include "playing.h"
#include "game/levels/leveldata.h"

Playing::~Playing()
{
    Logging::log("GameState : PLAYING DESTROYED\n");
}

void Playing::init(ASGE::Renderer *renderer)
{
    Logging::log("GameState : PLAYING INIT\n");
}

void Playing::update(float delta_time)
{

}

