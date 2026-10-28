#ifndef NODE_H
#define NODE_H
#include "kingdom.h"
class Kingdom;
class Node{
private:
  Node* next;
  Kingdom* kingdom;
public:
  // I like to keep Constructors and Destructors implementation here.
  Node(Kingdom* kingdom, Node* next=nullptr){
    this->kingdom=kingdom;
    this->next=next;
  }
  ~Node() {delete next;}
  Kingdom* getKingdom() const;
  Node* getNext() const;
  void setNext(Node* next);
};
#endif
