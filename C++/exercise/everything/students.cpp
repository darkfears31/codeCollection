#include <iostream>
#include <string>
#include "students.h"
using namespace std;

// Constructor
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
bool Students::operator>(Students& s){
    return this->age>s.age;
}
bool Students::operator<(Students& s){
    return this->age<s.age;
}
// Operator overloading from outside of class
ostream& operator<<(ostream& o, const Students& s){
    o<<"Name: "<<s.getName()<<"\nSurname: "<<s.getSurname()<<"\nAge: "<<s.getAge()<<"\nSex: "<<s.getSex()<<'\n';
    return o;
}

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