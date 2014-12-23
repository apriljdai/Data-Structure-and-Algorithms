#include <stdio.h>
#include <stdlib.h>

class MyClass {
private:
  int a;
  int b;
public:
  MyClass() : a(3), b(4) {
    printf("Creating MyClass\n");
  }
  ~MyClass() {
    printf("Destroying with a=%d, b=%d\n",a, b);
  }
  void mathify(int x) {
    a = a * x + b;
    b = b - x;
    printf("Math resulted in a=%d b=%d\n",a,b);
  }
};

int main(void) {
  MyClass ** array = new MyClass*[4];
  printf("First loop\n");
  for (int i = 0; i < 4; i++) {
    array[i] = new MyClass();
  }
  printf("Second loop\n");
  for (int i = 0; i < 4; i++) {
    array[i]->mathify(i);
  }
  printf("Third loop\n");
  for (int i = 0; i < 4; i++) {
    delete array[i];
  }
  printf("Done looping\n");
  delete[] array;
  return EXIT_SUCCESS;
}

/*
 output:
 First loop
 Creating MyClass
 Creating MyClass
 Creating MyClass
 Creating MyClass
 Second loop
 Math resulted in a=4 b=4
 Math resulted in a=7 b=3
 Math resulted in a=10 b=2
 Math resulted in a=13 b=1
 Third loop
 Destroying with a=4, b=4
 Destroying with a=7, b=3
 Destroying with a=10, b=2
 Destroying with a=13, b=1
 Done looping
