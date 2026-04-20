#include "class.h"
#include <iostream>
using namespace std;

box::box(int h, int w, int s, string n){
    setHeight(h);
    setWidth(w);
    setSize(s);
    name = n;
}

string box::getName() const{
    return name;
}
int box::volume() const{
    return height*width*size;
}

int box::getSize() const{
    return size;
}
int box::getWidth() const{
    return width;
}
int box::getHeight() const{
    return height;
}

void box::setSize(int s){
    size=s;
}
void box::setWidth(int w){
    width=w;
}
void box::setHeight(int h){
    height=h;
}

box& box::operator++(){ // prefix
    this->height++;
    this->width++;
    this->size++;
    return *this; //  reference return to create an lvalue.
}

box box::operator++(int){ // postfix
    box tmp = *this; // Hold current state of the object we are using for postfix increment.
    ++(*this); // Use prefix increment to increment the current object.
    return tmp;
}

ostream& operator<<(ostream& o, const box& b){
    o<<"Name: "<<b.getName()<<"\nHeight: "<<b.getHeight()<<"\nWidth: "<<b.getWidth()<<"\nSize: "<<b.getSize()<<"\nVolume: "<<b.volume()<<endl;
    return o; // Because of ostream& we can do chaining: cout<<a<<b<<c;
}

istream& operator>>(istream& i, box& b){
    i>>b.height;
    i>>b.width;
    i>>b.size;
    return i; // enables chaining.
}
