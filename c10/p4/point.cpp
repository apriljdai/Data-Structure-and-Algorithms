#include "point.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

Point::Point(): x(0), y(0){

}

void Point::move(double dx, double dy){
  x += dx;
  y += dy;
}

double Point::distanceFrom(const Point & p){
  double dis = sqrt((x - p.getX())*(x - p.getX()) + (y - p.getY())*(y - p.getY()));
  return dis;
}
