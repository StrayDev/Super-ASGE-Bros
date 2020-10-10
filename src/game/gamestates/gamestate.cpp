#include "gamestate.h"
#include "game/components/spriterenderer.h"
#include "Engine/Logger.hpp"


void GameState::render(ASGE::Renderer* renderer)
{

    Logging::log(std::to_string(Renderer::getRenderComponents().size()));

    for(auto r : Renderer::getRenderComponents())
    {

    }
}