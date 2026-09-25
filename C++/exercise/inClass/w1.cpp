#include <iostream>
using namespace std;

int main(){

  int* x=new int[3];
  *x=1;
  *(x+1)=2;
  *(x+2)=3;
  for(int i=0;i<3;i++){
    cout<<"Address: "<<x+i<< " Number: "<<*(x+i)<<endl;
  }
  delete[] x;

  return 0;
}
