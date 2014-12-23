#include <stdio.h>
#include <stdlib.h>



int * initArray(int * array, int n){
  for (int i = 0; i < n; i++){
    array[i] = i;
  }
  return array;                       
}

int * aFunction(int n) {
  int myArray[n];
  
  int * ptr = initArray(myArray, n-1);
  int total = 0;
  for (int i = 0; i <= n; i++) {      //use of uninitialized value when i = 7
    printf("%d\n", myArray[i]);       //index out of bounds when i = 8
    total += ptr[i];                  //*2
  }
  printf("Total = %d\n", total);
  return myArray;                     //return dangling pointer
}

int main (void) {
  int * ptr = aFunction(8);           //use of dangling pointer
  printf("%d\n", ptr[0]);
  return EXIT_SUCCESS;
}
