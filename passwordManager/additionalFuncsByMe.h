// additionalFuncsByMe.h
#ifndef ADDITIONALFUNCSBYME_H
#define ADDITIONALFUNCSBYME_H

#include <filesystem>
#include <iostream>
#include "sha1.h"
#include "functions.h"
namespace fs = std::filesystem;
SHA1 sha1;

class funcs {
public:
    bool passFileExists() {
        return fs::exists("hashedPassword.txt");
    }
    bool fileContainingPasswordsExists(){
        return fs::exists("fileContainingPasswords.txt");
    }
    void addPassToFile(string pass){
        ofstream file("hashedPassword.txt");
        if (!file){
            cout<<"Error."<<endl;
        }
        file<<sha1(pass)<<endl; //Pass encrypted password to file
        file.close();
    }
    bool comparePass(string pass){
        ifstream file("hashedPassword.txt");
        string hashedPass;
        getline(file, hashedPass);
        file.close();
        return sha1(pass)==hashedPass; //compares the password and if it is the same returns true, if not - false.
    }
    void addingPasswordsToFileForFirstTime(string key){
        cout<<"Now you are adding passwords to Password Manager. Make sure to include 1 password on each line."<<endl;
        cout<<"Press enter when you are done."<<endl;
        ofstream file("fileContainingPasswords.txt");
        string passwordsForPassManager;
        bool stop;
        do{
            getline(cin, passwordsForPassManager);
            if(passwordsForPassManager=="") stop=true;
            else{
                file<<vigenereEncrypt(passwordsForPassManager, key)<<endl;
            }
        }while(stop!=true);
        file.close();   
    }
    int menu(){
        int choice;
        cout<<"1. Add Password."<<endl;
        cout<<"2. Show Password."<<endl;
        cout<<"3. Remove Password."<<endl;
        cin>>choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout<<endl;
        return choice;
    }

    char repeaterChoice(){
        cout<<endl;
        char repeaterChoice;
        cout<<"Go back to Menu (1) or Quit the Program (2): ";
        cin>>repeaterChoice;
        cout<<endl;
        return repeaterChoice;

    }
    void addingPasswordsToFile(string key){
        cout<<"Press enter when you are done."<<endl;
        ofstream file("fileContainingPasswords.txt", ios::app);
        string passwordsForPassManager;
        bool stop;
        do{
            getline(cin, passwordsForPassManager);
            if(passwordsForPassManager=="") stop=true;
            else{
                file<<vigenereEncrypt(passwordsForPassManager, key)<<endl;
            }
        }while(stop!=true);
        file.close();
    }
    void showPasswords(string key){
        ifstream file("fileContainingPasswords.txt");
        string encryptedWords;
        while(getline(file, encryptedWords)){
            cout<<vigenereDecrypt(encryptedWords, key)<<endl;
        }
        file.close();
    } 
    void removePasswordFromFile(string key){
        ifstream file("fileContainingPasswords.txt");
        ofstream tmp("temp.txt");

        //Read Encrypted File
        string encryptedWords;
        while(getline(file, encryptedWords)){
            cout<<vigenereDecrypt(encryptedWords, key)<<endl;
        }

        cout << "Which Password Do You Want To Remove (Type Exactly)? ";
        string deletePass;
        cin >> deletePass;

        file.clear(); // Clear EOF flag
        file.seekg(0, ios::beg); // rewind file

        string line;
        while (getline(file,line))
        {
            if (vigenereDecrypt(line, key) != deletePass)
            {
                tmp << line << endl;
            }
        }
        tmp.close();
        file.close();
        remove("fileContainingPasswords.txt");
        rename("temp.txt","fileContainingPasswords.txt");
        cout <<endl<<endl<<endl;
    }   
};

#endif
