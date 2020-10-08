//
// Created by huxy on 23/01/2020.
//

#ifndef ASGE_GAMESETTINGS_HPP
#define ASGE_GAMESETTINGS_HPP
#include <string>
namespace ASGE
{
  struct GameSettings
  {
    enum class WindowMode
    {
      FULLSCREEN = 0,            /**< Fullscreen without decorations. */
      WINDOWED = 1,              /**< Windowed desktop mode. */
      BORDERLESS_WINDOWED = 2,   /**< Borderless window desktop mode. */
      BORDERLESS_FULLSCREEN = 3, /**< Borderless full screen window mode. */
    };

    enum class MagFilter
    {
      NEAREST, /**< Takes the nearest pixel in manhattan distance.*/
      LINEAR   /**< Takes the weighted average of all 4 pixels.*/
    };

    GameSettings()  = default;
    ~GameSettings() = default;

    int window_width  = 800; /**< The width of the GL Window to create. */
    int window_height = 640; /**< The height of the GL Window to create. */
    int window_bpp    = 32;  /**< The Bits Per Pixel (BPP) of the window. */
    int msaa_level    = 1 ;  /**< MSAA can help smooth edges when using rotated views. */
    int fps_limit     = 144; /**< The engine will attempt to never exceed this FPS. */
    int anisotropic   = 16;  /**< Improves filtering at oblique angles. Not recommended for 2D. */

    std::string write_dir{ "" }; /**< The default write directory for ASGE IO. */
    std::string window_title{ "My ASGE Game" }; /**< The window title. */
    WindowMode mode{ WindowMode::WINDOWED }; /**< The window mode i.e. Fullscreen. */
    MagFilter mag_filter {MagFilter::LINEAR}; /**< Textures will use this filter by default. */
  };

  /// The lazy way of grabbing the game's settings
  inline GameSettings SETTINGS;
}
#endif // ASGE_GAMESETTINGS_HPP
