#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"

int main(void){

  struct link_node* head = NULL;
  printf("Press Enter To Exit Typing.\n");
  printf("Enter Text:\n");
  while(true){
    struct link_node* newNode = malloc(sizeof(struct link_node));
    fgets(newNode->node_str, sizeof(newNode->node_str), stdin);
    // Remove Every New-Line from entered string
    newNode->node_str[strcspn(newNode->node_str, "\n")] = '\0';
    // If entered string size is zero, so it is empty,
    // end the while loop.
    if(strlen(newNode->node_str)==0) break;
    newNode->next = NULL; 
    head = add_node(head, newNode);
  }
  printf("Sorted List:\n");
  display_list(head);
  return 0;
}

