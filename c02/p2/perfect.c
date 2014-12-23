#include <stdlib.h>
#include <stdio.h>

int isPerfect (int x){
  //A positive number is "perfect" iff it is equal to the sum of its divisors, except for itself.
  int ans = 1;
  for (int i = 2; i < x; i++){
    if (x % i == 0)
      ans += i;
  }
  if (ans == x)
    return 1;
  else
    return 0;
}

int main (void){
  for (int i = 2; i < 10000; i++){
    if (isPerfect(i) == 1)
      printf("%d is perfect!\n", i);
  }
  return EXIT_SUCCESS;
}
