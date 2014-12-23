//C library
#include <cstdlib>
#include <cstdio>
#include <cstring>
//C++ containers
#include <map>
#include <vector>
//Input/Output library
#include <iostream>
#include <fstream>
#include <sstream>
//other
#include <string>
#include <vector>
#include <dirent.h>//format of directory entries
#include <sys/types.h>//data types
#include <sys/stat.h>
#include <algorithm>
#include <errno.h>
//hashing functions
#include "md5.h"
#include "sha256.h"

//find all regular files
typedef std::map<std::string, std::string> filepath;
void addToMap(filepath * map, std::string fname);
std::string isDuplicate(filepath * map, std::string fname);
void showInScript(std::ofstream & outfile, std::string fname, std::string fnameMapped);
const std::string getHash(std::string fname);
