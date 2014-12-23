#include "node.h"

Node *  buildTree(uint64_t * counts) {
  //priority_queue_t
  //make a priority queue
  priority_queue_t * pq = new priority_queue_t();
  //For each character that appears in the input
  //its frequency is not 0---you have the frequencies passed in as an argument
  //you need to construct a new Node and add it to the priority queue. 
  for (unsigned i = 0; i < 257; i++){
  //Note that if you are on the ith charachter, you can do pq.push(new Node(i,freqs[i]));
    if (counts[i] > 0){
      Node * node = new Node(i, counts[i]);
      //pq.push(new Node(i, counts[i]));
      pq->push(node);
    }
  }
  //build the tree from the Nodes by removing the top two nodes,
  while (pq->size() > 1){
  //building a new Node out of them, and putting the new Node into the Priority Queue.
    Node * one = pq->top();
    pq->pop();//no return
    Node * two = pq->top();
    pq->pop();
    Node * root = new Node(one, two);
    pq->push(root);
  }
  Node * res = pq->top();
  pq->pop();
  delete pq;
  return res;
  //Methods you may find useful:
  //pq.size() //tells you how many items are in the PQ
  //   pq.top()   //returns the top item on the PQ (without removing it
  //pq.pop()   //removes the top item of the queue
  //pq.push(x)   //puts x into the queue
}  
