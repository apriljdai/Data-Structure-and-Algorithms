#include <stdio.h>
#include <stdlib.h>

int isPrime(int n){
  if (n ==2)
    return 1;
  for (int i = 2; i < n; i++){
    if (n % i == 0)
      return 0;
  }
  return 1;
}

void printFactors(int n) {
  //print an empty line if n = 1
  if (n == 1)
    printf("\n");
  int i = 2;
  while (i < n){
    int x = isPrime(i);
    if (x == 1 && n % i == 0){
      printf("%d * ", i);
      n = n / i;
    }
    else
      i++;
  }
  if (i == n)
    printf("%d\n", i);
}

int main(void) {
  printf("Factorization of 1:\n");
  printFactors(1);
  printf("Factorization of 60:\n");
  printFactors(60);
  printf("Factorization of 132:\n");
  printFactors(132);
  printf("Factorization of 11726:\n");
  printFactors(11726);
  printf("Factorization of 2169720:\n");
  printFactors(2169720);
  printf("Factorization of 1789220887:\n");
  printFactors(1789220887);
  return EXIT_SUCCESS;
}
