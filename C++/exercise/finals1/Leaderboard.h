#ifndef LEADERBOARD_H
#define LEADERBOARD_H

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <class T>
class Leaderboard{
private:
  vector<T> session;
public:
  void insert(const T& item){
    session.push_back(item);
  }
  int size() const{
    return session.size();
  }
  int find(const string& playerID){
    for(int i=0; i<session.size();i++){
      if(session[i]->getPlayerID() == playerID) return i;
    }
    return -1;
  }
  T& operator[](int index){
    if(index<0 || index>session.size()){
      throw out_of_range("Invalid Index.\n");
    }
    return session[index];
  }
  const T& operator[](int index) const {
    if(index<0 || index>=session.size()){
      throw out_of_range("Invalid Index.\n");
    }
    return session[index];
  }
  void removeAt(int index){
    if(index<0 || index>=session.size()){
      throw out_of_range("Invalid Index.\n");
    }
    delete session[index];
    session.erase(session.begin()+index);
  }
  bool contains(const T& item){
    for(int i=0;i<session.size();i++){
      if(*session[i]==*item) return true;
    }
    return false;
  }
  typename vector<T>::iterator begin() {return session.begin();}
  typename vector<T>::iterator end() {return session.end();}
};

template <class T>
void sort(Leaderboard<T>& board){
  sort(board.begin(), board.end(), [](const T& a, const T& b){return *a<*b;});
}





#endif
