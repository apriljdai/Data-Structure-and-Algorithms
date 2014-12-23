#include <stdlib.h>
#include <stdio.h>

void buildMatrix(FILE * f, char matrix[][10]){
  for (int i = 0; i < 10; i++){
    int c;
    int j = 0;
    while (((c = fgetc(f)) != EOF) && (c != '\n')){
      matrix[i][j] = c;
      j++;
    }
  }
}

void rotate(char matrix[][10]){
  for (int i = 0; i < 5; i++){
    for (int j = 0; j < 5; j++){
      char temp = matrix[i][j];
      matrix[i][j] = matrix[9 - j][i];
      matrix[9 - j][i] = matrix[9 - i][9 - j];
      matrix[9 - i][9 - j] = matrix[j][9 - i];
      matrix[j][9 - i] = temp;
    }
  }
}

void printMatrix(char matrix[][10]){
  for (int i = 0; i < 10; i++){
    for (int j = 0; j < 10; j++){
      printf("%c", matrix[i][j]);
    }
    printf("\n");
  }
}

int main(int argc, char ** argv){
  if (argc != 2){
    fprintf(stderr, "Usage: rotate inputFileName\n");
    return EXIT_FAILURE;
  }
  FILE * f = fopen(argv[1], "r");
  if (f == NULL){
    perror("Could not open file");
    return EXIT_FAILURE;
  }
  char matrix[10][10];
  buildMatrix(f, matrix);
  rotate(matrix);
  printMatrix(matrix);
  if (fclose(f) != 0){
    perror("Failed to close the input file!");
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
