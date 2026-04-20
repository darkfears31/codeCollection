#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include "students.h"
using namespace std;

int main(){
    Students* arr=new Students[7];
    Students s1("luka", "abab", 15, 'm');
    Students s2("nina", "acac", 14, 'f');
    Students s3("vaja", "adad", 13, 'm');
    arr[0]=s1;
    arr[1]=s2;
    arr[2]=s3;
    ifstream f("students.txt");
    for(int i=3;i<7;i++){
        f>>arr[i];
    }
    f.close();
    int number_Of_Girls{0};
    cout<<"Sorted: \n";
    sort(arr, arr+7);
    for(int i=0;i<7;i++){
        cout<<arr[i]<<endl;
        if(arr[i].getSex()=='f') number_Of_Girls++;
    }
    cout<<"Number of Girls: "<<number_Of_Girls<<endl;
    cout<<"Oldest Student: \n"<<arr[6];
    for(int i=0;i<7;i++){
        if(arr[i].getSex()=='m'){
            cout<<"Youngest:\n"<<arr[i];
            break;
        }
    }
    delete[] arr;
    return 0;
}