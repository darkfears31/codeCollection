#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include "students.h"
using namespace std;

int main(){
    // Dynamic array of type Students
    // array can hold 7 Students
    Students* arr=new Students[7];
    Students s1("luka", "abab", 15, 'm');
    Students s2("nina", "acac", 14, 'f');
    Students s3("vaja", "adad", 13, 'm');
    // Add students to Array
    arr[0]=s1;
    arr[1]=s2;
    arr[2]=s3;
    // Open file, where we will read info of students
    // And use that info to create new Students
    ifstream f("students.txt");
    for(int i=3;i<7;i++){
        // With help of operator overloading we can read info from file and create Students -- for implementation see students.cpp
        f>>arr[i];
    }
    // Close file
    f.close();
    // We can sort array with operator overloading  -- for implementation see students.cpp
    cout<<"Sorted: \n";
    // To sort dynamic array we have to give address of first object which is 'arr' and last object which is 'arr+7' (pointer arithmetics)
    // There is no other way for this.
    sort(arr, arr+7);
    // Count number of girls
    int number_Of_Girls{0};
    for(int i=0;i<7;i++){
        cout<<arr[i]<<endl;
        // getSex() is getter -- for implementation see students.cpp
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