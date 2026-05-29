#include "node.h"
#include <stdio.h>
#include <string.h>


int compare_node( struct link_node *n1, struct link_node *n2 ){
  return strcmp(n1->node_str, n2->node_str);
}

struct link_node *add_node( struct link_node *list, struct link_node *node ){
  // Check if list is empty or node_str of node comes before head of the list,
  // if it does node becomes head of the list.
  if(list==NULL || compare_node(node, list)<0){
    node->next = list;
    return node;
  }
  struct link_node* current = list;
  // use while loop to go trough list to find where node_str of node 
  // should be.
  while(current->next != NULL && compare_node(node, current->next)>=0){
    current = current->next;
  }
  // When with help of while loop we find where node should be inserted 
  // we insert it in list.
  node->next = current->next;
  current->next=node;
  return list;
}

void display_list( struct link_node *head ){
  struct link_node* current = head;
  // until current node is nullpointer run while loop and print 
  // nodes, and change current node to next node.
  while(current!=NULL){
    printf("%s\n", current->node_str);
    current = current->next;
  }
}
