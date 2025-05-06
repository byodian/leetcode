#ifndef DESIGN_LINKED_LIST
#define DESIGN_LINKED_LIST
typedef struct Node {
  int val;
  struct Node* next;
} Node;

typedef struct {
  Node* head;
} MyLinkedList;

Node* createNode(int val);
MyLinkedList* myLinkedListCreate();
int myLinkedListGet(MyLinkedList* obj, int index);
void myLinkedListAddAtHead(MyLinkedList* obj, int val);
void myLinkedListAddAtTail(MyLinkedList* obj, int val);
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val);
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index);
void myLinkedListFree(MyLinkedList* obj);

#endif