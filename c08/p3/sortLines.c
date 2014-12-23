#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ** readLine(FILE * f, int * numLine){
  char * line = NULL;
  char ** data = NULL;
  size_t size;
  while (getline(&line, &size, f) >= 0){
    data = (char **) realloc(data, (*numLine + 1)*sizeof(*data));
    data[*numLine] = malloc(strlen(line) + sizeof(line[0]));
    strcpy(data[*numLine], line);
    (*numLine)++;
  }
  free(line);
  line = NULL;
  return data;
}

void printAndfree(char ** line, int numLine){
  if (line != NULL){
    for (int i = 0; i < numLine; i++){
      printf("%s", line[i]);
      free(line[i]);
      line[i] = NULL;
    }
    free(line);
    line = NULL;
  }
}

//This function is used to figure out the ording 
//of the strings in qsort.  You do not need
//to modify it.
int stringOrder(const void * vp1, const void * vp2){
  const char * const * p1 = vp1;
  const char * const * p2 = vp2;
  return strcmp(*p1, *p2);
}

/* This function will sort and print data (whose length is count)
   data: array of strings.
   count: length of array - how many strings it contains
*/
void sortData(char ** data, size_t count){
  qsort(data, count, sizeof(char *), stringOrder);
}

int main(int argc, char ** argv){
  // if argc == 1
  if (argc == 1){
    int numLine = 0;
    //read from stand input
    char  ** data = readLine(stdin, &numLine);
    //sort lines
    sortData(data, numLine);
    //print the results
    //free memory
    printAndfree(data, numLine);
  }
  // if argc > 1
  if (argc > 1){
    //read all the files
    for (int i = 1; i < argc; i++){
      FILE * f = fopen(argv[i], "r");
      if (f == NULL){
	perror("Could not open the file!");
	return EXIT_FAILURE;
      }
      int numLine = 0;
      char ** data = readLine(f, &numLine);
      //sort lines
      sortData(data, numLine);
      //print the result
      //free memory
      printAndfree(data, numLine);
      if (fclose(f) != 0){
	perror("Could not close the file!");
	return EXIT_FAILURE;
      }
    }
  }
  return EXIT_SUCCESS;
}
