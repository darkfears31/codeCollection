#include <iostream>
using namespace std;
const int CAP=10;
class CircStatQueue{
private:
  int size;
  int top;
  int tail;
  int myCont[CAP];
public:
  CircStatQueue(){
    size=0;
    top=tail=-1;
  }
  bool isEmpty(){
    return size==0;
  }
  bool isFull(){
    return size==CAP;
  }
  void enqueu(int val){
    if(!isFull()){
      if(top==-1) (top++)%CAP;
      (tail++)%CAP;
      myCont[tail]=val;
      size++;
    }
  }
  void deque(){
    if(!isEmpty()){
      if(top==tail) top=tail=-1;
      else {(top++)%CAP;}
      size--;
    }
  }
  void display(ostream& o){
    for(int i=top; i!=tail; ((i++)%CAP)){
      cout<<myCont[i]<<' ';
      cout<<"Number: "<<i<<endl;
    }
    cout<<myCont[tail] <<" Tail: "<<tail<<endl;
  }

};

ostream& operator<<(ostream& o, CircStatQueue& c){
  c.display(o);
  return o;
}

int main(){
  
  CircStatQueue q;
  q.enqueu(10);
  q.enqueu(20);
  q.enqueu(30);
  q.enqueu(40);
  q.enqueu(90);
  q.enqueu(80);
  q.enqueu(70);
  q.enqueu(50);
  q.enqueu(62);
  q.enqueu(43);
  q.enqueu(64);
  cout<<q<<endl;
  q.deque();
  q.enqueu(64);
  cout<<q<<endl;
  CircStatQueue q2=q;
  cout<<q2<<endl;
  return 0;
}
