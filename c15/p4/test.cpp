#include "ll.h"
#include "function.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

//function for filter
template<typename T>
class DivideTwo: public Function<bool, const T&>{
public:
  virtual bool invoke(const T& x){
    return (x % 2 == 0);
  }
};

//function for split
template<typename T>
class DivideThree: public Function<unsigned, const T&>{
public:
  virtual unsigned invoke(const T& x){
    return x % 3;
  }
};

//test for foldl
template<typename T>
class Sum: public Function<T, std::pair<const T&, const T&> >{
public:
  virtual T invoke(std::pair<const T&, const T&> p){
    return (p.first + p.second);
  }
};

template<typename T>
void printList(LinkedList<T> * ll){
  typename LinkedList<T> :: iterator it = ll->begin();
  while (it != NULL){
    std::cout << * it << ", ";
    ++it;
  }
  std::cout << "\n";
}


int main(void){
  LinkedList<int> *ll = new LinkedList<int>();
  ll->addBack(1);
  ll->addBack(2);
  ll->addBack(3);
  ll->addBack(4);
  ll->addBack(5);
  ll->addFront(6);
  ll->addFront(7);
  ll->addFront(8);
  ll->addFront(9);
  ll->addFront(10);
  std::cout << "The LinkedList ll is: ";
  printList(ll);
  
  //test for filter function
  DivideTwo<const int&> * d = new DivideTwo<const int&>();
  ll->filter(d);
  std::cout << "After filter, the LinkedList ll is now: ";
  printList(ll);

  //test for split function
  LinkedList<int> *ll2 = new LinkedList<int>();
  for (int i = 1; i < 6; i++){
    ll2->addBack(i);
  }
  for (int i = 6; i < 11; i++){
    ll2->addFront(i);
  }
  std::cout << "The LinkedList ll2 is: ";
  printList(ll2);
  DivideThree<const int&> *d2 = new DivideThree<const int&>();
  std::vector<LinkedList<int> > vec = ll2->split(d2);
  /*
  for (unsigned i = 0; i < vec.size(); i++){
    std::cout << "vec[ " << i << " ] is: ";
    printList(&vec[i]);
  }
  std::cout << "After split, the LinkedList ll2 is now: ";
  printList(ll2);
  */
  DivideThree<const int&> *f2 = new DivideThree<const int&>();
  std::vector<LinkedList<int> > sp = ll2->split(f2);
  for (unsigned i=0; i<sp.size(); i++) {
    std::cout << "sp["<<i<<"] is: ";
    printList(&sp[i]);
  }
  std::cout << "After split, ll2 is now: ";
  printList(ll2);

  // test foldl
  const int start = 0;
  Sum<int> *f3 = new Sum<int>();
  int ll2sum = ll2->foldl(f3, start);
  std::cout<<"After foldl, Sum of ll2 from fold l is "<<ll2sum<<"\n";
    
  delete ll;
  delete d;
  delete ll2;
  delete f2;
  delete f3;
  return EXIT_SUCCESS;
}

