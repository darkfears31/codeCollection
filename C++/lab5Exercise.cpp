#include <iostream>
using namespace std;

int main(){
    int a,b,c,d,f,g, sum{0};
    do {
        do{a=rand();}
        while(a%5==0);//ensure a is not multiple of 5

        
        do{b=rand();}
        while(b%5==0);
        
        do{c=rand();}
        while(c%5==0);
        
        do{d=rand();}
        while(d%5==0);

        do{f=rand();}
        while(f%5==0);
        
        do{g=rand();}
        while(g%5==0);
        
        sum=a+b+c+d+f+g;
    }while (sum%19!=0);//ensure sum is multiple of 19    
    cout<<"The numbers are: "<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<f<<" "<<g<<endl;
    cout<<"The sum is: "<<sum<<endl;
    cout<<"Arithmetic mean is: "<<sum/6.0<<endl;
    return 0;

}