#include "gamestate.h"

void GameState::render(ASGE::Renderer* renderer)
{
    for(auto r : RenderComponent::getRenderComponents())
    {
        r->render(renderer);
    }
}