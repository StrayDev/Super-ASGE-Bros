#pragma once
#include <game/components/transform.h>

class MenuObjectFactory
{
public:
    static void createMenuObjects(ASGE::Renderer* renderer);

private:
    static Transform* Selection_icon;

    static void createMenuText(ASGE::Renderer* renderer);
    static void createSelectionIcon(ASGE::Renderer *renderer);

    static void createCoinIcon(ASGE::Renderer *pRenderer);
};


