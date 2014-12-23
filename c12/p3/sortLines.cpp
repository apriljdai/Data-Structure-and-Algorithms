#include <iostream>
#include <algorithm>   //std::sort
#include <vector>      //std::vector
#include <fstream>

int main(int argc, char ** argv){
  std::string  str;
  std::vector<std::string> vec;
  //std::cin read from standard input
  //std::ifstreams: read files
  if (argc == 1){
    if (!std::cin.good()){
      std::cin.clear();
      std::string badinput;
      std::getline(std::cin, badinput);
      std::cout << badinput << "wasn't a string!\n";
    }
    else{
      while (getline(std::cin, str)){
	//std::getline(std::cin, str);
	vec.push_back(str);
	str.clear();
      }
    }
  }
  else{
    for (int i = 1; i < argc; i++){
      std::ifstream f(argv[i]);
      if (!f.good()){
	std::cout << "The file does NOT exist!\n";
      }
      else{
	while (getline(f, str)){
	  vec.push_back(str);
	  str.clear();
	} 
      //std::vector: hold the strings that you read in
      //std::sort: sort the vector
      }
    }
  }
  std::sort(vec.begin(), vec.end());
  //std::cout: print the strings
  for (std::vector<std::string>::size_type i = 0; i < vec.size(); i++){
    std::cout << vec[i] << std::endl;
  }
  return EXIT_SUCCESS;
}
