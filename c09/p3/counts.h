#ifndef __COUNTS_H__
#define __COUNTS_H__
struct _one_count_t {
  //information about one count
  char * info;
  //times we have seen it
  int times;
};
typedef struct _one_count_t one_count_t;

struct _counts_t {
  //array of the first
  one_count_t ** array;
  // the size of the array
  int size;
};
typedef struct _counts_t counts_t;

counts_t * createCounts(void);
void addCount(counts_t * c, const char * name);
void printCounts(counts_t * c, FILE * outFile);

void freeCounts(counts_t * c);

#endif
