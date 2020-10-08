/** 
 * @file
 * @brief Class @ref ASGE::Game
 */

#pragma once
#include <atomic>
#include <memory>

#include "GameSettings.hpp"
#include "GameTime.h"
#include "Input.h"
#include "Renderer.h"

namespace ASGE {

	/**
	*  @brief the core of the engine
	*  
	*  A skeleton structure and interface for running an instance
	*  of a Game. It stores access to the renderer and the input
	*  system. Input is often intrinsically linked to the render
	*  subsystem. To help speed up development, a typical update
	*  and render function is provided, along with GameTime. The
	*  initilisation code is not created by the Game, but by its
	*  dervied classes as the setup of the renderer is platform
	*  specific.
	*  @see GameTime
	*/
	class Game
	{

	public:

		/**
		*  Default constructor.
		*/
		explicit Game(const GameSettings& game_settings);

		/**
		*  Default destructor.
		*/
		virtual ~Game();

		/**
		*  Pure virtual function used to update the game.
		*  The update pattern is common usage within engines
		*  and will be automatically called every frame. Here
		*  all game objects that need simulation should be
		*  updated, ready to be rendered shortly thereafter.
		*  @param us Game and Frame delta information.
		*  @see GameTime
		*/
		virtual void update(const GameTime& us) = 0;

		/**
		*  Pure virtual function that sets up the renderer
		   before rendering a frame.
		*  Can include flushing of buffers, clearing screens etc.
		*  **This is handled inside the platform's specific
		*  implementation.**
		*/
		virtual void beginFrame() = 0;

		/**
		*  Pure virtual function used to render the game world.
		*  The render pattern is common usage within engines
		*  and will be automatically called every frame. All
		*  game objects to be visualised need to be drawn at this
		*  stage using the Game's renderer.
		*  @param us	Game and Frame delta information.
		*  @see GameTime
		*/
		virtual void render() = 0;

		/**
		*  Pure virtual function that completes the render frame.
		*  Typically, flushes the render queue, instructs any
		*  batched calls to complete and swaps the video buffers.
		*  **This is handled inside the platform's specific
		   implementation.**
		*/
		virtual void endFrame() = 0;

		/**
		*  Pure virtual function for setup and intialisation of API.
		*  **This is handled inside the platform's specific
		   implementation.**
		*  @param settings The window mode to start the game with.
		*  @return The result of the initialisation operation.
		*  @see WindowMode
		*/
		virtual bool initAPI() = 0;

		/**
		*  Pure virtual function for terminating the API.
		*  **This is handled inside the platform's specific
		   implementation.**
		*  @return The result of the initialisation operation.
		*/
		virtual bool exitAPI() noexcept = 0;

		/**
		*  The main game loop.
		*  Will keep looping unti a request to exit is received
		*  either from the renderer or via the signal exit
		*  function.
		*  @return The exit code for the game.
		*  @see signalExit
		*/
		int run();

		/**
		*  Signals the game should exit.
		*  Will flag the game to stop processing updates
		*  and abort the main game loop, thus exiting
		*  the game.
		*/
		void signalExit() noexcept;

	protected:

		/**
		*  Toggles the FPS on-screen.
		*  Will cause the game to draw and update the FPS
		*  on the screen every tick.
		*/
		void toggleFPS() noexcept;

		/**
		*  Updates the FPS counter.
		*  Update the FPS calculation every tick. Uses the
		*  average number of frames over a single second.
		*/
		void updateFPS();

		/**
		*  Initialises the file system.
		*/
		void initFileIO();

		std::unique_ptr<Renderer> renderer; /**< Unique pointer to the Renderer subsystem.
											     A smart pointer managing the renderer. 
											     Use renderer.get() to retrieve the raw pointer. */

		std::unique_ptr<Input>    inputs;   /**< Unique pointer to the Input handler.
												 A smart pointer managing the input handler.
											     Use renderer.get() to retrieve the raw pointer. */

		std::atomic<bool> show_fps {false}; /**< FPS counter. Shows the FPS on screen if set to true. */
		std::atomic<bool> exit {false};     /**< Exit boolean. If true the game loop will exit. */


   // GameSettings settings;
   private:
		std::chrono::milliseconds getGameTime() noexcept;
		GameTime epoch; /**< Delta. The frame deltas and total running time. */

		// used to measure the game's running time
    std::chrono::milliseconds paused_time = std::chrono::milliseconds(0);
    std::chrono::time_point<std::chrono::steady_clock> start_time = std::chrono::steady_clock::now();
    int frames = 0;
	};
}