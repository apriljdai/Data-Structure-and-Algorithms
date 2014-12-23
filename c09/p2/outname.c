#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "outname.h"

char * computeOutputFileName(const char * inputName) {
  //WRITE ME
  int nameLen = strlen(inputName);
  char  * outName = (char *)malloc((nameLen + 8)*sizeof(*outName));
  //add counts at the end of the input file name
  strcpy(outName, inputName);
  strcat(outName, ".counts");
  //appends the src string to the dest string, overwriting the terminating null byte('\0') at the end of dest, and then adds a terminating null byte
  return outName;
}
