//
// A basic 2D Camera for use in ASGE
//

#ifndef ASGE_CAMERA2D_HPP
#define ASGE_CAMERA2D_HPP

#include "GameTime.h"
#include "Point2D.h"
#include "Viewport.hpp"
#include <array>
namespace ASGE
{
  class Camera2D
  {
   public:
    using Translation = std::array<float, 3>;

   public:
    Camera2D() = default;
    Camera2D(float, float);
    Camera2D(Point2D, float, float);
    virtual ~Camera2D() = default;

    void lookAt(Point2D);
    void translate(float x, float y, float z);
    void translateX(float);
    void translateY(float);
    void translateZ(float);
    void resize(float, float);
    void setZoom(float);
    virtual void update(const ASGE::GameTime& game_time);

    [[nodiscard]] Viewport getView() const;
    [[nodiscard]] const Translation& getTranslation() const;
    [[nodiscard]] Translation& getTranslation();
    [[nodiscard]] float getZoom() const;

   private:
    Viewport viewport{ 0, 0, 0, 0 };
    Translation translation{ 0, 0, 0 };
    float zoom = 1.0f;
  };
}
#endif // ASGE_CAMERA2D_HPP
