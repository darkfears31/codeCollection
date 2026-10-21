#include <iostream>
#include <string>
#include <cmath>

using namespace std;

long long* enterInt(){
  //Biggest number that can be entered can be size of `long long`
  long long* number = new long long;
  cout<<"Enter number: ";
  while(!(cin>>*number)){
    cin.clear();
    cin.ignore(1000, '\n');
    cout<<"Invalid choice. Enter new number: ";
  }
  cin.ignore(1000, '\n');
  return number;
}

// Lazy [$_$] (as in - I don't want to write this for every function.)
bool* checkIfValid(long long* number, int* bitWeAreWorkingWith){
  bool* valid = new bool(false);
  if(*number < -(pow(2, *(bitWeAreWorkingWith)-1))) { cout<<"Not valid number.\n";return valid;} 
  if(*number > (pow(2, *(bitWeAreWorkingWith)-1))-1){ cout<<"Not valid number.\n";return valid;} 
  *valid=true;
  return valid;
}

string* integerToBinary(long long* number, int* bitWeAreWorkingWith){
  // In C course (Tinatin Davitashvili) I learned about bit manipulation, I'm going to use it.
  string* binary = new string;
  int* whichBit = new int(*bitWeAreWorkingWith-1);
  while(*whichBit>=0){
    // check if most significant bit is `0` or '1' and write it into string `binary`.
    if((*number)>>(*whichBit) & 1LL) *binary+='1';
    else {*binary+='0';}
    (*whichBit)--;
  }
  delete whichBit;
  return binary;
}

// Pretty self-explanatory
string* onesComplement(string* binary){
  string* result = new string;
  int* i= new int(0);
  for(*i=0;*i<(*binary).size();(*i)++){
    if((*binary)[*i] == '0') *result+='1';
    else {*result+='0';}
  }
  delete i;
  return result;
}

string* twosComplement(string* onesCompl){
  string* result = new string(*onesCompl);
  int* i= new int(int((*result).size())-1);
  bool* carry = new bool(true);
  for(;*i>=0 && *carry==true ;(*i)--){
    if((*result)[*i] == '1') (*result)[*i]='0';
    else {(*result)[*i]='1'; *carry=false;}
  }
  delete i;
  delete carry;
  return result;
}

/*
Basically every function works like this:
  alocate memory which holds which bit function is being used.
  alocates memory for checking, storing number and string which will hold number in binary.
  used do..while loop to wait for user to enter correct number, to be exact: valid number which sits between limits ( limits is being set by function )
  if number entered is correct do..while loop is brought to end
  then, number is converted to binary with bit manipulation and being displayed.
  converted binary number (in string) is then given to onesComplement function which returs ones complement and I display it.
  Ones complement (string) is given to twosComplement, converts it however needed and then it is displayed.
  at last every allocated memory is freed.
*/


// Min number = -8
// Max number = 7
void Bit4(){
  int* bitWeAreWorkingWith = new int(4);
  bool* validNumber = new bool(false);
  string* binary = new string;
  string* onesComplem = new string;
  string* twosComplem = new string;
  long long* num= new long long;
  do{
   long long* number = enterInt();
    bool* result = checkIfValid(number, bitWeAreWorkingWith);
    *validNumber = *result;
    delete result;
    if(*validNumber==true) *num=*number;
    delete number;
  }while(*validNumber==false);
  string* result1 = integerToBinary(num, bitWeAreWorkingWith);
  *binary = *result1;
  delete result1;
  string* result2 = onesComplement(binary);
  *onesComplem=*result2;
  delete result2;
  string* result3 = twosComplement(onesComplem);
  *twosComplem=*result3;
  delete result3;
  cout<<"Binary: "<<*binary<<endl;
  cout<<"Ones Complement: "<<*onesComplem<<endl;
  cout<<"Twos Complement: "<<*twosComplem<<endl;
  delete bitWeAreWorkingWith;
  delete onesComplem;
  delete twosComplem;
  delete binary;
  delete num;
  delete validNumber;
}
 
// Min number = -128
// Max number = 127
void Bit8(){
  int* bitWeAreWorkingWith = new int(8);
  bool* validNumber = new bool(false);
  string* binary = new string;
  string* onesComplem = new string;
  string* twosComplem = new string;
  long long* num= new long long;
  do{
   long long* number = enterInt();
    bool* result = checkIfValid(number, bitWeAreWorkingWith);
    *validNumber = *result;
    delete result;
    if(*validNumber==true) *num=*number;
    delete number;
  }while(*validNumber==false);
  string* result1 = integerToBinary(num, bitWeAreWorkingWith);
  *binary = *result1;
  delete result1;
  string* result2 = onesComplement(binary);
  *onesComplem=*result2;
  delete result2;
  string* result3 = twosComplement(onesComplem);
  *twosComplem=*result3;
  delete result3;
  cout<<"Binary: "<<*binary<<endl;
  cout<<"Ones Complement: "<<*onesComplem<<endl;
  cout<<"Twos Complement: "<<*twosComplem<<endl;
  delete bitWeAreWorkingWith;
  delete onesComplem;
  delete twosComplem;
  delete binary;
  delete num;
  delete validNumber;
}

