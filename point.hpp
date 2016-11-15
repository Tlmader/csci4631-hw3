/**
 * Contains function declarations for a Point.
 * @author Ted Mader
 * @date 2016-09-12
 */

#ifndef POINT_H
#define POINT_H

class Point {

public:
  /**
   * Constructs a Point with values set to 0.
   *
   * @return the constructed Point
   */
  Point();

  /**
   * Constructs a Point with given values.
   *
   * @param x a value for x
   * @param y a value for y
   * @return the constructed Point
   */
  Point(float x, float y);

  /**
   * Returns a copy of this Point.
   *
   * @return the copied Point
   */
  Point(const Point& rhs);
  /**
   * Returns the x value of this Point.
   *
   * @return the value for x
   */
  double getX() const;

  /**
   * Sets the x value of this Point.
   *
   * @param _x the new value for x
   */
  void setX(float _x);

  /**
   * Returns the y value of this Point.
   *
   * @return the value for y
   */
  double getY() const;

  /**
   * Sets the y value of this Point.
   *
   * @param _y the new value for y
   */
  void setY(float _y);

private:
  float x;
  float y;
};

#endif
