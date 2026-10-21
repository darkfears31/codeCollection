#include <iostream>
#include <array>
using namespace std;

typedef int mytype;
class myDynamicList{
  int size=0;
  int capacity;
  mytype* mylist;
public:
  myDynamicList(int cap=100){
    capacity=(cap>0? cap:1);
    size=0;
    mylist= new mytype[capacity];
  }
  myDynamicList(const myDynamicList& other){
    capacity=other.capacity;
    size=other.size;
    mylist = new mytype[capacity];
    for(int i=0;i<size;i++){
      mylist[i]=other.mylist[i];
    }
  }
  ~myDynamicList(){
    delete[] mylist;
  }
  bool is_empty(){
    return size==0;
  }
  void resize(){
    capacity*=2;
    mytype* templist=new mytype[capacity];
    for(int i=0;i<size;i++){
      templist[i]=mylist[i];
    }
    delete[] mylist;
    mylist = templist;
  }
  void push_back(mytype val){
    if(size==capacity) resize();
    mylist[size]=val;
    size++;
  }
  void insertAt(mytype val, int index){
    if(index<capacity && index>=0 && index!=size){
      for(int i=size; i>index;i--){
        mylist[i] = mylist[i-1];
      }
      mylist[index]=val;
      size++;
    }
    else{
      throw out_of_range("Out of range.\n");
    }
  }
  void pop(){
    if(!is_empty()){
      size--;
    }
  }
  void deleteAt(int index){
    if(index<0 || index>=size || is_empty()){
      throw out_of_range("Index is not valid.\n");
    }
    for(int i=index;i<size;i++){
      mylist[i]=mylist[i+1];
    }
    size--;
  }
  void display(ostream& o){
    for(int i=0;i<size;i++){
      o<<mylist[i]<<' ';
    }
  }
  int search(mytype val){
    for(int i=0;i<capacity;i++){
      if(mylist[i]==val) return i;
    }
    return -1;
  }
  myDynamicList operator=(myDynamicList& other){
    if(this!=&other){
      if(capacity < other.capacity){
        capacity=other.capacity;
        delete[] mylist;
        mylist = new mytype[capacity];
      }
      this->size=other.size;
      for(int i=0;i<size;i++){
        mylist[i]=other.mylist[i];
      }
    }
  }
  void shrinkToFit(){
    if(!is_empty()){
      capacity=size;
      mytype* templist = new mytype[capacity];
      for(int i=0;i<size;i++){
        templist[i]= mylist[i];
      }
      delete[] mylist;
      mylist = templist;
    }
  }
};


ostream& operator<<(ostream& o, myDynamicList& list){
  list.display(o);
  return o;
}

int main(){

  myDynamicList l1;
  l1.push_back(15);
  l1.push_back(25);
  l1.push_back(13);
  cout<<l1<<endl;
  l1.pop();
  cout<<l1<<endl;

  return 0;
}
