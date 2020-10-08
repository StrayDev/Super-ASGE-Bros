/** 
 * @file
 * @brief Struct @ref ASGE::Colour, Namespace @ref ASGE::COLOURS
 */

#pragma once
namespace ASGE {

	/**
	* @brief RGB Helper.
	* 
	* Used to represent the RGB values of a colour.
	*/
	struct Colour
	{
		float r = 1; /**< the red component.   */
		float g = 1; /**< the green component. */
		float b = 1; /**< the blue component.  */

		/**
		* Default constructor.
		* The constructor takes an array of 3 floats. These
		* are then mapped on the RGB values inside the struct.
		*/
		constexpr Colour(const float rgb[3]) noexcept
		{
			r = rgb[0];
			g = rgb[1];
			b = rgb[2];
		}

    constexpr Colour(const float r, const float g, const float b) noexcept
    {
      this->r = r;
      this->g = g;
      this->b = b;
    }
	};

    /**
    * @namespace ASGE::COLOURS
    * @brief predefined RGB values
    */
	namespace COLOURS {
		constexpr Colour ALICEBLUE {0.941F, 0.973F, 1.000F};          /**< ALICEBLUE[] = { 0.941F, 0.973F, 1.000F }           */
		constexpr Colour ANTIQUEWHITE{ 0.980F, 0.922F, 0.843F };         /**< ANTIQUEWHITE[] = { 0.980F, 0.922F, 0.843F }         */
		constexpr Colour AQUA { 0.000F, 1.000F, 1.000F };                 /**< AQUA { 0.000F, 1.000F, 1.000F }                 */
		constexpr Colour AQUAMARINE { 0.498F, 1.000F, 0.831F };           /**< AQUAMARINE { 0.498F, 1.000F, 0.831F }           */
		constexpr Colour AZURE { 0.941F, 1.000F, 1.000F };                /**< AZURE { 0.941F, 1.000F, 1.000F }                */
		constexpr Colour BEIGE { 0.961F, 0.961F, 0.863F };                /**< BEIGE { 0.961F, 0.961F, 0.863F }                */
		constexpr Colour BISQUE { 1.000F, 0.894F, 0.769F };               /**< BISQUE { 1.000F, 0.894F, 0.769F }               */
		constexpr const Colour BLACK { 0.000F, 0.000F, 0.000F };                /**< BLACK { 0.000F, 0.000F, 0.000F }                */
		constexpr Colour BLANCHEDALMOND { 1.000F, 0.922F, 0.804F };       /**< BLANCHEDALMOND { 1.000F, 0.922F, 0.804F }       */
		constexpr Colour BLUE { 0.000F, 0.000F, 1.000F };                 /**< BLUE { 0.000F, 0.000F, 1.000F }                 */
		constexpr Colour BLUEVIOLET { 0.541F, 0.169F, 0.886F };           /**< BLUEVIOLET { 0.541F, 0.169F, 0.886F }           */
		constexpr Colour BROWN { 0.647F, 0.165F, 0.165F };                /**< BROWN { 0.647F, 0.165F, 0.165F }                */
		constexpr Colour BURLYWOOD { 0.871F, 0.722F, 0.529F };            /**< BURLYWOOD { 0.871F, 0.722F, 0.529F }            */
		constexpr Colour CADETBLUE { 0.373F, 0.620F, 0.627F };            /**< CADETBLUE { 0.373F, 0.620F, 0.627F }            */
		constexpr Colour CHARTREUSE { 0.498F, 1.000F, 0.000F };           /**< CHARTREUSE { 0.498F, 1.000F, 0.000F }           */
		constexpr Colour CHOCOLATE { 0.824F, 0.412F, 0.118F };            /**< CHOCOLATE { 0.824F, 0.412F, 0.118F }            */
		constexpr Colour CORAL { 1.000F, 0.498F, 0.314F };                /**< CORAL { 1.000F, 0.498F, 0.314F }                */
		constexpr Colour CORNFLOWERBLUE { 0.392F, 0.584F, 0.929F };       /**< CORNFLOWERBLUE { 0.392F, 0.584F, 0.929F }       */
		constexpr Colour CORNSILK { 1.000F, 0.973F, 0.863F };             /**< CORNSILK { 1.000F, 0.973F, 0.863F }             */
		constexpr Colour CRIMSON { 0.863F, 0.078F, 0.235F };              /**< CRIMSON { 0.863F, 0.078F, 0.235F }              */
		constexpr Colour CYAN { 0.000F, 1.000F, 1.000F };                 /**< CYAN { 0.000F, 1.000F, 1.000F }                 */
		constexpr Colour DARKBLUE { 0.000F, 0.000F, 0.545F };             /**< DARKBLUE { 0.000F, 0.000F, 0.545F }             */
		constexpr Colour DARKCYAN { 0.000F, 0.545F, 0.545F };             /**< DARKCYAN { 0.000F, 0.545F, 0.545F }             */
		constexpr Colour DARKGOLDENROD { 0.722F, 0.525F, 0.043F };        /**< DARKGOLDENROD { 0.722F, 0.525F, 0.043F }        */
		constexpr Colour DARKGRAY { 0.663F, 0.663F, 0.663F };             /**< DARKGRAY { 0.663F, 0.663F, 0.663F }             */
		constexpr Colour DARKGREEN { 0.000F, 0.392F, 0.000F };            /**< DARKGREEN { 0.000F, 0.392F, 0.000F }            */
		constexpr Colour DARKGREY { 0.663F, 0.663F, 0.663F };             /**< DARKGREY { 0.663F, 0.663F, 0.663F }             */
		constexpr Colour DARKKHAKI { 0.741F, 0.718F, 0.420F };            /**< DARKKHAKI { 0.741F, 0.718F, 0.420F }            */
		constexpr Colour DARKMAGENTA { 0.545F, 0.000F, 0.545F };          /**< DARKMAGENTA { 0.545F, 0.000F, 0.545F }          */
		constexpr Colour DARKOLIVEGREEN { 0.333F, 0.420F, 0.184F };       /**< DARKOLIVEGREEN { 0.333F, 0.420F, 0.184F }       */
		constexpr Colour DARKORANGE { 1.000F, 0.549F, 0.000F };           /**< DARKORANGE { 1.000F, 0.549F, 0.000F }           */
		constexpr Colour DARKORCHID { 0.600F, 0.196F, 0.800F };           /**< DARKORCHID { 0.600F, 0.196F, 0.800F }           */
		constexpr Colour DARKRED { 0.545F, 0.000F, 0.000F };              /**< DARKRED { 0.545F, 0.000F, 0.000F }              */
		constexpr Colour DARKSALMON { 0.914F, 0.588F, 0.478F };           /**< DARKSALMON { 0.914F, 0.588F, 0.478F }           */
		constexpr Colour DARKSEAGREEN { 0.561F, 0.737F, 0.561F };         /**< DARKSEAGREEN { 0.561F, 0.737F, 0.561F }         */
		constexpr Colour DARKSLATEBLUE { 0.282F, 0.239F, 0.545F };        /**< DARKSLATEBLUE { 0.282F, 0.239F, 0.545F }        */
		constexpr Colour DARKSLATEGRAY { 0.184F, 0.310F, 0.310F };        /**< DARKSLATEGRAY { 0.184F, 0.310F, 0.310F }        */
		constexpr Colour DARKTURQUOISE { 0.000F, 0.808F, 0.820F };        /**< DARKTURQUOISE { 0.000F, 0.808F, 0.820F }        */
		constexpr Colour DARKVIOLET { 0.580F, 0.000F, 0.827F };           /**< DARKVIOLET { 0.580F, 0.000F, 0.827F }           */
		constexpr Colour DEEPPINK { 1.000F, 0.078F, 0.576F };             /**< DEEPPINK { 1.000F, 0.078F, 0.576F }             */
		constexpr Colour DEEPSKYBLUE { 0.000F, 0.749F, 1.000F };          /**< DEEPSKYBLUE { 0.000F, 0.749F, 1.000F }          */
		constexpr Colour DIMGRAY { 0.412F, 0.412F, 0.412F };              /**< DIMGRAY { 0.412F, 0.412F, 0.412F }              */
		constexpr Colour DIMGREY { 0.412F, 0.412F, 0.412F };              /**< DIMGREY { 0.412F, 0.412F, 0.412F }              */
		constexpr Colour DODGERBLUE { 0.118F, 0.565F, 1.000F };           /**< DODGERBLUE { 0.118F, 0.565F, 1.000F }           */
		constexpr Colour FIREBRICK { 0.698F, 0.133F, 0.133F };            /**< FIREBRICK { 0.698F, 0.133F, 0.133F }            */
		constexpr Colour FLORALWHITE { 1.000F, 0.980F, 0.941F };          /**< FLORALWHITE { 1.000F, 0.980F, 0.941F }          */
		constexpr Colour FORESTGREEN { 0.133F, 0.545F, 0.133F };          /**< FORESTGREEN { 0.133F, 0.545F, 0.133F }          */
		constexpr Colour FUCHSIA { 1.000F, 0.000F, 1.000F };              /**< FUCHSIA { 1.000F, 0.000F, 1.000F }              */
		constexpr Colour GAINSBORO { 0.863F, 0.863F, 0.863F };            /**< GAINSBORO { 0.863F, 0.863F, 0.863F }            */
		constexpr Colour GHOSTWHITE { 0.973F, 0.973F, 1.000F };           /**< GHOSTWHITE { 0.973F, 0.973F, 1.000F }           */
		constexpr Colour GOLD { 1.000F, 0.843F, 0.000F };                 /**< GOLD { 1.000F, 0.843F, 0.000F }                 */
		constexpr Colour GOLDENROD { 0.855F, 0.647F, 0.125F };            /**< GOLDENROD { 0.855F, 0.647F, 0.125F }            */
		constexpr Colour GRAY { 0.502F, 0.502F, 0.502F };                 /**< GRAY { 0.502F, 0.502F, 0.502F }                 */
    constexpr Colour GRAYBLACK { 0.100F, 0.100F, 0.100F };            /**< GRAYBLACK { 0.100F, 0.100F, 0.100F }            */
		constexpr Colour GREEN { 0.000F, 0.502F, 0.000F };                /**< GREEN { 0.000F, 0.502F, 0.000F }                */
		constexpr Colour GREENYELLOW { 0.678F, 1.000F, 0.184F };          /**< GREENYELLOW { 0.678F, 1.000F, 0.184F }          */
		constexpr Colour GREY { 0.502F, 0.502F, 0.502F };                 /**< GREY { 0.502F, 0.502F, 0.502F }                 */
    constexpr Colour GREYBLACK { 0.100F, 0.100F, 0.100F };            /**< GREYBLACK { 0.100F, 0.100F, 0.100F }            */
		constexpr Colour HONEYDEW { 0.941F, 1.000F, 0.941F };             /**< HONEYDEW { 0.941F, 1.000F, 0.941F }             */
		constexpr Colour HOTPINK { 1.000F, 0.412F, 0.706F };              /**< HOTPINK { 1.000F, 0.412F, 0.706F }              */
		constexpr Colour INDIANRED { 0.804F, 0.361F, 0.361F };            /**< INDIANRED { 0.804F, 0.361F, 0.361F }            */
		constexpr Colour INDIGO { 0.294F, 0.000F, 0.510F };               /**< INDIGO { 0.294F, 0.000F, 0.510F }               */
		constexpr Colour IVORY { 1.000F, 1.000F, 0.941F };                /**< IVORY { 1.000F, 1.000F, 0.941F }                */
		constexpr Colour KHAKI { 0.941F, 0.902F, 0.549F };                /**< KHAKI { 0.941F, 0.902F, 0.549F }                */
		constexpr Colour LAVENDER { 0.902F, 0.902F, 0.980F };             /**< LAVENDER { 0.902F, 0.902F, 0.980F }             */
		constexpr Colour LAVENDERBLUSH { 1.000F, 0.941F, 0.961F };        /**< LAVENDERBLUSH { 1.000F, 0.941F, 0.961F }        */
		constexpr Colour LAWNGREEN { 0.486F, 0.988F, 0.000F };            /**< LAWNGREEN { 0.486F, 0.988F, 0.000F }            */
		constexpr Colour LEMONCHIFFON { 1.000F, 0.980F, 0.804F };         /**< LEMONCHIFFON { 1.000F, 0.980F, 0.804F }         */
		constexpr Colour LIGHTBLUE { 0.678F, 0.847F, 0.902F };            /**< LIGHTBLUE { 0.678F, 0.847F, 0.902F }            */
		constexpr Colour LIGHTCORAL { 0.941F, 0.502F, 0.502F };           /**< LIGHTCORAL { 0.941F, 0.502F, 0.502F }           */
		constexpr Colour LIGHTCYAN { 0.878F, 1.000F, 1.000F };            /**< LIGHTCYAN { 0.878F, 1.000F, 1.000F }            */
		constexpr Colour LIGHTGOLDENRODYELLOW { 0.980F, 0.980F, 0.824F }; /**< LIGHTGOLDENRODYELLOW { 0.980F, 0.980F, 0.824F } */
		constexpr Colour LIGHTGRAY { 0.827F, 0.827F, 0.827F };            /**< LIGHTGRAY { 0.827F, 0.827F, 0.827F }            */
		constexpr Colour LIGHTGREEN { 0.565F, 0.933F, 0.565F };           /**< LIGHTGREEN { 0.565F, 0.933F, 0.565F }           */
		constexpr Colour LIGHTGREY { 0.827F, 0.827F, 0.827F };            /**< LIGHTGREY { 0.827F, 0.827F, 0.827F }            */
		constexpr Colour LIGHTPINK { 1.000F, 0.714F, 0.757F };            /**< LIGHTPINK { 1.000F, 0.714F, 0.757F }            */
		constexpr Colour LIGHTSALMON { 1.000F, 0.627F, 0.478F };          /**< LIGHTSALMON { 1.000F, 0.627F, 0.478F }          */
		constexpr Colour LIGHTSEAGREEN { 0.125F, 0.698F, 0.667F };        /**< LIGHTSEAGREEN { 0.125F, 0.698F, 0.667F }        */
		constexpr Colour LIGHTSKYBLUE { 0.529F, 0.808F, 0.980F };         /**< LIGHTSKYBLUE { 0.529F, 0.808F, 0.980F }         */
		constexpr Colour LIGHTSLATEGRAY { 0.467F, 0.533F, 0.600F };       /**< LIGHTSLATEGRAY { 0.467F, 0.533F, 0.600F }       */
		constexpr Colour LIGHTSLATEGREY { 0.467F, 0.533F, 0.600F };       /**< LIGHTSLATEGREY { 0.467F, 0.533F, 0.600F }       */
		constexpr Colour LIGHTSTEELBLUE { 0.690F, 0.769F, 0.871F };       /**< LIGHTSTEELBLUE { 0.690F, 0.769F, 0.871F }       */
		constexpr Colour LIGHTYELLOW { 1.000F, 1.000F, 0.878F };          /**< LIGHTYELLOW { 1.000F, 1.000F, 0.878F }          */
		constexpr Colour LIME { 0.000F, 1.000F, 0.000F };                 /**< LIME { 0.000F, 1.000F, 0.000F };                */
		constexpr Colour LIMEGREEN { 0.196F, 0.804F, 0.196F };            /**< LIMEGREEN { 0.196F, 0.804F, 0.196F }            */
		constexpr Colour LINEN { 0.980F, 0.941F, 0.902F };                /**< LINEN { 0.980F, 0.941F, 0.902F }                */
		constexpr Colour MAGENTA { 1.000F, 0.000F, 1.000F };              /**< MAGENTA { 1.000F, 0.000F, 1.000F }              */
		constexpr Colour MAROON { 0.502F, 0.000F, 0.000F };               /**< MAROON { 0.502F, 0.000F, 0.000F }               */
		constexpr Colour MEDIUMAQUAMARINE { 0.400F, 0.804F, 0.667F };     /**< MEDIUMAQUAMARINE { 0.400F, 0.804F, 0.667F }     */
		constexpr Colour MEDIUMBLUE { 0.000F, 0.000F, 0.804F };           /**< MEDIUMBLUE { 0.000F, 0.000F, 0.804F }           */
		constexpr Colour MEDIUMORCHID { 0.729F, 0.333F, 0.827F };         /**< MEDIUMORCHID { 0.729F, 0.333F, 0.827F }         */
		constexpr Colour MEDIUMPURPLE { 0.576F, 0.439F, 0.859F };         /**< MEDIUMPURPLE { 0.576F, 0.439F, 0.859F }         */
		constexpr Colour MEDIUMSEAGREEN { 0.235F, 0.702F, 0.443F };       /**< MEDIUMSEAGREEN { 0.235F, 0.702F, 0.443F }       */
		constexpr Colour MEDIUMSLATEBLUE { 0.482F, 0.408F, 0.933F };      /**< MEDIUMSLATEBLUE { 0.482F, 0.408F, 0.933F }      */
		constexpr Colour MEDIUMSPRINGGREEN { 0.000F, 0.980F, 0.604F };    /**< MEDIUMSPRINGGREEN { 0.000F, 0.980F, 0.604F }    */
		constexpr Colour MEDIUMTURQUOISE { 0.282F, 0.820F, 0.800F };      /**< MEDIUMTURQUOISE { 0.282F, 0.820F, 0.800F }      */
		constexpr Colour MEDIUMVIOLETRED { 0.780F, 0.082F, 0.522F };      /**< MEDIUMVIOLETRED { 0.780F, 0.082F, 0.522F }      */
		constexpr Colour MIDNIGHTBLUE { 0.098F, 0.098F, 0.439F };         /**< MIDNIGHTBLUE { 0.098F, 0.098F, 0.439F }         */
		constexpr Colour MINTCREAM { 0.961F, 1.000F, 0.980F };            /**< MINTCREAM { 0.961F, 1.000F, 0.980F }            */
		constexpr Colour MISTYROSE { 1.000F, 0.894F, 0.882F };            /**< MISTYROSE { 1.000F, 0.894F, 0.882F }            */
		constexpr Colour MOCCASIN { 1.000F, 0.894F, 0.710F };             /**< MOCCASIN { 1.000F, 0.894F, 0.710F }             */
		constexpr Colour NAVAJOWHITE { 1.000F, 0.871F, 0.678F };          /**< NAVAJOWHITE { 1.000F, 0.871F, 0.678F }          */
		constexpr Colour NAVY { 0.000F, 0.000F, 0.502F };                 /**< NAVY { 0.000F, 0.000F, 0.502F }                 */
		constexpr Colour OLDLACE { 0.992F, 0.961F, 0.902F };              /**< OLDLACE { 0.992F, 0.961F, 0.902F }              */
		constexpr Colour OLIVE { 0.502F, 0.502F, 0.000F };                /**< OLIVE { 0.502F, 0.502F, 0.000F }                */
		constexpr Colour OLIVEDRAB { 0.420F, 0.557F, 0.137F };            /**< OLIVEDRAB { 0.420F, 0.557F, 0.137F }            */
		constexpr Colour ORANGE { 1.000F, 0.647F, 0.000F };               /**< ORANGE { 1.000F, 0.647F, 0.000F }               */
		constexpr Colour ORANGERED { 1.000F, 0.271F, 0.000F };            /**< ORANGERED { 1.000F, 0.271F, 0.000F }            */
		constexpr Colour ORCHID { 0.855F, 0.439F, 0.839F };               /**< ORCHID { 0.855F, 0.439F, 0.839F }               */
		constexpr Colour PALEGOLDENROD { 0.933F, 0.910F, 0.667F };        /**< PALEGOLDENROD { 0.933F, 0.910F, 0.667F }        */
		constexpr Colour PALEGREEN { 0.596F, 0.984F, 0.596F };            /**< PALEGREEN { 0.596F, 0.984F, 0.596F }            */
		constexpr Colour PALETURQUOISE { 0.686F, 0.933F, 0.933F };        /**< PALETURQUOISE { 0.686F, 0.933F, 0.933F }        */
		constexpr Colour PALEVIOLETRED { 0.859F, 0.439F, 0.576F };        /**< PALEVIOLETRED { 0.859F, 0.439F, 0.576F }        */
		constexpr Colour PAPAYAWHIP { 1.000F, 0.937F, 0.835F };           /**< PAPAYAWHIP { 1.000F, 0.937F, 0.835F }           */
		constexpr Colour PEACHPUFF { 1.000F, 0.855F, 0.725F };            /**< PEACHPUFF { 1.000F, 0.855F, 0.725F }            */
		constexpr Colour PERU { 0.804F, 0.522F, 0.247F };                 /**< PERU { 0.804F, 0.522F, 0.247F }                 */
		constexpr Colour PINK { 1.000F, 0.753F, 0.796F };                 /**< PINK { 1.000F, 0.753F, 0.796F }                 */
		constexpr Colour PLUM { 0.867F, 0.627F, 0.867F };                 /**< PLUM { 0.867F, 0.627F, 0.867F }                 */
		constexpr Colour POWDERBLUE { 0.690F, 0.878F, 0.902F };           /**< POWDERBLUE { 0.690F, 0.878F, 0.902F }           */
		constexpr Colour PURPLE { 0.502F, 0.000F, 0.502F };               /**< PURPLE { 0.502F, 0.000F, 0.502F }               */
		constexpr Colour RED { 1.000F, 0.000F, 0.000F };                  /**< RED { 1.000F, 0.000F, 0.000F }                  */
		constexpr Colour ROSYBROWN { 0.737F, 0.561F, 0.561F };            /**< ROSYBROWN { 0.737F, 0.561F, 0.561F }             */
		constexpr Colour ROYALBLUE { 0.255F, 0.412F, 0.882F };            /**< ROYALBLUE { 0.255F, 0.412F, 0.882F }            */
		constexpr Colour SADDLEBROWN { 0.545F, 0.271F, 0.075F };          /**< SADDLEBROWN { 0.545F, 0.271F, 0.075F }          */
		constexpr Colour SALMON { 0.980F, 0.502F, 0.447F };               /**< SALMON { 0.980F, 0.502F, 0.447F }               */
		constexpr Colour SANDYBROWN { 0.957F, 0.643F, 0.376F };           /**< SANDYBROWN { 0.957F, 0.643F, 0.376F }           */
		constexpr Colour SEAGREEN { 0.180F, 0.545F, 0.341F };             /**< SEAGREEN { 0.180F, 0.545F, 0.341F }             */
		constexpr Colour SEASHELL { 1.000F, 0.961F, 0.933F };             /**< SEASHELL { 1.000F, 0.961F, 0.933F }             */
		constexpr Colour SIENNA { 0.627F, 0.322F, 0.176F };               /**< SIENNA { 0.627F, 0.322F, 0.176F }               */
		constexpr Colour SILVER { 0.753F, 0.753F, 0.753F };               /**< SILVER { 0.753F, 0.753F, 0.753F }               */
		constexpr Colour SKYBLUE { 0.529F, 0.808F, 0.922F };              /**< SKYBLUE { 0.529F, 0.808F, 0.922F }             */
		constexpr Colour SLATEBLUE { 0.416F, 0.353F, 0.804F };            /**< SLATEBLUE { 0.416F, 0.353F, 0.804F }            */
		constexpr Colour SLATEGRAY { 0.439F, 0.502F, 0.565F };            /**< SLATEGRAY { 0.439F, 0.502F, 0.565F }            */
		constexpr Colour SLATEGREY { 0.439F, 0.502F, 0.565F };            /**< SLATEGREY { 0.439F, 0.502F, 0.565F }            */
		constexpr Colour SNOW { 1.000F, 0.980F, 0.980F };                 /**< SNOW { 1.000F, 0.980F, 0.980F }                 */
		constexpr Colour SPRINGGREEN { 0.000F, 1.000F, 0.498F };          /**< SPRINGGREEN { 0.000F, 1.000F, 0.498F }          */
		constexpr Colour STEELBLUE { 0.275F, 0.510F, 0.706F };            /**< STEELBLUE { 0.275F, 0.510F, 0.706F }            */
		constexpr Colour TAN { 0.824F, 0.706F, 0.549F };                  /**< TAN { 0.824F, 0.706F, 0.549F }                 */
		constexpr Colour TEAL { 0.000F, 0.502F, 0.502F };                 /**< TEAL { 0.000F, 0.502F, 0.502F }                 */
		constexpr Colour THISTLE { 0.847F, 0.749F, 0.847F };              /**< THISTLE { 0.847F, 0.749F, 0.847F }              */
		constexpr Colour TOMATO { 1.000F, 0.388F, 0.278F };               /**< TOMATO { 1.000F, 0.388F, 0.278F }               */
		constexpr Colour TURQUOISE { 0.251F, 0.878F, 0.816F };            /**< TURQUOISE { 0.251F, 0.878F, 0.816F }             */
		constexpr Colour VIOLET { 0.933F, 0.510F, 0.933F };               /**< VIOLET { 0.933F, 0.510F, 0.933F }               */
		constexpr Colour WHEAT { 0.961F, 0.871F, 0.702F };                /**< WHEAT { 0.961F, 0.871F, 0.702F }                */
		constexpr Colour WHITE { 1.000F, 1.000F, 1.000F };                /**< WHITE { 1.000F, 1.000F, 1.000F }                */
		constexpr Colour WHITESMOKE { 0.961F, 0.961F, 0.961F };           /**< WHITESMOKE { 0.961F, 0.961F, 0.961F }          */
		constexpr Colour YELLOW { 1.000F, 1.000F, 0.000F };               /**< YELLOW { 1.000F, 1.000F, 0.000F }               */
		constexpr Colour YELLOWGREEN { 0.604F, 0.804F, 0.196F };          /**< YELLOWGREEN { 0.604F, 0.804F, 0.196F }          */
	}
}