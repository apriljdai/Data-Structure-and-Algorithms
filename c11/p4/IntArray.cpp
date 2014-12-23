#include "IntArray.h"
#include <assert.h>
#include <iostream>

IntArray::IntArray(): data(NULL), numElements(0) {
  //initializes the size to 0, and the array to NULL
}
IntArray::IntArray(int n): data(new int[n]), numElements(n) {
  //initializes the size to n, and the array to hold that many ints
}

IntArray::IntArray(const IntArray & rhs)  {
  //perform a deep copy
  numElements = rhs.numElements;
  data = new int[numElements];
  for (int i = 0; i < numElements; i++){
    data[i] = rhs.data[i];	
  }
  //data = new int(*rhs.data);
}
IntArray::~IntArray() {
  //releases any allocated memory
  delete[] data;
}

IntArray & IntArray::operator=(const IntArray & rhs) {
  //perform a deep copy
  if (this != & rhs){
    int * temp = new int[rhs.numElements];
    delete[] data;
    numElements = rhs.numElements;
    data = temp;
    for (int i = 0; i < numElements; i++){
      data[i] = rhs.data[i];
    }
  }
  return *this;
}

const int & IntArray::operator[](int index) const {
  //if the index is in bounds (use assert)
  assert (index < numElements);
  //returns a reference to the appropriate element
  return  data[index];
}
int & IntArray::operator[](int index) {
  assert (index < numElements);
  return data[index];
}

int IntArray::size() const {
  //returns the size of the array
  return numElements;
}

bool IntArray::operator==(const IntArray & rhs) const {
  //checks two arrays if they have the same contents
  if (numElements != rhs.numElements)
    return false;
  for (int i = 0; i < numElements; i++){
    if(data[i] != rhs.data[i])
      return false;
  }
  return true;
}

bool IntArray::operator!=(const IntArray & rhs) const {
  return !((*this) == rhs);
}

std::ostream & operator<<(std::ostream & s, const IntArray & rhs) {
  s << "{";
  int i;
  for (i = 0; i < rhs.numElements - 1; i++){
    s << rhs.data[i] << ", ";
  }
  s << rhs.data[i] << "}";
  return s;
}
