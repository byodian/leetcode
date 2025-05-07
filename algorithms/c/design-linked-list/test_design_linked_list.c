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

  MyLinkedList* list2 = myLinkedListCreate();
  myLinkedListAddAtTail(list2, 4);
  myLinkedListAddAtHead(list2, 3);
  printList(list2);
  printf("Value at index 1: %d\n", myLinkedListGet(list2, 1));
  printf("Value at index 2: %d\n", myLinkedListGet(list2, 2));

  return 0;
}