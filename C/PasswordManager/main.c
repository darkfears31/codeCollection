// Encryption/Decryption using 64bit LFSR.
// nullptr didn't exist before C23,
// because I don't know what version user uses I decided to go with NULL instead of nullptr, for pointers.
// https://stackoverflow.com/questions/16870485/how-can-i-read-an-input-string-of-unknown-length
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcs.h"

int main(){
  char pass[PASS_SIZE + 1] = {0};
  // IF password.txt doesn't exist it means that user is using this password manager for first time.
  // So I ask them to create password
  // confirm the inputed password 
  // 
  // IF password.txt exists it means user already has password so 
  // I ask them to login
  // I encrypt user inputted password and if it matches one in password.txt I grant them access to whole files.
  if(!check_If_File_Exists("password.txt")){
      first_Time_Using(pass);
  } else {
      if(!login(pass)){
          printf("Exiting.\n");
          return 1;
      }
  }

  printf("What do you want to do?\n");
  printf("  1 - Read encrypted.txt\n");
  printf("  2 - Add to encrypted.txt\n");
  printf("Choice: ");

  int choice = 0;
  scanf("%d", &choice);
  // to remove that \n from user input
  getchar();

  switch(choice){
    case 1: 
      read_encrypted(pass);
      break;
    case 2:
      write_encrypted(pass);
      break;
    default:
      printf("Invalid choice.\n");
      break;
  }

  return 0;
}
