#ifndef FUNCTIONS_H
#define FUNCTIONS_H

using namespace std;

//function to find the shift value based on a letter
int getShift(char letter);

//given a letter and a number to shift by, find the new resulting letter
char mapShift(char letter, int shift);
//do reverse (backwards shift)
char reverseShift(char letter, int shift);

//testing function
void testFunctions();

//vigenere functions
string vigenereEncrypt(string inputMessage, string key);
string vigenereDecrypt(string inputMessage, string key);
string filterKey(string key);

#endif // FUNCTIONS_H