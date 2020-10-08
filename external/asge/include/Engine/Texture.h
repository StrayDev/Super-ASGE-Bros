/** 
 * @file
 * @brief Class @ref ASGE::Texture2D, Enum Class @ref ASGE::SpriteSortMode
 */


#pragma once
#include "GameSettings.hpp"
#include "NonCopyable.h"
#include "PixelBuffer.h"
namespace ASGE
{
	/**
	* @brief modes to control the batching of sprites
	*
	* Used to control the sprite batching techniques
	* that renderers may support.
	*/
	enum class SpriteSortMode
	{
		IMMEDIATE,     /**< Renders the sprite immediately.
					              Invokes a state change, uploads to the gpu and draws the
							          primitives. This can be an expensive operation. */
		TEXTURE,       /**< Prepares the render data but does not populate the shared buffers
					              nor does it render immediately. Instead it queues all the draw calls
							          and then sorts them by their texture id. This reduces texture and
							          GPU state changes, but breaks the original draw order and is slightly
							          more intensive on the CPU and memory systems. */
		BACK_TO_FRONT, /**< Works identically to texture, but also uses the z-order to control the
					              order of draw calls. All draw calls will be first sorted by their z-order
							          and then sorted by their texture id. This mode will render the sprites with
							          the lowest z-order first. */
		FRONT_TO_BACK, /**< Works identically to texture, but also uses the z-order to control the
					              order of draw calls. All draw calls will be first sorted by their z-order
							          and then sorted by their texture id. This mode will render the sprites with
							          the highest z-order first. */
	};

	/**
	* @brief a simple 2D non-renderable texture.
	* 
	* A texture is used to load images into the GPU.
	* They retain a handle or link to it and the 
	* renderers are free to implement any caching systems
	* they see fit. 
	*/
	class Texture2D
	{
	public:

    using MagFilter = GameSettings::MagFilter;

    /**
    * The format of the texture
    */
    enum Format
    {
        MONOCHROME = 1, /**< The texture is monochromatic.*/
        MONOCHROME_ALPHA = 2, /**< The texture is monochromatic and has an alpha channel.*/
        RGB = 3, /**< There are Red, Green & Blue channels present.*/
        RGBA = 4 /**< There are RGB plus alpha chanels present .*/
    };

    /**
		* Default constructor.
		* @param width The width of the texture.
		* @param height the height of the texture.
		*/
		Texture2D(float width, float height) noexcept
		{
			dims[0] = width;
			dims[1] = height;
		}
			
		/**
		* Default destructor.
		* The destructor does not free the memory used on the GPU.
		* **This is handled inside the platform's specific implementation.**
		*/
		virtual ~Texture2D() = default;

 	  /**
		* Sets the format of the texture. 
		* @param f The format of the stored texture.
		* @see Format
		*/
		void setFormat(Format f) noexcept {	format = f; } 

		/**
		* Retrieves the format of the stored texture. 
		* @return The format of the texture. 
		* @see Format
		*/
		[[nodiscard]] Format getFormat() const { return format;}

    /**
		* Sets the filtering used for texture magnification.
		* Allows the type of filtering applied when
    * sampling the texture under magnification to be changed.
		* @param MagFilter.
		*/
    virtual void updateMagFilter(MagFilter filter) = 0;

		/**
		* Retrieves the texture from GPU memory.
		* Retrieving memory from the GPU like this is a
		* slow process. It is best to do this infrequently.
		* @return The binary file loaded in memory.
		*/
		virtual PixelBuffer* getPixelBuffer() noexcept = 0;
    [[nodiscard]] virtual const PixelBuffer* getPixelBuffer() const noexcept = 0;

		/**
		* Retrieves the width of the loaded texture.
		* @return The width of the texture.
		*/
		[[nodiscard]] float getWidth()  const noexcept { return dims[0]; }
		
		/**
		* Retrieves the width of the loaded texture.
		* @return The height of the texture.
		*/
		[[nodiscard]] float getHeight() const noexcept { return dims[1]; }


	protected:
    //MagFilter mag_filter;   /**< Texture2D Magnification Filter. Filtering to use when magnifying the texture. */
	  Format format = RGB;		/**< Texture2D Format. The pixel format used when loading the texture file. */
		float  dims[2]{ 0,0 };	/**< Texture2D Dimensions. The dimensions of the loaded texture file. */
	};
}