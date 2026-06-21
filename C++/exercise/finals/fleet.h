#ifndef FLEET_H
#define FLEET_H

#include <vector>
#include <iostream>
#include <algorithm>
#include <stdexcept>
using namespace std;

template <class T>
class Fleet{
private:
  vector<T> ships;
public:
  void insert(const T& item){
    ships.push_back(item);
  }

  int size() const{
    return ships.size();
  }

  T& operator[](int index){
    if(index<0 || index>= ships.size()){
      throw out_of_range("Invalid Index.\n");
    }
    return ships[index];
  }

  const T& operator[](int index) const{
    if(index<0 || index>= ships.size()){
      throw out_of_range("Invalid Index.\n");
    }
    return ships[index];
  }
  typename vector<T>::iterator begin() { return ships.begin(); }
  typename vector<T>::iterator end()   { return ships.end(); }
};

template <class T>
void sortFleet(Fleet<T>& fleet){
  sort(fleet.begin(), fleet.end(), [](const T& a, const T& b){return *a<*b;});
}
#endif
