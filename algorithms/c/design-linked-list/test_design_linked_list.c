#include <stdio.h>
#include <stdlib.h>
#include "design_linked_list.h"

void printList(MyLinkedList* obj) {
  Node* current = obj->head;
  while(current != NULL) {
    printf("%d-", current->val);
    current = current->next;
  }

  printf("\n");
}


int main() {
  MyLinkedList* list = myLinkedListCreate();
  myLinkedListAddAtHead(list, 1);
  myLinkedListAddAtHead(list, 2);
  myLinkedListAddAtHead(list, 3);
  myLinkedListAddAtTail(list, 4);
  printList(list);

  return 0;
}