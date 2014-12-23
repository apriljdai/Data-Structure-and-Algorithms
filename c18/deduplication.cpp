#include "deduplication.h"
#include <iostream>
#include <cstdlib>
#include <stdio.h>

void getDir(std::string dir, filepath * map, std::ofstream &outfile){
  //directory pointer
  DIR *directory;//DIR: a type representing a directory stream, display a list of files and subfolders
  //dir entry pointer
  struct dirent * enter;
  struct stat buf;
  std::cout << "dir is: " << dir << std::endl;
  directory = opendir(dir.c_str());  //DIR* opendir(const char *)
  std::cout << "The directory is " << directory << std::endl;
  if (dir.at(dir.length() - 1) != '/'){
    dir = dir + "/";
  }
  if (directory != NULL){
    while ((enter = readdir(directory))){
      if (strcmp(enter->d_name, ".") != 0 && strcmp(enter->d_name, "..") != 0){
          if (lstat((dir + enter->d_name).c_str(), &buf) != -1){
	      if (S_ISDIR(buf.st_mode)) {
	          //protection mode; S_ISDIR:test for a directory
                  std::cout << "a directory!\n";
	          getDir(dir + enter->d_name, map, outfile);
               }
	       else if (S_ISREG(buf.st_mode)){//S_ISREG: test for a regular file
                  std::cout << "a file!\n";
	          std::string fnameMapped = isDuplicate(map, dir+enter->d_name);
	          if (fnameMapped != "") {
                      showInScript(outfile, dir+enter->d_name, fnameMapped);
                  }
	          else {
   	              addToMap(map, dir+enter->d_name);
	          }
               }
           }
           else {
               perror("Could not get the file information!");
           }
        }
     }
    closedir(directory);
  }
    else {
        perror("Could not open the directory!");
    }
}

const std::string getHash(std::string fname){
  std::ifstream f;
  f.open(fname.c_str());
  SHA256 digest;
  const size_t BufferSize = 144 * 7 * 1024;
  char * buffer = new char[BufferSize];
  if (f != NULL){
    f.read(buffer, BufferSize);//read(char *s, streamsize n)
    std::size_t numByte = size_t(f.gcount());//gcount(): return the number of characters extracted by the last unformatted input operation
    digest.add(buffer, numByte);
  }
  f.close();
  delete[] buffer;
  return digest.getHash();
}

void addToMap(filepath * map, std::string fname){
  std::string hashString = getHash(fname);
  (*map)[hashString] = fname;
}

std::string isDuplicate(filepath * map, std::string fname){
  std::string hashString = getHash(fname);
  //there's no duplicate 
  if (map->find(hashString) == map->end())//search the container for an element with a key, returns map:end if no key found
    return "";
  else
    return (*map)[hashString];
}

void showInScript(std::ofstream & outfile, std::string fname, std::string fnameMapped){
  outfile <<"#Removing " << fname << " (duplicate of " << fnameMapped << ")." << std::endl;
  outfile << "rm " << fname << std::endl;
}

int main(int argc, char * argv[]){
  //take as command line arguments 1 or more directory names
  if (argc < 2){
    fprintf(stderr, "Usage: deduplication directory\n");
    return EXIT_FAILURE;
  }
  else{
    //program's output is a shell script
    std::ofstream outfile("deduplicate.sh");
    //first print #!/bin/bash
    outfile << "#!/bin/bash" << std::endl;
    filepath * map = new filepath();
    for (int i = 1; i < argc; i++){
      std::string dir = argv[i];
      std::cout << "dir is " << dir << std::endl;
      getDir(dir, map, outfile);
    }
    outfile.close();
    delete map;
    std::cout << "Finshied generating shell script." << std::endl;
  }
  return EXIT_SUCCESS;
}
