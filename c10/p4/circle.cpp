#include <stdlib.h>
#include "circle.h"
#include <stdio.h>
#include <math.h>
#define PI 3.1415926
Circle::Circle(Point p, double d): center(p), radius(d){
  //initializes the center and radius
}

Circle::Circle(): center(Point()), radius(0){

}

void Circle::move(double dx, double dy){
  //moves the circle's center by dx,dy
  center.move(dx, dy);
}

double Circle::intersectionArea(const Circle & otherCircle){
  //computs the area of the intersection of this circle and otherCircle
  Point center1 = otherCircle.getPoint();
  double radius1 = otherCircle.getRadius();
  // printf("other circle's radius is %f\n", radius1);
  //check if two circles are intersected
  double dis = center.distanceFrom(center1);
  //printf("circle's radius is %f\n", radius);
  //printf("distance of two circles are %f\n", dis);
  double twoRadius = radius + radius1;
  double intersection;
  double r = radius;
  //printf("r is %f, ", r);
  double R = radius1;
  //printf("R is %f\n", R);
  if (dis >= twoRadius || r == 0 || R == 0){
    return 0;
  }
  if (dis == 0){
    return (r > R) ? R * R * PI : r * r * PI; 
  }
  if (dis <= fabs(r - R)){
    return (r > R) ? R * R * PI : r * r * PI; 
  }
  //compute the intersection area
  else{
    /*if (R < r){
      r = radius1;
      R = radius;
      //printf("now r is %f, R is %f\n", r, R);
    }
*/
    double part1 = r * r * acos((dis * dis + r * r - R * R) / (2 * r * dis));
    //printf("part1 is %f\n", part1);
    double part2 = R * R * acos((dis * dis + R * R - r * r) / (2 * dis * R));
    //printf("part2 is %f\n", part2);
    double part3 = 0.5 * sqrt((r + R - dis) * (dis + r - R) * (dis - r + R) * (dis + r + R));
    //printf("part3 is %f\n", part3);
    intersection = part1 + part2 - part3;
    //printf("intersection is %f\n", intersection);
    //compute two points of intersection
    //x = (x + x1)/2 + (x1 - x)*(radius1 * radius1 - radius * radius)/ (2 * dis)+-2 * (y - y1);
    //calculate the area of two triangles
    //area = 2 * radius * sin(0.5 * angle) * radius * cos(0.5 * angle) / 2;
    //calculate the area of two fans
    //area = angle * radius * radius / 2
    //get the intersection area
  }
  return intersection;
}
