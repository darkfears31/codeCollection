//Append text to file.
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
 

int main(){
    
    ofstream file;
    string addText;
    file.open("example.txt", ios::app); //Opens the file in append mode, if there is no file it creates one.
    if(!file){
        cout<<"Error.";
        return 1;
    }
    cout<<"Enter text: "<<endl;
    getline(cin, addText);
    file<<addText<<endl;
    cout<<"Text added."<<endl;
    file.close();
    return 0;
}
