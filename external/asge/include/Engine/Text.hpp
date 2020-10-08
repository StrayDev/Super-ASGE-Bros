//
// Created by huxy on 07/02/2020.
//

#ifndef ASGE_TEXT_HPP
#define ASGE_TEXT_HPP

#include "Colours.h"
#include "Font.h"
#include "SpriteBounds.h"
#include <string>

namespace ASGE
{
  struct
  Text
  {
   public:
    Text() = default;
    explicit Text(const ASGE::Font&);
    Text(const ASGE::Font&, std::string);
    Text(const ASGE::Font& font, const std::string& string, int x, int y);
    Text(const ASGE::Font& font, std::string&& string, int x, int y);
    Text(const ASGE::Font& font, const std::string& string, int x, int y, const ASGE::Colour& colour);
    Text(const ASGE::Font& font, std::string&& string, int x, int y, const ASGE::Colour& colour);

    Text(const Text&) = delete;
    Text& operator=(const Text&) = delete;
    Text(Text&&) noexcept;
    Text& operator=(Text&& other) noexcept;

    [[nodiscard]] bool  validFont() const noexcept;
    [[nodiscard]] short getZOrder() const noexcept;
    [[nodiscard]] int   getLineSpacing(bool) const;
    [[nodiscard]] float getHeight() const noexcept;
    [[nodiscard]] float getOpacity() const noexcept;
    [[nodiscard]] float getScale() const noexcept;
    [[nodiscard]] float getWidth() const noexcept;
    [[nodiscard]] const Point2D& getPosition() const noexcept;
    [[nodiscard]] const Colour& getColour() const noexcept;
    [[nodiscard]] const std::string& getString() const noexcept;
    [[nodiscard]] const Font& getFont() const noexcept;
    [[nodiscard]] TextBounds getGlobalBounds() const;
    [[nodiscard]] TextBounds getLocalBounds() const;

    void setZOrder(short) noexcept;
    void setScale(float) noexcept;
    void setOpacity(float) noexcept;
    void setPositionX(float) noexcept;
    void setPositionY(float) noexcept;
    void setPosition(const Point2D&) noexcept;
    void setPosition(Point2D&&) noexcept;
    void setColour(const ASGE::Colour&) noexcept;
    void setString(std::string& string) noexcept;
    void setString(std::string&& string) noexcept;
    void setFont(const Font&) noexcept;

    //operator overload, add to string.. yes...
    //operator overload, remove from string

    ///todo: add move assignment and copy constructors
   private:
    std::string string = "";
    Colour colour      = ASGE::COLOURS::WHITE;
    Point2D position   = Point2D{0, 0};
    float opacity      = 1.0f;
    float scale        = 1.0f;
    short z_order      = 0;
    const Font* font   = nullptr;

    int getCharacterSize (){ static_assert(true, "Not Yet Implemented"); return 0;}
    int getRotation()      { static_assert(true, "Not Yet Implemented"); return 0;}
    int getLetterSpacing() { static_assert(true, "Not Yet Implemented"); return 0;}

  };
}
#endif // ASGE_TEXT_HPP
