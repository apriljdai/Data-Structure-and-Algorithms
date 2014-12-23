#include <stdio.h>
#include <cstdlib>
#include "readFreq.h"
#include <fstream>
#include <iostream>

void printSym(std::ostream & s, unsigned sym) {
  if (sym > 256 ) {
    s << "INV";
  }
  else if (sym == 256) {
    s << "EOF";
  }
  else if (isprint(sym)) {
    char c = sym;
    s << "'" << c << "'";
  }
  else {
    std::streamsize w = s.width(3);
    s << std::hex << sym << std::dec;
    s.width(w);
  }
}
uint64_t * readFrequencies(const char * fname) {
  //opens the file
  std::ifstream f(fname);
  //build an array of the frequency of each character
  //return an array has 257 entries
  uint64_t * arr = new uint64_t[257];
  for (unsigned i = 0; i < 257; i++){
    arr[i] = 0;
  }
  while (f.good()){
    unsigned char c = f.get();
    if (f.good())
      //array have a count of how many times that character appears in the input
      //index 256 of the array to count the end of file marker
      arr[static_cast<int> (c)] += 1;
  }
  arr[256] = 1;
  f.close();
  return arr;
}
