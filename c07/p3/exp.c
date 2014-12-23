#include <stdio.h>
#include <stdlib.h>

long power(long x, long y) {
  //write me
  if (y == 0)
    return 1;
  else
    return x * power(x, y - 1);
}

int main(void) {
  char * line = NULL;
  ssize_t read;
  size_t size;
  char * line2;
  char * line3;
  //a loop which reads a line (from stdin, using getline) has the format x^y
  //ssize_t getline(char **lineptr, size_t *n, FILE *stream)
  while ((read = getline(&line, &size, stdin)) != -1){
    //long int strtol(const char *nptr, char **endptr, int base)
    //convert the initial part of the string in nptr to a long integer value according to the given base(2 to 36)
    //endptr points to the first character that was not converted to a number
    long int num1 = strtol(line, &line2, 10);
    //print an error message to stderr if the format of the line is not correct
    if (line == line2){
      fprintf(stderr, "No first number has been found.\n");
      continue;
    }
    if (*line2 == '\0'){
      fprintf(stderr, "Only first number has been found.\n");
      continue;
    }
    if (*line2 != '^'){
      fprintf(stderr, "No exponent sign has been detected.\n");
      continue;
    }
    long int num2 = strtol(line2 + 1, &line3, 10);
    if (line2 + 1 == line3){
      fprintf(stderr, "No second number has been found.\n");
      continue;
    }
    if (*line3 != '\n'){
      fprintf(stderr, "Additional number has been found.\n");
      continue;
    }
    if (num2 < 0){
      num1 = 1 / num1;
      num2 = -num2;
    }
    //comput x to the y power 
    long int ans = power(num1, num2);
    //print out the result
    printf("%ld\n", ans);
  }
  if (line != NULL){
    free(line);
    line = NULL;
    line2 = NULL;
    line3 = NULL;
  }
  return EXIT_SUCCESS;
}
