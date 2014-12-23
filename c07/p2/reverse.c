#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void reverse_help(char * str, char * arr,  int index){
  if (index < 0){
    printf("\n");
  }
  else{
    *arr = str[index];
    printf("%c", *arr);
    arr += 1;
    index--;
    reverse_help(str, arr, index);
  }
}

void reverse(char * str){
  int len = strlen(str);
  char arr[len];
  if (str[len - 1] != '\n')
    reverse_help(str, arr, len - 1);
  else
    reverse_help(str, arr, len - 2);
}

int main(void){
  char buffer[500];
  while (fgets(buffer, 500, stdin) != NULL){
    reverse(buffer);
  }
  return EXIT_SUCCESS;
}
