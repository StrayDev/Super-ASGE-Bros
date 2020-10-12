#include "gamestate.h"
#include "game/components/spriterenderer.h"
#include "Engine/Logger.hpp"


void GameState::render(ASGE::Renderer* renderer)
{
    for(auto r : RenderComponent::getRenderComponents())
    {
        r->render(renderer);
    }
}