#include "node.h"
void Node::buildMap(BitString b, std::map<unsigned,BitString> & theMap) {
  //builds up a map which maps from each char that appears in the tree to the BitString representing the path to get to that character
  //if this node contains a symble(sym != NO_SYM)
  if (sym != NO_SYM){
    //the node is a leaf
    assert(left == NULL && right == NULL);
    //update theMap, it maps sym to the BitString representing the path to get to this node
    theMap.insert(std::pair<unsigned,BitString> (sym, b));
  } 
  else{
    //if this node does not contain a symble(sym == NO_SYM)
    //it is an internal node
    //both left and right should be non-NULL
    assert(left != NULL && right != NULL);
    //recurse to both the left and the right
    left->buildMap(b.plusZero(), theMap);
    right->buildMap(b.plusOne(), theMap);
  }
}

