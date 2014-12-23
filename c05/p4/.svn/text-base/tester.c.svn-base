#include <stdio.h>
#include <stdlib.h>
#include "code.h"

int main(void) {
  //WRITE TESTS HERE FOR THE CODE
  int array1[] = {10, 3, 2, 9, 1};
  int n1 = 5, v1 = 5;
  f (array1, n1, v1);
  //array1 -> path 1, no loop and false check
  int array2[] = {1, 2, 3, 4, 6};
  int n2 = 5, v2 = 5;
  f (array2, n2, v2);
  //array2 -> path 6, 2 loops and true check
  int array3[] = {6};
  int n3 = 1, v3 = 17;
  f (array3, n3, v3);
  //array3 -> path 0, no loop and true check
  int array4[] = {6, 7};
  int n4 = 2, v4 = 10;
  f (array4, n4, v4);
  //array4 -> path 4, i loop and true check
  int array5[] = {10, 12, 14, 16, 18};
  int n5 = 5, v5 = 5;
  f (array5, n5, v5);
  //array5 -> path 2, j loop and true check
  int array6[] = {1, 10, 12, 14, 4};
  int n6 = 5, v6 = 5;
  f (array6, n6, v6);
  //array6 -> path 5, i loop and false check
  int array7[] = {10, 1, 2, 6, 17};
  int n7 = 5, v7 = 5;
  f (array7, n7, v7);
  //array7 -> path 3, j loop and false check
  int array8[] = {1, 6, 2, 3, 17};
  int n8 = 5, v8 = 5;
  f (array8, n8, v8);
  //array8 -> path 7, 2 loops and false check
#ifdef REPORT_COVERAGE
  reportPathCoverage();
#endif
  return EXIT_SUCCESS;
}
