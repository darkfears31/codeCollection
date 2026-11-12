#include <iostream>
using namespace std;

class CircStatQueue{
    int capacity;
    int size;
    int top; 
    int tail;
    int * myCont;
    
    public:
    //constructor
  CircStatQueue(int cap);
  bool isEmpty();
  bool isFull();
  void enqueue(int val);
  void deque();
  void resize();
  void display(ostream &);
};

  CircStatQueue::CircStatQueue(int cap){
      size = 0;
      top = tail = -1;
      capacity = cap;
      myCont = new int[capacity];
  }
  bool CircStatQueue::isEmpty(){
      return size == 0;
  }
  bool CircStatQueue::isFull(){
      return size == capacity;
  }
  void CircStatQueue::enqueue(int val){
          if(isEmpty()) top = 0;
          if(isFull()) resize();
          tail = (tail+1) % CAP;
          myCont[tail] = val;
          size++;
  }
  void CircStatQueue::resize(){
    capacity = 2*capacity;
    int * newCont = new int[capacity];
    for(int i =0, int j=topl i<size && j!=tail); i++, (j++)%capacity){
      newCont[i]=myCont[j];
    }
    delete myCont;
    myCont=newCont;
    top=0;
    tail=size-1;
  }
  void CircStatQueue::deque(){
    if(!isEmpty()){
        if(top==tail)  top = tail = -1; 
        else top = (top+1) % CAP;
        size--;
    }
  }
  void CircStatQueue::display(ostream & o){
    for(int  i = top ; i != tail; i = (i+1) % CAP){
        o << myCont[i]<< ' ';
    }
    cout << myCont[tail] << endl;
  }

ostream & operator<<(ostream & o, CircStatQueue & q){
  q.display(o);
  return o;
}


int main(){
  CircStatQueue q;
  q.enqueue(10);
  q.enqueue(1);
  q.enqueue(15);
  q.enqueue(25);
  cout<< q << endl;
  q.deque();
  cout << q << endl;
  CircStatQueue q2 = q;
  cout << q2 << endl;
  return 0;
}
