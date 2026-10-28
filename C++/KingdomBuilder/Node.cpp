#include "Node.h"

Kingdom* Node::getKingdom() const{
  return kingdom;
}

Node* Node::getNext() const{
  return next;
}

void Node::setNext(Node* next){
  this->next=next;
}
