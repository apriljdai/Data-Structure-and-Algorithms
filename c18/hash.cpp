#include "deduplication.h"

int main(int argc, char * argv[]){
  if (argc != 2){
    perror("Usage: hash filename.");
    return EXIT_FAILURE;
  }

  MD5 digestMd5;
  //make a SHA256 hash of a file
  std::ifstream f;
  f.open(argv[1]);
  const size_t BufferSize = 144 * 7 * 1024;
  char *buffer = new char[BufferSize];

  if (f != NULL){
    f.read(buffer, BufferSize);
    std::size_t numByte = size_t(f.gcount());
    digestMd5.add(buffer, numByte);
  }
  f.close();
  delete[] buffer;
  //results
  std::cout << "MD5: " << digestMd5.getHash() << std::endl;
  return EXIT_SUCCESS;
}
