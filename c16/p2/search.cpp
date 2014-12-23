#include <cstdlib>
#include "function.h"
#include <math.h>
#include <iostream>

/*
//find the x-value for which the y-value is closest to 0
  int binarySearchForZero(Function<int, int> * f, int low, int high){
  //return low if f(x) is all positive
  if (f->invoke(low) > 0)
    return low;
  //return hi - 1 if f(x) is all negative
  if (f->invoke(high - 1) < 0)
  return high - 1;
  int mid; 
  while (low < high - 1){
    
    //if (low == high - 2)
      //return (abs(f->invoke(low)) > abs(f->invoke(high - 1))) ? high - 1 : low;
    mid = (low + high) / 2;
    //std::cout << "mid = " << mid << std::endl;
    int y = f->invoke(mid);
    //std :: cout << "y = " << y << std::endl;
    if (y == 0)
      return mid;
    if (y < 0)
      low = (abs(f->invoke(mid + 1)) < abs(y)) ? mid + 1 : mid;
    else
      high = (abs(f->invoke(mid - 1)) < abs(y)) ? mid : mid + 1;
    //std::cout << "low = " << low << ", ";
    //std::cout << "high = " << high << std::endl;
    //mid = (low + high) / 2;
  }
  return low;
}
*/
int binarySearchForZero(Function<int, int> * f, int low, int high){
  /*
  if (f->invoke(low) >= 0){
    std::cout << "invoke base case1!"<<std::endl;
    return low;
  }
  if (f->invoke(high) <= 0){
    std::cout << "invoke base case2!"<< std::endl;
    return high;
  }
  */
  int y;
  high--;
  while (low <= high){
    //int mid = (low + high) / 2;
    int mid = low + (high - low) / 2;
    y = f->invoke(mid);
    //std::cout << "invoke y!" << std::endl;
    //std::cout << "y is: " << y << std::endl;
    if (y == 0)
      return mid;
    if (y < 0)
      low = mid + 1;
    else
      high = mid - 1;
  }
  /*
  if (low == high){
    //std::cout << "invoke low == high case!"<<std::endl;
    return (abs(f->invoke(high) < abs(y))) ? high : high - 1;
  }
  */
  //else{
    //std::cout << "invoke low == high - 1 case!" << std::endl;
  return (abs(f->invoke(high)) < abs(f->invoke(low)))? high : low;
  //}
}





