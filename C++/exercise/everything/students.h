#ifndef STUDENTS_H
#define STUDENTS_H

#include <iostream>
using namespace std;
class Students{
private:
    string name;
    string surname;
    int age;
    char sex;

public:
    // Default Constructor
    // constructor with an initializer list
    // If nothing is inputted while creating object Student they all will have defualt values given in constructor.
    // Ex:
    // Students s2("nina", "acac", 14, 'f');
    Students(string n="", string s="", unsigned int a=0, char sex=' '): 
        name(n), surname(s), age(a), sex(sex) {}
    // This can be used to create object Student while reading from file.
    Students(istream &);
    // Destructor, After object dies destructor is called.
    ~Students()=default;
    // Setters
    void setName(string);
    void setSurname(string);
    void setAge(int);
    void setSex(char);

    // Getters
    string getName() const;
    string getSurname() const;
    int getAge() const;
    char getSex() const;

    // Operator Overloading
    bool operator>(Students&);
    bool operator<(Students&);

};

// Operator overloading from outside of class
ostream& operator<<(ostream& o, const Students& s);
istream& operator>>(istream& i, Students& s);
#endif