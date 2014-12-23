&#ifndef _BSTMAP_H_
#define _BSTMAP_H_
#include <cstdlib>
#include "map.h"
#include <exception>
#include <iostream>

template<typename K, typename V>
  class BstMap{
 private:
  class BSTNode{
  public:
    K key;
    V value;
    BSTNode * left;
    BSTNode * right;
  BSTNode():key(), value(), left(NULL), right(NULL){}
  BSTNode(K k,V v):key(k),value(v),left(NULL),right(NULL){}
  BSTNode(K k,V v, BSTNode * l, BSTNode * r):key(k),value(v),left(l),right(r){}
  ~BSTNode(){}
  };
  BSTNode * root;
 public:
 BstMap():root(NULL){}
  BstMap(const BstMap<K,V> &rhs){
    root = copy(rhs.root);
  }
  BSTNode * copy(const BSTNode * node){
    if (node == NULL)
      return NULL;
    BSTNode * newRoot = new BSTNode(node->key, node->value);
    //newRoot->key = node->key;
    //newRoot->value = node->value;
    if (node->left != NULL)
      newRoot->left = copy(node->left);
    if (node->right != NULL)
      newRoot->right = copy(node->right);
    return newRoot;
  }
  BstMap<K,V> & operator=(const BstMap<K,V> & rhs){
    assert(this != &rhs);
    clear(root);
    root = copy(rhs.root);
    return *this;
  }
  void clear(const BSTNode * node){
    if (node == NULL)
      return;
    if (node->left != NULL)
      clear(node->left);
    if (node->right != NULL)
      clear(node->right);
    delete node;
  }
  ~BstMap(){
    clear(root);
  }
  virtual void add(const K & key, const V & value){
    BSTNode * bst = new BSTNode(key, value);
    BSTNode ** ptr = &root;
    while (*ptr != NULL){
      if (key == (*ptr)->key){
	(*ptr)->value = value;
	delete bst;
	return;
      }
      if (key < (*ptr)->key)
	ptr = &(*ptr)->left;
      else
	ptr = &(*ptr)->right;
    }
    *ptr = bst;
  }

  virtual const V & lookup(const K& key) const throw (std::invalid_argument) {
    BSTNode * curr = root;
    while (curr != NULL){
      if (curr->key == key)
	return curr->value;
      if (key < curr->key)
	curr = curr->left;
      else
	curr = curr->right;
    }
    //return curr->value;
    throw std::invalid_argument("The key could not be found!");
  }

  virtual void remove(const K& key){
    root = remove(root, key);
  }
  BSTNode * remove(BSTNode * curr, const K& key){
    if (curr == NULL)
      return NULL;
    if(curr->key == key){
      BSTNode * temp;
      if (curr->left == NULL){
	temp = curr->right;
	delete curr;
	return temp;
      }
      if (curr->right == NULL){
	temp = curr->left;
	delete curr;
	return temp;
      }
      curr->left = twoChildRm(curr->left, curr);
      return curr;
    }
    else if (key < curr->key)
      curr->left = remove(curr->left, key);
    else
      curr->right = remove(curr->right, key);
    return curr;
  }
  BSTNode * twoChildRm(BSTNode * curr, BSTNode * replace){
    if (curr->right == NULL){
      replace->key = curr->key;
      replace->value = curr->value;
      BSTNode * temp = curr->left;
      delete curr;
      return temp;
    }
    curr->right = twoChildRm(curr->right, replace);
    return curr;
  }

  void printBSTInOrder(){
    printBSTInOrder(root);
  }
  void printBSTInOrder(BSTNode * node){
    if (node != NULL){
      printBSTInOrder(node->left);
      std::cout << node->key << ", " << node->value << std::endl;
      printBSTInOrder(node->right);
    }
  }
  void printBSTPreOrder(){
    printBSTPreOrder(root);
  }
  void printBSTPreOrder(BSTNode * node){
    if (node != NULL){
      std::cout << node->key << ", " << node->value << std::endl;
      printBSTInOrder(node->left);
      printBSTInOrder(node->right);
    }
  }
  void printBSTPostOrder(){
    printBSTPostOrder(root);
  }
  void printBSTPostOrder(BSTNode * node){
    if (node != NULL){
      printBSTInOrder(node->left);
      printBSTInOrder(node->right);
      std::cout << node->key << ", " << node->value << std::endl;
    }
  }
};

#endif

