#ifndef POINT_H
#define POINT_H

/**
 * Contains function declarations for Points.
 * @author Ted Mader
 * @date 2016-09-12
 */
class Point {
public:
  /**
   * Returns a constructed Point with values set to 0.
   */
  Point();

  /**
   * Returns a constructed Point with given values.
   */
  Point(float x, float y);

  /**
   * Returns a copy of this POINT.
   */
  Point(const Point& rhs);
  /**
   * Returns the x value of this Point.
   */
  double getX() const;

  /**
   * Sets the x value of this Point.
   */
  void setX(float _x);

  /**
   * Returns the y value of this Point.
   */
  double getY() const;

  /**
   * Sets the y value of this Point.
   */
  void setY(float _y);
};
#endif
