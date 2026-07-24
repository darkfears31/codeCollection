#ifndef CONTACTS_H
#define CONTACTS_H

typedef struct ContactNode_struct {
   char contactName[50];
   char contactPhoneNum[50];
   struct ContactNode_struct* nextNodePtr;
}ContactNode;

void CreateContactNode(ContactNode* thisNode, char nameInit[], char phoneNumInit[], ContactNode* nextLoc);
void InsertContactAfter(ContactNode* thisNode, ContactNode* newNode);
ContactNode* GetNextContact(ContactNode* thisNode);
void PrintContactNode(ContactNode* thisNode);

#endif
