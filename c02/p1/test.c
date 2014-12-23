#include <stdio.h>
#include <stdlib.h>

struct _point_t {
  int x;
  int y;
};
typedef struct _point_t point_t;

struct _two_points_t {
  point_t p1;
  point_t p2;
};
typedef struct _two_points_t two_points_t;

point_t aFunction (two_points_t p) {
  p.p1.x += p.p2.y;
  p.p2.x += p.p1.y;
  printf("p1: (%d,%d)\n", p.p1.x, p.p1.y);
  printf("p2: (%d,%d)\n", p.p2.x, p.p2.y);
  return p.p1;
}

int main(void) {
  two_points_t tp;
  tp.p1.x = 3;
  tp.p1.y = 4;
  tp.p2.x = 1;
  tp.p2.y = 2;
  point_t c = aFunction (tp);
  
  printf("tp.p1: (%d,%d)\n", tp.p1.x, tp.p1.y);
  printf("tp.p2: (%d,%d)\n", tp.p2.x, tp.p2.y);
  printf("c: (%d,%d)\n", c.x, c.y);
  
  int x = 'e' - 'a';
  int y = 'M' - 'L';
  int z = '7' - '2';
  printf("x: %d\n", x);
  printf("y: %d\n", y);
  printf("z: %d\n", z);

  return EXIT_SUCCESS;
}
