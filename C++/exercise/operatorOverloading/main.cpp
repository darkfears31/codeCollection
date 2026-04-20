#include <iostream>
#include "class.h"
using namespace std;

int main(){

    box b1(1,2,3, "b1");
    box b2(4,5,6, "b2");
    box b3; // Default Constructor
    cout<<b1<<endl<<b2<<endl<<b3<<endl; // Works
    b3 = b1++; // Postfix - b3 gets the original state of b1, then b1 is incremented.
    cout<<"b3=b1++:"<<endl<<b1<<endl<<b3<<endl; // Works
    box b4 = ++b2; // Prefix - b2 is incremented first, then b3 gets the modified state of b2.
    cout<<"b4=++b2:"<<endl<<b2<<endl<<b4<<endl; // Works
    return 0;
}