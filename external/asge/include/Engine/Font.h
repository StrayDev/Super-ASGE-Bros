//! @file Font.h
//! @brief Struct
//! @ref ASGE::Font

#pragma once
#include <string>
namespace ASGE
{
  //! \brief A font used to render text
  //! A font is used to store font related information.
  //! All fonts need a name, size and line height. This can
  //! be used by the renderer to ensure correct formatting.
  struct Font
  {
   public:
    //! Default constructor
    Font() = default;

    //! Default destructor
    virtual ~Font() = default;

    //! \brief Returns the distance in x pixels.
    //! Sometimes it's useful to know how wide a string
    //! rendered on the screen will be, maybe for procedurally
    //! placing text etc. This function attempts to return
    //! the number of pixels a string will take.
    //! \param string the length you want to calculate.
    //! \return The max number of pixels wide needed to render the string.
    [[nodiscard]] int pxWide(const std::string& string) const;
    [[nodiscard]] int pxWide(const char* ch, float scale) const;

    //! \brief Returns the distance scaled in x pixels.
    //! Sometimes it's useful to know how wide a string
    //! rendered on the screen will be, maybe for procedurally
    //! placing text etc. This function attempts to return
    //! the number of pixels a string will take.
    //! \param string the length you want to calculate.
    //! \param scale the scaled size you want to calculate.
    //! \return The max number of pixels wide needed to render the string.
    [[nodiscard]] virtual float
    pxWide(const std::string& string, float scale) const = 0;

    [[nodiscard]] int pxHeight(const std::string& string) const;
    [[nodiscard]] virtual float
    pxHeight(const std::string& string, float scale) const = 0;

   public:
    const char* font_name = ""; //!< The name of the font loaded.
    int font_size = 0;          //!< The size of the font imported.
    int line_height = 0;        //!< The recommended height of each line.
  };
}