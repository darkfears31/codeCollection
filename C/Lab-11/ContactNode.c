#include "ContactNode.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void CreateContactNode(ContactNode* thisNode, char nameInit[], char phoneNumInit[], ContactNode* nextLoc){
  // Because everythig is char array, we need to use strcpy to copy every string into node.
  strcpy(thisNode->contactName, nameInit);
  strcpy(thisNode->contactPhoneNum, phoneNumInit);
  thisNode->nextNodePtr = nextLoc;
}


void InsertContactAfter(ContactNode* thisNode, ContactNode* newNode){
  ContactNode* tmpNext = thisNode->nextNodePtr;
  thisNode->nextNodePtr = newNode;
  newNode->nextNodePtr = tmpNext;
}


ContactNode* GetNextContact(ContactNode* thisNode){
  return thisNode->nextNodePtr;
}

void PrintContactNode(ContactNode* thisNode){
 printf("Name: %s\nPhone Number: %s\n", thisNode->contactName, thisNode->contactPhoneNum);
}
