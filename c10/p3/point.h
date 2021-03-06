#ifndef _POINT_H_
#define _POINT_H_

class Point{
 private:
  double x;
  double y;
 public:
  Point();
  double getX() const{ return x;}
  double getY() const {return y;}
  void move(double dx, double dy);
  //increase the point's x by dx, an its y by dy
  double distanceFrom(const Point & p);
  //reference to aother point, and computes the distance between the two points
};

#endif
