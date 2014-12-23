#include <cstdlib>
#include "bstset.h"
#include <iostream>

int main(void){
  BstSet<int> *bst1 = new BstSet<int>();
  bst1->add(17);
  bst1->add(9);
  bst1->add(6);
  bst1->add(29);
  bst1->add(37);
  bst1->add(2);
  std::cout << "BST Set integer printed inorder is: "<< std::endl;
  bst1->inOrder();
  //std::cout << "BST Set integer printed preorder is: ";
  //printPreorder(bst);
  //std::endl;
  //std::cout << "BST Set integer printed postorder is: ";
  //printPostorder(bst);
  //std::endl;
  bool s1 = bst1->contains(2);
  bool s2 = bst1->contains(29);
  bool s3 = bst1->contains(1);
  std::cout << "BST Set contains 2 is: " << s1 << std::endl;
  std::cout << "BST Set contains 29 is: "<< s2 << std::endl;
  std::cout << "BST Set contains 1 is: " << s3 << std::endl;
  bst1->remove(2);
  bst1->remove(37);
  std::cout << "After remove 2 and 37, the new BST Set inorder is: " << std::endl;
  bst1->inOrder();
  delete bst1;
  return EXIT_SUCCESS;
}
