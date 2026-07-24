#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "ContactNode.h"

int main(void) {
  char fullName[50] = "";
  char phoneNum[50] = "";
  char temp[50] = "";
  ContactNode* headContact = NULL;
  ContactNode* nextContact1 = NULL;
  ContactNode* nextContact2 = NULL;
  ContactNode* currContact = NULL;

  headContact = (ContactNode*)malloc(sizeof(ContactNode));
  nextContact1 = (ContactNode*)malloc(sizeof(ContactNode));
  nextContact2 = (ContactNode*)malloc(sizeof(ContactNode));

  // Filling each contact with user input.
  // Person 1
  printf("Person 1\n");
  printf("Enter Name:\n");
  fgets(fullName, 50, stdin);
  fullName[strlen(fullName)-1] = '\0';

  printf("Enter Phone Number:\n");
  fgets(phoneNum, 50, stdin);
  phoneNum[strlen(phoneNum)-1] = '\0';
  CreateContactNode(headContact, fullName, phoneNum, nextContact1); 
  PrintContactNode(headContact);

  // Person 2
  printf("Person 2\n");
  printf("Enter Name:\n");
  fgets(fullName, 50, stdin);
  fullName[strlen(fullName)-1] = '\0';

  printf("Enter Phone Number:\n");
  fgets(phoneNum, 50, stdin);
  phoneNum[strlen(phoneNum)-1] = '\0';
  CreateContactNode(nextContact1, fullName, phoneNum, nextContact2); 
  PrintContactNode(nextContact1);

  // Person 3
  printf("Person 3\n");
  printf("Enter Name:\n");
  fgets(fullName, 50, stdin);
  fullName[strlen(fullName)-1] = '\0';

  printf("Enter Phone Number:\n");
  fgets(phoneNum, 50, stdin);
  phoneNum[strlen(phoneNum)-1] = '\0';
  CreateContactNode(nextContact2, fullName, phoneNum, NULL); 
  PrintContactNode(nextContact2);

  // Going trough linked list and printing all the contacts.
  currContact = headContact;
  printf("CONTACT LIST\n");
  while (currContact != NULL) {
      printf("Name: %s\n", currContact->contactName);
      printf("Phone number: %s\n\n", currContact->contactPhoneNum);
      currContact = GetNextContact(currContact);
  }

  // Freeing allocated memory
  free(headContact);
  free(nextContact1);
  free(nextContact2);

   return 0;
}

