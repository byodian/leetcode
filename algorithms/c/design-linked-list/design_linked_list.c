/**
 * Title: Design Linked List
 * CreateTime: 2025-05-04
 * Difficulty: Medium
 * Likes: 2824
 * Dislikes: 1655
 * Topic Tags: Linked List, Design
 *
 * Problem description:
 * Design your implementation of the linked list. You can choose to use a singly or doubly linked list.
 * A node in a singly linked list should have two attributes: val and next. val is the value of the current node, and next is a pointer/reference to the next node.
 * If you want to use the doubly linked list, you will need one more attribute prev to indicate the previous node in the linked list. Assume all nodes in the linked list are 0-indexed.
 * Implement the MyLinkedList class:
 * 
 * MyLinkedList() Initializes the MyLinkedList object.
 * int get(int index) Get the value of the indexth node in the linked list. If the index is invalid, return -1.
 * void addAtHead(int val) Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
 * void addAtTail(int val) Append a node of value val as the last element of the linked list.
 * void addAtIndex(int index, int val) Add a node of value val before the indexth node in the linked list. If index equals the length of the linked list, the node will be appended to the end of the linked list. If index is greater than the length, the node will not be inserted.
 * void deleteAtIndex(int index) Delete the indexth node in the linked list, if the index is valid.
 * 
 *  
 * Example 1:
 * 
 * Input
 * ["MyLinkedList", "addAtHead", "addAtTail", "addAtIndex", "get", "deleteAtIndex", "get"]
 * [[], [1], [3], [1, 2], [1], [1], [1]]
 * Output
 * [null, null, null, null, 2, null, 3]
 * 
 * Explanation
 * MyLinkedList myLinkedList = new MyLinkedList();
 * myLinkedList.addAtHead(1);
 * myLinkedList.addAtTail(3);
 * myLinkedList.addAtIndex(1, 2);    // linked list becomes 1->2->3
 * myLinkedList.get(1);              // return 2
 * myLinkedList.deleteAtIndex(1);    // now the linked list is 1->3
 * myLinkedList.get(1);              // return 3
 * 
 *  
 * Constraints:
 * 
 * 0 <= index, val <= 1000
 * Please do not use the built-in LinkedList library.
 * At most 2000 calls will be made to get, addAtHead, addAtTail, addAtIndex and deleteAtIndex.
 * 
 *
 * Hints:

 */

#include <stdlib.h>
#include "design_linked_list.h"

// typedef struct Node {
//   int val;
//   struct Node* next; 
// } Node;

// typedef struct {
//   Node* head; 
// } MyLinkedList;

Node* createNode(int val) {
  Node* newnode = malloc(sizeof(Node));
  newnode->val = val;
  newnode->next = NULL;
  return newnode;
}

MyLinkedList* myLinkedListCreate() {
  MyLinkedList* obj = malloc(sizeof(MyLinkedList));
  obj->head = NULL;
  return obj;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
  if (!obj->head) {
    return -1;
  }

  if (index == 0) {
    if (obj->head) return obj->head->val;
    return -1;
  } else if (index > 0) {
    // for(int i = 1; i < index; i++) {
    //   if (current->next) {
    //     current = current->next;
    //   } else {
    //     return -1;
    //   }
    // }
    // if (current->next) {
    //   return current->next->val;
    // } else {
    //   return -1;
    // }
    int i = 1;
    Node* current = obj->head;
    while(current->next) {
      if (i == index) {
        return current->next->val;
      }
      i = i + 1;
      current = current->next;
    }
    return -1;
  } else {
    return -1;
  }
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
  if (!obj->head) {
    obj->head = createNode(val);
    return;
  }

  // head->oldnode->...
  // head->newnode->oldnode->...
  Node* tmp = obj->head;
  Node* newnode = createNode(val);
  obj->head = newnode;
  newnode->next = tmp;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
  if (!obj->head) {
    return myLinkedListAddAtHead(obj, val);
  }

  Node* current = obj->head;
  while(current->next) {
    current = current->next;
  }
  current->next = createNode(val);
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
  if (obj == NULL) {
    return;
  }
  Node* head = obj->head;
  Node* newnode = createNode(val);
  if (index == 0) {
    newnode->next = head;
    obj->head = newnode;
    return;
  }

  Node* current = head;
  int currentIndex = 1;
  while(current->next != NULL) {
    if (currentIndex == index) {
      newnode->next = current->next;
      current->next = newnode;
      return;
    }
    current = current->next;
    currentIndex = currentIndex + 1;
  }
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
  if (obj == NULL) {
    return;
  }

  Node* head = obj->head;
  if (index == 0) {
    obj->head = head->next;
    free(head);
    return;
  }

  Node* current = head;
  int currentIndex = 1;
  while(current->next != NULL) {
    Node* temp = current->next;
    if (currentIndex == index) {
      current->next = temp->next;
      free(temp);
      return;
    }
    current = current->next;
    currentIndex = currentIndex + 1;
  }
}

void myLinkedListFree(MyLinkedList* obj) {
  if (obj == NULL) {
    return;
  }

  Node* current = obj->head;
  while(current != NULL) {
    Node* tmp = current;
    current = current->next;
    free(tmp);
  }  
  free(obj);
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/