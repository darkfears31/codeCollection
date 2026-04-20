#ifndef CLASS_H
#define CLASS_H
#include <iostream>
using namespace std;

class box{
private:
    int height;
    int width;
    int size;
    string name;
public:
    box(int h=1, int w=1, int s=1, string n="Box"); // Default Constructor
    // Getters
    string getName() const;
    int volume() const;
    int getSize() const;
    int getWidth() const;
    int getHeight() const;
    // Setters
    void setSize(int);
    void setWidth(int);
    void setHeight(int);

    friend istream& operator>>(istream& i, box& b);
    //Operator Overloading in Class
    box& operator++(); // prefix - Return reference to the modified object: *this.
    box operator++(int); // postfix - Save original state - Return original state: tmp.
};

ostream& operator<<(ostream& o, const box& b);
#endif