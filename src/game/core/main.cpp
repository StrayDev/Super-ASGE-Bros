#include "game.h"

int main()
{
    ASGE::GameSettings game_settings;
    game_settings.window_title  = "Super ASGE Bros";
    game_settings.window_width  = 2048;
    game_settings.window_height = 1080;
    game_settings.msaa_level    = 2;

    ASGEGame asge_game(game_settings);
    if (asge_game.init())
    {
        asge_game.run();
    }
    return 0;
}