//
// Created by huxy on 11/11/18.
//

#ifndef ASGE_POINT_H
#define ASGE_POINT_H

namespace ASGE
{
  /**
* @brief A point in 2D space.
*
* Used to represent a position in 2D space. Includes some basic
* helper functionality for distance and mid-point calculations.
   */
  struct Point2D
  {
    float x = 0; /**< the x position.   */
    float y = 0; /**< the y position.   */

    /**
    * Default constructor.
    * The constructor takes will default the position to 0,0
    * unless the x or x and y parameters are provided. These
    * are then mapped on the x,y values inside the struct.
    * @param x The x coordinate.
    * @param y The y coordinate.
    */
    Point2D(float x = 0, float y = 0);

    /**
    * Assigns the value of another point2D to this one.
    * Assignment constructor, that copies each field from
    * rhs in to the lhs.
    * @param Point2D.
    */
    Point2D& operator=(const Point2D&);

    /**
    * Assigns a 2D float array to this point.
    * Uses index 0,1 to copy the values from an array on to
    * the fields used in the struct. Allows easier updates
    * of an existing Point2D. Point2D p = {1,2}
    * @param [2] array storing x and y.
    */
    Point2D& operator=(const float[2]);

    /**
    * Midpoint.
    * Calculates the midpoint between two different points.
    * @param rhs The second point to use.
    * @return The midpoint as a Point2D.
    */
    [[nodiscard]] Point2D midpoint(const Point2D& rhs) const;

    /**
    * Distance.
    * Given two points, calculate the distance between them.
    * @param The second point to use.
    * @return The distance between the two points.
    */
    [[nodiscard]] float distance(const Point2D& rhs) const;

    Point2D& operator+=(const Point2D& rhs);
    Point2D& operator*=(float scalar);
    Point2D  operator*(float scalar);

    Point2D(const Point2D&) = default;
    Point2D(Point2D&&) noexcept;
    Point2D& operator=(Point2D&&) noexcept;
  };
}

#endif //ASGE_POINT_H
