#include <iostream>
#include <array>
using namespace std;

const int CAPACITY = 100;
typedef int mytype;
class myStatList{
  int siz=0;
  mytype mylist[CAPACITY];
public:
  myStatList() = default;
  bool is_empty(){
    return siz==0;
  }
  void push_back(mytype val){
    if(siz==CAPACITY) throw out_of_range("Oout of ragne.\n");
    mylist[siz]=val;
    siz++;
  }
  void insertAt(mytype val, int index){
    if(index<CAPACITY && index>=0 && index!=siz){
      for(int i=siz; i>index;i--){
        mylist[i] = mylist[i-1];
      }
      mylist[index]=val;
      siz++;
    }
    else{
      throw out_of_range("Out of range.\n");
    }
  }
  void pop(){
    if(!is_empty()){
      siz--;
    }
  }
  void deleteAt(int index){
    if(index<0 || index>=siz || is_empty()){
      throw out_of_range("Index is not valid.\n");
    }
    for(int i=index;i<siz;i++){
      mylist[i]=mylist[i+1];
    }
    siz--;
  }
  void display(ostream& o){
    for(int i=0;i<siz;i++){
      o<<mylist[i]<<' ';
    }
  }
  int search(mytype val){
    for(int i=0;i<CAPACITY;i++){
      if(mylist[i]==val) return i;
    }
    return -1;
  }
};


ostream& operator<<(ostream& o, myStatList& list){
  list.display(o);
  return o;
}

int main(){

  myStatList l1;
  l1.push_back(15);
  l1.push_back(25);
  l1.push_back(13);
  cout<<l1<<endl;
  l1.pop();
  cout<<l1<<endl;

  return 0;
}
