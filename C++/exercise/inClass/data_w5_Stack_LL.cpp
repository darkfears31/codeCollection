#include <iostream>
using namespace std;


typedef int mytype;

class myStack{
  class Node{
  public:
    mytype data;
    Node* next;
    Node(mytype val, Node* n=nullptr){
      data =val;
      next=n;
    }
  };
  Node* top;
  int size;
public:
  myStack(){
    size=0;
    top=nullptr;
  }
  ~myStack(){
    while(!isEmpty()){
      pop();
    }
  }

  myStack(const myStack& other){
    this->size = other.size;
    this->top=nullptr;
    if(!other.isEmpty()){
      Node* otherIt=other.top->next, *newIt;
      newIt = top = new Node(other.top->data); 
      while(otherIt!=nullptr){
        newIt->next = new Node(otherIt->data);
        newIt = newIt->next;
        otherIt = otherIt->next;
      }
    }
  }

  myStack operator=(myStack& other){
    if(this != &other){
      this->~myStack();
      if(other.top==nullptr){
        top=nullptr;
      }
      Node* otherIt=other.top->next, *newIt;
      size=other.size;
      newIt = top = new Node(other.top->data); 
      while(otherIt!=nullptr){
        newIt->next = new Node(otherIt->data);
        newIt = newIt->next;
        otherIt = otherIt->next;
      }
    }
    return *this;
  }

  bool isEmpty() const{
    return top==nullptr;
  }

  void push(mytype item){
    top = new Node(item, top);
    size++;
 // If node constructor was without pointer 
    
 // Node* newNode = new Node(val);
 // newNode->next = top;
 // top = newNode;
  }

  void pop(){
    if(!isEmpty()){
      Node* tmp = top;
      top = top->next;
      delete tmp;
      size--;
    }
  }

  void display(ostream& o){
    Node* it = top;
    while(it!=nullptr){
      o<<it->data<<' ';
      it=it->next;
    }
    o<<endl;
  }

  mytype& operator[](int index){
    Node* tmp = top;
    for(int i=0;i<index;i++){
      tmp=tmp->next;
    }
    return tmp->data;
  }
};

ostream& operator<<(ostream& o, myStack& s){
  s.display(o);
  return o;
}


int main(){

  myStack s1;
  s1.push(5);
  s1.push(6);
  s1.push(2);
  s1.push(3);
  cout<<s1<<endl;
  myStack s2 =s1;
  s1.pop();
  cout<<s2<<s1<<endl;
  myStack s3;
  s3 = s2;
  cout<<s3<<endl;
  cout<<s3[0];

  return 0;
}
