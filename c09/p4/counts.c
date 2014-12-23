#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "counts.h"
counts_t * createCounts(void) {
  //allocate memory for a counts_t structure
  counts_t * count = malloc(sizeof(*count));
  //initialize it to represent that nothing has been counted yet
  count->array = NULL;
  count->size = 0;
  return count;
}
void addCount(counts_t * c, const char * name) {
  for (int i = 0; i < c->size; i++){
    //account for name be NULL
    if ((name == NULL) && (strcmp(c->array[i]->info, "<unknown>") == 0)){
      c->array[i]->times++;
      return;
    }
    //increment the count for the corresponding name
    //if the name has already been there
    if ((name != NULL) &&(strcmp(name, c->array[i]->info) == 0)){
      c->array[i]->times++;
      return;
    }
  }
  //if no same has been found
  c->size++;
  c->array = realloc(c->array, c->size * sizeof(*(c->array)));
  c->array[c->size - 1] = malloc(sizeof(*(c->array[c->size - 1])));
  if (name == NULL){
    c->array[c->size - 1]->info = malloc(10 * sizeof(*name));
    strcpy(c->array[c->size - 1]->info, "<unknown>");
  }
  else{
    c->array[c->size - 1]->info = malloc((strlen(name) + 1) * sizeof(*name));
    strcpy(c->array[c->size - 1]->info, name);    
  }
  c->array[c->size - 1]->times = 1;
}
void printCounts(counts_t * c, FILE * outFile) {
  //unkown must be listed at buttom
  one_count_t * unknown = NULL;
  for (int i = 0; i < c->size; i++){
  //name: #
    if (strcmp(c->array[i]->info, "<unknown>") == 0){
      unknown = c->array[i];
    }
    else{
      fprintf(outFile, "%s: %d\n", c->array[i]->info, c->array[i]->times);
    }
  }
  if (unknown != NULL){
    fprintf(outFile, "%s: %d\n", unknown->info, unknown->times);
  }
  if (fclose(outFile) != 0){
    perror("Could not close the outFile!");
  }
}

void freeCounts(counts_t * c) {
  //free all the memory associated with c
  for (int i = 0; i < c->size; i++){
    free(c->array[i]->info);
    free(c->array[i]);
  }
  free(c->array);
  free(c);
}
