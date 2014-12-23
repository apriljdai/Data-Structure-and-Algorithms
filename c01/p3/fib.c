#include <stdio.h>
#include <stdlib.h>

int fib (int n){
  //if n < 0, fib(n) = 0
  if (n < 0)
    return 0;
  //base case: n = 0 && n = 1
  if (n == 0)
    return 0;
  if (n == 1)
    return 1;
  //recursion when n >= 2
  return fib (n - 1) + fib (n - 2);
}

int main(void){
  for (int i = -2; i <= 30; i++){
    printf("fib(%d) = %d\n", i, fib(i));
  }
  return EXIT_SUCCESS;
}
