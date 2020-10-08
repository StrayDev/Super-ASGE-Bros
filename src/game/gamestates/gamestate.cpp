#include "gamestate.h"

void GameState::render(ASGE::Renderer* renderer)
{
    for(auto g: GameObjects)
    {
        if (!g->getSprite()) continue;
        renderer->renderSprite(*g->getSprite());
    }
    for(auto t: TextObjects)
    {
        renderer->renderText(*t);
    }
}