/** 
 * @file
 * @brief Struct @ref ASGE::GameTime
 */

#pragma once
#include <chrono>
#include <chrono>
namespace ASGE {

	/**
	*  @brief stores both frame and game deltas
	*    
	*  Stores various measurments of delta time for the
	*  game. It will store the current time point which
	*  is used to calculate the delta between frames, the 
	*  delta of the last frame and the entire delta since the 
	*  game started. This can be used to control simulations
	*  and render functions to use non-fixed time steps.
	*/
	struct GameTime
	{

    /**
    *  Time point of last tick.
    *  The time at which the previous tick update began.
    */
    std::chrono::time_point<std::chrono::steady_clock> update_time = std::chrono::steady_clock::now();

		/** 
		*  Time point of frame.  
		*  The time at which the previous frame was rendered.
		*/
		std::chrono::time_point<std::chrono::steady_clock> frame_time = std::chrono::steady_clock::now();

		/**
		*  Tick delta.
		*  The amount of elapsed time since the last update.
		*/
		std::chrono::duration<double, std::milli> delta;

		/**
		*  Running time. 
		*  The amount of time since the start of the game. 
		*/
		std::chrono::milliseconds elapsed;

		/// The last delta expressed in seconds (double)
		/// Just a shorthand function to convert the chrono::duration
		/// into a more user friendly number.
		/// \return The last frame delta in seconds
    double deltaInSecs() const noexcept { return delta.count() / 1000.0; }
	};
}