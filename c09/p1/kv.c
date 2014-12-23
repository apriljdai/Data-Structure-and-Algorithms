#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"

kvpair_t * split(char * line){
  //printf("line is: %s\n", line);
  char * firstPart = strtok(line, "=");
  int firLen = strlen(firstPart);
  char * secondPart = strtok(NULL, "\n");
  int secLen = strlen(secondPart);
  kvpair_t * pair = malloc(sizeof(*pair));
  int i;
  if (firstPart != NULL){
    pair->key = malloc((firLen + 1)*sizeof(*(pair->key)));
    for (i = 0; i < firLen; i++){
      pair->key[i] = firstPart[i];
    }
    pair->key[i] = '\0';
  }
  //printf("key is: %s\n", pair->key);
  //printf("secondpart is: %s\n", secondPart);
  if (secondPart != NULL){
    //printf("secondpart bytes=%d\n", secLen+1);
    pair->value = malloc((secLen+1)*sizeof(*(pair->value)));
    for (i = 0; i < secLen; i++){
      pair->value[i] = secondPart[i];
    }
    pair->value[i] = '\0';
  }
  return pair;
}

kvarray_t * readKVs(const char * fname) {
  //open the file
  FILE * f = fopen(fname, "r");
  if (f == NULL){
    perror("Could not open the file!");
    return NULL;
  }
  kvarray_t * array = malloc (sizeof(*array));
  //initialize the array
  array->length = 0;
  array->pairs = NULL;
  //read the lines of text
  char * line = NULL;
  size_t size;
  while (getline(&line, &size, f) >= 0){
    //split them into key/value pairs
    kvpair_t * newPair = split(line);
    //add the resulting pairs to an array
    if (newPair != NULL){
      array->length++;
      //kinda not understand the size of the space
      array->pairs = realloc(array->pairs, array->length * sizeof(*(array->pairs)));
      array->pairs[array->length - 1] = newPair;
    }
  }
  free(line);
  //close the file
  if (fclose(f) != 0){
    perror("Could not close the file!");
    return NULL;
  }
  //return
  return array;
}

void freeKVs(kvarray_t * pairs) {
  //free all the memory allocated by readKVs
  for (int i = 0; i < pairs->length; i++){
    free(pairs->pairs[i]->key);
    free(pairs->pairs[i]->value);
    free(pairs->pairs[i]);
  }
  free(pairs->pairs);
  free(pairs);
}

void printKVs(kvarray_t * pairs) {
  //take a kvarray_t * and print out key = '%s' value = '%s\n'
  for (int i = 0; i < pairs->length; i++){
    printf("key = '%s' value = '%s'\n", pairs->pairs[i]->key, pairs->pairs[i]->value);
  }
}

char * lookupValue(kvarray_t * pairs, const char * key) {
  //takes a kvarray_t * and a char * 
  //searches the kvarray_t for a matching key
  for (int i = 0; i < pairs->length; i++){
    //returns the corresponding value when key found
    if (strcmp(pairs->pairs[i]->key, key) == 0)
      return pairs->pairs[i]->value;
  }
  //return NULL if no key matched
  return NULL;
}
