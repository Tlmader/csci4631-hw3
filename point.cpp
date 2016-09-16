/**
 * Implements functions for Points.
 * @author Ted Mader
 * @date 2016-09-12
 */

#include "point.hpp"

Point::Point() {
  x = 0;
  y = 0;
}

Point::Point(float _x, float _y) {
  x = _x;
  y = _y;
}

Point::Point(const Point &rhs) {
  x = rhs.x;
  y = rhs.y;
}

double Point::getX() const {
  return x;
}

void Point::setX(float _x) {
  x = _x;
}

double Point::getY() const {
  return y;
}

void Point::setY(float _y) {
  y = _y;
}
