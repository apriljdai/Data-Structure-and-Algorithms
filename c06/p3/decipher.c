#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int max(int * a){
  int index = 0;
  int max = a[0];
  for (int i = 1; i < 26; i++){
    if (a[i] > max){
      max = a[i];
      index = i;
    }
  }
  return index;
}

int findE(FILE * f){
  int array[26] = {0};
  int c;
  while ((c = fgetc(f))!= EOF){
    if (isalpha(c)){
      c = tolower(c);
      int i = c - 'a';
      array[i] ++;
    }
  }
  int e = max(array);
  int key = e - 4;
 if (key < 0){
    key += 26;
  }
  return key;
}
 
int main (int argc, char ** argv){
  //check the value of argc
  if (argc != 2){
    fprintf(stderr, "Usage: decipher inputFileName\n");
    return EXIT_FAILURE;
  }
  //open the file and check if it is empty
  FILE * f = fopen(argv[1], "r");
  if (f == NULL){
    perror("Could not open file");
    return EXIT_FAILURE;
  }
  //invoke findE function to find the e character
  int key = findE(f);
  printf("%d\n", key);
  //check if the file could be closed 
  if (fclose(f) != 0){
    perror("Failed to close the input file!");
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