// Min number = -32768
// Max number = 32767
void Bit16(){
  int* bitWeAreWorkingWith = new int(16);
  bool* validNumber = new bool(false);
  string* binary = new string;
  string* onesComplem = new string;
  string* twosComplem = new string;
  long long* num= new long long;
  do{
   long long* number = enterInt();
    bool* result = checkIfValid(number, bitWeAreWorkingWith);
    *validNumber = *result;
    delete result;
    if(*validNumber==true) *num=*number;
    delete number;
  }while(*validNumber==false);
  string* result1 = integerToBinary(num, bitWeAreWorkingWith);
  *binary = *result1;
  delete result1;
  string* result2 = onesComplement(binary);
  *onesComplem=*result2;
  delete result2;
  string* result3 = twosComplement(onesComplem);
  *twosComplem=*result3;
  delete result3;
  cout<<"Binary: "<<*binary<<endl;
  cout<<"Ones Complement: "<<*onesComplem<<endl;
  cout<<"Twos Complement: "<<*twosComplem<<endl;
  delete bitWeAreWorkingWith;
  delete onesComplem;
  delete twosComplem;
  delete binary;
  delete num;
  delete validNumber;
}

// Min number = -2147483648
// Max number = 2147483647
void Bit32(){
  int* bitWeAreWorkingWith = new int(32);
  bool* validNumber = new bool(false);
  string* binary = new string;
  string* onesComplem = new string;
  string* twosComplem = new string;
  long long* num= new long long;
  do{
   long long* number = enterInt();
    bool* result = checkIfValid(number, bitWeAreWorkingWith);
    *validNumber = *result;
    delete result;
    if(*validNumber==true) *num=*number;
    delete number;
  }while(*validNumber==false);
  string* result1 = integerToBinary(num, bitWeAreWorkingWith);
  *binary = *result1;
  delete result1;
  string* result2 = onesComplement(binary);
  *onesComplem=*result2;
  delete result2;
  string* result3 = twosComplement(onesComplem);
  *twosComplem=*result3;
  delete result3;
  cout<<"Binary: "<<*binary<<endl;
  cout<<"Ones Complement: "<<*onesComplem<<endl;
  cout<<"Twos Complement: "<<*twosComplem<<endl;
  delete bitWeAreWorkingWith;
  delete onesComplem;
  delete twosComplem;
  delete binary;
  delete num;
  delete validNumber;
}

// Min number = -9223372036854775808
// Max number = 9223372036854775807
void Bit64(){
  int* bitWeAreWorkingWith = new int(64);
  bool* validNumber = new bool(false);
  string* binary = new string;
  string* onesComplem = new string;
  string* twosComplem = new string;
  long long* num= new long long;
  do{
   long long* number = enterInt();
    bool* result = checkIfValid(number, bitWeAreWorkingWith);
    *validNumber = *result;
    delete result;
    if(*validNumber==true) *num=*number;
    delete number;
  }while(*validNumber==false);
  string* result1 = integerToBinary(num, bitWeAreWorkingWith);
  *binary = *result1;
  delete result1;
  string* result2 = onesComplement(binary);
  *onesComplem=*result2;
  delete result2;
  string* result3 = twosComplement(onesComplem);
  *twosComplem=*result3;
  delete result3;
  cout<<"Binary: "<<*binary<<endl;
  cout<<"Ones Complement: "<<*onesComplem<<endl;
  cout<<"Twos Complement: "<<*twosComplem<<endl;
  delete bitWeAreWorkingWith;
  delete onesComplem;
  delete twosComplem;
  delete binary;
  delete num;
  delete validNumber;
}

void yORn(char* choice){
  cout<<"Continue? (y/n) -> ";
  bool* enteredValid=new bool(false);
  do{
    cin>>*choice;
    *choice = (char)tolower(*choice);
    if(*choice != 'y' && *choice != 'n'){
      cout<<"Invalid expression, enter again: ";
    }
    else {*enteredValid=true;}
  }while(*enteredValid==false);
  delete enteredValid;
}

int main(){
  char* choice=new char;
  int* a=new int;
  do{
    cout<<"Choose which bit manipulation you want to use to display number (with number): \n";
    cout<<"1. 4 Bit\n";
    cout<<"2. 8 Bit\n";
    cout<<"3. 16 Bit\n";
    cout<<"4. 32 Bit\n";
    cout<<"5. 64 Bit\n";
    cin>>*a;
    switch (*a){
      case 1:
        Bit4();
        yORn(choice);
        break;
      case 2:
        Bit8();
        yORn(choice);
        break;
      case 3:
        Bit16();
        yORn(choice);
        break;
      case 4:
        Bit32();
        yORn(choice);
        break;
      case 5:
        Bit64();
        yORn(choice);
        break;
      default:
        cout<<"Invalid choice.\n";
        yORn(choice);
        break;
    }
  }while(*choice=='y');

  delete choice;
  delete a;
  return 0;
}
