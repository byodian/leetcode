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
  myLinkedListAddAtHead(list2, 2);
  myLinkedListAddAtIndex(list2, 3, 5);
  printList(list2);
  printf("Value at index 1: %d\n", myLinkedListGet(list2, 1));
  printf("Value at index 2: %d\n", myLinkedListGet(list2, 2));

  MyLinkedList* list3 = myLinkedListCreate();
  myLinkedListAddAtIndex(list3, 0, 10);
  myLinkedListAddAtIndex(list3, 0, 20);
  myLinkedListAddAtIndex(list3, 1, 30);
  printf("%d\n", myLinkedListGet(list3, 0));

  MyLinkedList* list4 = myLinkedListCreate();
  myLinkedListAddAtHead(list4, 2);
  myLinkedListDeleteAtIndex(list4, 1);
  myLinkedListAddAtHead(list4, 2);
  myLinkedListAddAtHead(list4, 7);
  myLinkedListAddAtHead(list4, 3);
  myLinkedListAddAtHead(list4, 2);
  myLinkedListAddAtHead(list4, 5);
  myLinkedListAddAtTail(list4, 5);
  // 5-2-3-7-2-2-5
  printf("%d\n", myLinkedListGet(list4, 5));
  // 5-2-3-7-2-2
  myLinkedListDeleteAtIndex(list4, 6);
  // 5-2-3-7-2
  myLinkedListDeleteAtIndex(list4, 4);
  printList(list4);

  return 0;
}