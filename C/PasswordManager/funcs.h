#ifndef FUNCS_H
#define FUNCS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Maximum size of password is 8
#define PASS_SIZE 8


// Checks if password.txt exists
bool check_If_File_Exists(const char* filename);

// IF password.txt doesnt exist then user is using password manager for first time
// I ask them to think of some password which later on will be used.
void first_Time_Using(char* password);

// IF password.txt doesn't exist then we ask user to login, 
// they have 3 tries Maximum.
bool login(char* password);

// we don't know how big of string user wants to enter so I found this code online
// Which acts some kind of vector, bigger the input string becomes,
// bigger that char array becomes also.
// I found it here:
//     https://stackoverflow.com/questions/16870485/how-can-i-read-an-input-string-of-unknown-length
char* inputString(FILE* fp, size_t size);

// Converts Password in numbers, because
// later on password will be used as number for LFSR.
unsigned long long password_In_Number(char* password);

// Encrypts or Decrypts password.
void encrypt_decrypt(char* password, char* data, size_t len);

// opens encrypted.txt and reads from it.
// while decrypting each line.
void read_encrypted(char* pass);

// Opens encrypted.txt and writes encrypted text into it.
void write_encrypted(char* pass);

#endif
