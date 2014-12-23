#include <stdio.h>
#include <stdlib.h>

struct _point_t {
  long x;
  long y;
};

typedef struct _point_t point_t;
typedef point_t vector_t;

//start: the point to start from
//directions: the (backwards) directions (as an array)
//n: how many directions are in the array directions
point_t follow(point_t start, vector_t * directions, int n) {
  if (n == 1){
    start.x -= (*directions).x;
    start.y -= (*directions).y;
    printf("Go to (%ld,%ld)\n", start.x, start.y);
    return start;
  }
  start = follow(start, directions + 1, n - 1);
  return follow(start, directions, 1);
}

//given a line (e.g. ("3,4") convert it to a vector_t
vector_t lineToPoint(const char * line) {
  vector_t direction;
  char * mid;
  char * end;
  direction.x = strtol(line, &mid, 10);
  if (*mid != ','|| mid == line){
      fprintf(stderr, "Invalid vector!\n");
      exit (EXIT_FAILURE);
  }
  direction.y = strtol(mid + 1, &end, 10);
  if (*end != '\n'|| end == mid + 1){
    fprintf(stderr, "Invalid vector!\n");
    exit (EXIT_FAILURE);
  }
  /* if (line != NULL){
    free(mid);
    mid = NULL;
    free(end);
    end = NULL;
  }
  */
  return direction;
}

//given a FILE *f, read all the lines.
//v is the memory allocated to hold all the previous lines
// (as an array of vector_t)s
//n points at an int, which says how many items are already in v.
//that is *n is the length of v.
// this function will update *n whenever it reads more items,
// so that when it returns to its original caller, the int
// whose address was passed in will indicate the lenght of the
// returned array
vector_t * readVector(FILE * f, vector_t * v, int * n) {
  char * line = NULL;
  size_t size = 0;
  ssize_t read;
  vector_t direction;
  if ((read = getline(&line, &size, f)) == -1){
    free(line);
    return v;
  }
  else{
    direction = lineToPoint(line);
    (*n)++;
    v = (vector_t *) realloc(v, (*n) * sizeof(*v));
    v[(*n) - 1] = direction;
    free(line);
    line = NULL;
    return readVector(f, v, n);
  }
}

int main(int argc, char ** argv) {
  if (argc != 2){
    fprintf(stderr, "Usage: ant inputFileName\n");
    return EXIT_FAILURE;
  }
  FILE * f = fopen(argv[1], "r");
  if (f == NULL){
    perror("Could not open file");
    return EXIT_FAILURE;
  }
  int numLine = 0;
  vector_t * vec = malloc(numLine * sizeof(*vec));
  vec = readVector(f, vec, &numLine);
  point_t start = {0, 0};
  start.x = 0;
  start.y = 0;
  start = follow(start, vec, numLine);
  printf("Food at (%ld,%ld)\n", start.x, start.y);
  free(vec);
  vec = NULL;
  if (fclose(f) != 0){
    perror("Failed to close the input file!");
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
