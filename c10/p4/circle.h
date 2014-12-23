#ifndef _CIRCLE_H_
#define _CIRCLE_H_
#include "point.h"

class Circle{
 private:
  Point center;
  const double radius;
 public:
  Circle(Point p, double d);
  Circle();
  Point getPoint() const{return center;}
  double getRadius() const{return radius;}
  void move(double dx, double dy);
  double intersectionArea(const Circle & otherCircle);
};

#endif
