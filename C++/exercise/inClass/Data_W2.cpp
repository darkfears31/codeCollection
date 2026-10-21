#include <iostream>
#include <fstream>

using namespace std;

// int** createArr(int size){
//   int** arr= new int*[size];
//   for(int i=0;i<size;i++){
//     arr[i]=new int[i+1];
//   }
//   return arr;
// }
// 
// int** pupulateArr(int** arr, int size){
//   for(int i=0;i<size;i++){
//     for(int j=0;j<i;j++){
//       arr[i][j]=i;
//     }
//   }
//   return arr;
// }
// 
// void display(int** arr, int size){
//   for(int i=0;i<size;i++){
//     for(int j=0;j<i;j++){
//       cout<<arr[i][j];
//     }
//     cout<<endl;
//   }
// }
// 
// void deleteArr(int** arr, int size){
//   for(int i=0;i<size;i++){
//     delete[] arr[i];
//   }
//   delete[] arr;
//   cout<<"deleted.";
// }
// 
// int main(){
// 
//   int size=20;
//   int** arr = createArr(size);
//   arr = pupulateArr(arr, size);
//   display(arr,size);
//   deleteArr(arr,size);
// 
//   return 0;
// }

class House{
private:
  double size;
  int floors;
  double price;
  bool isAvailable;
public:
  House(){
    cout<<"Default constructor called.\n";
  }
  House(double size, int floors, double price, bool isAvailable) {
    setSize(size);
    setFloors(floors);
    setPrice(price);
    isAvailable(isAvailable);
  } 
  ~House(){
    cout<<"Default destructor called.\n";
  }
  House(House& other){
    cout<<"Copy constructor was called.\n";
  }
  bool getAvailability(){
    return isAvailable;
  }
  double getSize(){
    return size;
  }
  int getFloors(){
    return floors;
  }
  double getPrice(){
    return price;
  }
  void setSize(double s){
    if(s>=0) size=s; 
  }
  void setFloors(int f){
    if(f>=0) floors=f; 
  }
  void setPrice(double p){
    if(p>=0) price=p; 
  }
  void isAvailable(bool a){
    isAvailable=a;
  }
  void display(ostream& out){
    out<<"Size: "<<size<<"\nPrice: "<<price<<"\nFloors: "<<floors<<(isAvailable? "\nYes":"\nNo")<<endl;
  }
  void read(istream* i){
    i>>size>>floors>>price>>isAvailable;
  }
};

ostream& operator<<(ostream& o, House& h){
  h.display(o);
  return o;
}
istream& operator>>(istream& i, House& h){
  h.read(i);
  return i;
}

int main(){
  House h1;
  House h2=h1;
  House h3;
  h3=h1;
  cout<<sizeof(h3)<<' '<<sizeof(h2)<<' '<<sizeof(h1)<<' ';
  ofstream o("harali.txt");
  o<<h1<<h2<<h3;
  return 0;
}
