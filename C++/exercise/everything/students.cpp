#include <iostream>
#include <string>
#include "students.h"
using namespace std;

// Constructor
// Creates objects while reading from file.
Students::Students(istream& i){
    i>>name>>surname>>age>>sex;
}

// Setters
void Students::setName(string n){
    name=n;
}
void Students::setSurname(string s){
    surname=s;
}
void Students::setAge(int a){
    age=a;
}
void Students::setSex(char s){
    sex=s;
}

// Getters
string Students::getName() const{
    return name;
}
string Students::getSurname() const{
    return surname;
}
int Students::getAge() const{
    return age;
}
char Students::getSex() const {
    return sex;
}

// Operator overloading from Class
// because it is operator overloading from class it takes one object which is on the right of '>' operator
// obj > s
// because this operator overloading is defined inside class it always knows which object is on the left.
// and can use 'this->' pointer to take leftside object's age
// To learn what is 'this->' visit this link:
//      https://en.wikipedia.org/wiki/This_(computer_programming) 
// With help of this kind of operator overloading we can compare objects with their age
// and also use 'sort' algorithm to sort array.
bool Students::operator>(Students& s){
    return this->age>s.age;
}
bool Students::operator<(Students& s){
    return this->age<s.age;
}
// Operator overloading from outside of class
// Because this operator overloading is from outside of class it takes two arguments.
// This kind of operator overloading always needs 2 arguments, so often it is better to define from outside of class.
// This operator overloading will be used to 'cout' objects in terminal
// Can also be used to input them into files.
ostream& operator<<(ostream& o, const Students& s){
    o<<"Name: "<<s.getName()<<"\nSurname: "<<s.getSurname()<<"\nAge: "<<s.getAge()<<"\nSex: "<<s.getSex()<<'\n';
    return o;
}
// This operator overloading is used to create objects while reading from the file.
// it creates object, reads from file, uses setter functions and sets their values.
// in 'istream&' -- '&' is used for chaining.
// for example if it didnt have '&' we wouldn't be able to do such a thing: 
//      i>> obj_1 >> obj_2 >> obj_3;
istream& operator>>(istream& i, Students& s){
    string n;
    i>>n;
    s.setName(n);

    string sn;
    i>>sn;
    s.setSurname(sn);

    int a;
    i>>a;
    s.setAge(a);

    char sex;
    i>>sex;
    s.setSex(sex);

    return i;
}