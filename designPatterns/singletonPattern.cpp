// Singleton - one class only one object.
#include <iostream>
#include <string>
using namespace std;


class Person{
private:
  string name;
  unsigned short age;
  Person(string name, unsigned short age){
    this->name=name;
    this->age=age;
  }
public:
  static Person& getInstance(){
    static Person obj("Adam", 27);
    return obj;
  }
};

int main (int argc, char *argv[]) {
  Person& bob= Person::getInstance();
  Person& jack = Person::getInstance();
  cout<<&bob << ' '<< &jack<<endl;
  return 0;
}
