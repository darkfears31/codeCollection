#include <iostream>
using namespace std;


class LinkedQueue{
private:
  class Node{
  public:
    int data;
    Node* next;
    Node(int data){
      this->data=data;
      next=nullptr;
    }
  };
  Node* top;
  Node* tail;
  int size;
public:
  LinkedQueue(){
    top=tail=nullptr;
    size=0;
  }

  ~LinkedQueue(){
    while(top!=nullptr){
      Node* tmp=top;
      top=top->next;
      delete tmp;
      size--;
    }
  }

  LinkedQueue(const LinkedQueue& other){
    if(!other.isEmpty()){
      this->top=this->tail=new Node(other.top->data);
    }
    Node* otherIt = other.top->next;
    while(otherIt!=nullptr){
      tail = tail->next = new Node(otherIt->data);
    }
  }

  bool isEmpty() const {
    return size==0;
  }

  void enqueue(int val){
    if(isEmpty()) top=tail=new Node(val);
    else{tail=tail->next=new Node(val);}
    size++;
  }

  void deque(){
    if(!isEmpty()){
      if(top==tail) tail=nullptr;
      Node* tmp=top;
      top=top->next;
      delete tmp;
      size--;
    }
  }
  void display(ostream& o){
    Node* tmp=top;
    while(tmp!=nullptr){
      o<<"Data: "<<tmp->data<<'\n';
      tmp=tmp->next;
    }
  }
};
ostream& operator<<(ostream& o, LinkedQueue& q){
  q.display(o);
  return o;
}


int main(){
  LinkedQueue q;
  q.enqueue(10);
  q.enqueue(1);
  q.enqueue(15);
  q.enqueue(25);
  cout<< q << endl;
  q.deque();
  cout << q << endl;
 // LinkedQueue q2 = q;
  //cout << q2 << endl;
  return 0;
}
