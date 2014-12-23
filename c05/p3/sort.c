#include <stdio.h>
#include <stdlib.h>

void swap (int * a, int * b) {
  int temp = * a;
  *a = *b;
  *b = temp;
}

void bubbleSort(int * array, int n) {
  int done = 0;
  while (!done) {
    int check = 1;
    for (int i = 0; i < n - 1 ; i++) {
      if (array[i] > array[i+1]) {
	swap(&array[i],&array[i+1]);
	check = 0;
      }
    }
    n--;
    done = (check == 0)?0:1;
  }
}

int main(int argc, char ** argv) {
  int data[argc-1];
  for (int i = 0; i < argc-1; i++) {
    data[i] = atoi(argv[i+1]);
  }
  bubbleSort(data, argc-1);
  for (int i =0; i < argc-1; i++) {
    printf("%d\n", data[i]);
  }
  return EXIT_SUCCESS;
}
