#include <iostream>
#include <fstream>

#include "additionalFuncsByMe.h"
funcs f;
using namespace std;

int main(){
    
    string key; // Will be used for vigenere encryption (key)
    if(!(f.passFileExists())){ // Checks if file containing hashed password exists
        string password;
        cout<<"Enter New Password: ";
        getline(cin, password);
        f.addPassToFile(password); // creates file in which hashed password is stored.
        key=password;
    }
    else{
        bool match;
        do{
            string passwordToMatch;
            cout<<"Enter Password To Continue: ";
            getline(cin, passwordToMatch);
            match = f.comparePass(passwordToMatch); // Compares entered string to hashed password
            if(match==false) cout<<"Incorrect"<<endl;
            else key=passwordToMatch;
        }while(match!=true);
    }
    //IF file that contains the passwords doesn't exist, it is created and stores passwords, if it exists, we decypher it with given key.
    if(!(f.fileContainingPasswordsExists())){
        f.addingPasswordsToFileForFirstTime(key);
    }
    else{
        char repeaterChoice;
        do{
            int choice = f.menu();
            switch(choice){
                case 1: 
                f.addingPasswordsToFile(key);
                repeaterChoice=f.repeaterChoice();
                break;
                case 2:
                f.showPasswords(key);
                repeaterChoice=f.repeaterChoice();
                break;
                case 3:
                f.removePasswordFromFile(key);
                repeaterChoice=f.repeaterChoice();
                break;
            }
        }while(repeaterChoice!='2');
    }
    return 0;
}



